/*
 * s2dos05_powermeter.c
 *
 * Copyright (c) 2015 Samsung Electronics Co., Ltd
 *              http://www.samsung.com
 *
 *  This program is free software; you can redistribute  it and/or modify it
 *  under  the terms of  the GNU General  Public License as published by the
 *  Free Software Foundation;  either version 2 of the  License, or (at your
 *  option) any later version.
 *
 */

#include <linux/err.h>
#include <linux/slab.h>
#include <linux/regulator/s2dos05.h>
#include <linux/platform_device.h>
#include <linux/regulator/pmic_class.h>

#define CURRENT_METER		1
#define POWER_METER		2
#define RAWCURRENT_METER	3
#define SYNC_MODE		1
#define ASYNC_MODE		2

struct adc_info {
	struct i2c_client *i2c;
	u8 adc_mode;
	u8 adc_sync_mode;
	u16 *adc_val;
	u8 adc_ctrl1;
};

#ifdef CONFIG_DRV_SAMSUNG_PMIC
static const unsigned int current_coeffs[8] =
	{CURRENT_ELVDD, CURRENT_ELVSS, CURRENT_AVDD,
	 CURRENT_BUCK, CURRENT_L1, CURRENT_L2, CURRENT_L3, CURRENT_L4};

static const unsigned int power_coeffs[8] =
	{POWER_ELVDD, POWER_ELVSS, POWER_AVDD,
	 POWER_BUCK, POWER_L1, POWER_L2, POWER_L3, POWER_L4};

static void s2m_adc_read_data(struct device *dev, int channel)
{
	struct adc_info *adc_meter = dev_get_drvdata(dev);
	int i;
	u8 data_l, data_h, temp;

	/* ASYNCRD bit '1' --> 2ms delay --> read  in case of ADC Async mode */
	if (adc_meter->adc_sync_mode == ASYNC_MODE) {

		s2dos05_read_reg(adc_meter->i2c, S2DOS05_REG_PWRMT_CTRL1, &temp);
		if (!(temp & 0x40)) {
			if (adc_meter->adc_mode == CURRENT_METER) {
				if (channel < 0) {
					for (i = 0; i < 8; i++)
						adc_meter->adc_val[i] = 0;
				} else {
					adc_meter->adc_val[channel] = 0;
				}
			} else if (adc_meter->adc_mode == POWER_METER) {
				if (channel < 0) {
					for (i = 0; i < 8; i++)
						adc_meter->adc_val[i] = 0;
				} else {
					adc_meter->adc_val[channel] = 0;
				}
			} else {
				dev_err(dev, "%s: invalid adc mode(%d)\n",
					__func__, adc_meter->adc_mode);
			}
			return;
		}
		s2dos05_update_reg(adc_meter->i2c, S2DOS05_REG_PWRMT_CTRL1,
				   ADC_ASYNCRD_MASK, ADC_ASYNCRD_MASK);
		usleep_range(2000, 2100);
	}

	if (adc_meter->adc_mode == CURRENT_METER) {
		if (channel < 0) {
			for (i = 0; i < 8; i++) {
				s2dos05_update_reg(adc_meter->i2c,
						   S2DOS05_REG_PWRMT_CTRL2,
						   i, ADC_PTR_MASK);
				s2dos05_read_reg(adc_meter->i2c,
						 S2DOS05_REG_PWRMT_DATA, &data_l);
				adc_meter->adc_val[i] = data_l;
			}
		} else {
			s2dos05_update_reg(adc_meter->i2c,
					   S2DOS05_REG_PWRMT_CTRL2,
					   channel, ADC_PTR_MASK);
			s2dos05_read_reg(adc_meter->i2c,
					 S2DOS05_REG_PWRMT_DATA,
					 &data_l);
			adc_meter->adc_val[channel] = data_l;
		}
	} else if (adc_meter->adc_mode == POWER_METER) {
		if (channel < 0) {
			for (i = 0; i < 8; i++) {
				s2dos05_update_reg(adc_meter->i2c,
						   S2DOS05_REG_PWRMT_CTRL2,
						   2*i, ADC_PTR_MASK);
				s2dos05_read_reg(adc_meter->i2c,
						 S2DOS05_REG_PWRMT_DATA,
						 &data_l);

				s2dos05_update_reg(adc_meter->i2c,
						   S2DOS05_REG_PWRMT_CTRL2,
						   2*i+1, ADC_PTR_MASK);
				s2dos05_read_reg(adc_meter->i2c,
						 S2DOS05_REG_PWRMT_DATA,
						 &data_h);

				adc_meter->adc_val[i] = ((data_h & 0xff) << 8) |
							 (data_l & 0xff);
			}
		} else {
			s2dos05_update_reg(adc_meter->i2c,
					   S2DOS05_REG_PWRMT_CTRL2,
					   2 * channel, ADC_PTR_MASK);
			s2dos05_read_reg(adc_meter->i2c,
					 S2DOS05_REG_PWRMT_DATA, &data_l);

			s2dos05_update_reg(adc_meter->i2c,
					   S2DOS05_REG_PWRMT_CTRL2,
					   2 * channel + 1, ADC_PTR_MASK);
			s2dos05_read_reg(adc_meter->i2c,
					 S2DOS05_REG_PWRMT_DATA,
					 &data_h);

			adc_meter->adc_val[channel] = ((data_h & 0xff) << 8) |
							(data_l & 0xff);
		}
	} else {
		dev_err(dev, "%s: invalid adc mode(%d)\n",
			__func__, adc_meter->adc_mode);
	}
}

static unsigned int get_coeff(struct device *dev, u8 adc_reg_num)
{
	struct adc_info *adc_meter = dev_get_drvdata(dev);
	unsigned int coeff;

	if (adc_meter->adc_mode == CURRENT_METER) {
		if (adc_reg_num <= 7)
			coeff = current_coeffs[adc_reg_num];
		else {
			dev_err(dev, "%s: invalid adc regulator number(%d)\n",
				__func__, adc_reg_num);
			coeff = 0;
		}
	} else if (adc_meter->adc_mode == POWER_METER) {
		if (adc_reg_num <= 7)
			coeff = power_coeffs[adc_reg_num];
		else {
			dev_err(dev, "%s: invalid adc regulator number(%d)\n",
				__func__, adc_reg_num);
			coeff = 0;
		}
	} else {
		dev_err(dev, "%s: invalid adc mode(%d)\n",
			__func__, adc_meter->adc_mode);
		coeff = 0;
	}
	return coeff;
}

static ssize_t adc_val_all_show(struct device *dev,
				struct device_attribute *attr, char *buf)
{
	struct adc_info *adc_meter = dev_get_drvdata(dev);

	s2m_adc_read_data(dev, -1);
	if (adc_meter->adc_mode == POWER_METER) {
		return snprintf(buf, PAGE_SIZE,
			"CH0:%d uW (%d), CH1:%d uW (%d), CH2:%d uW (%d), CH3:%d uW (%d)\n"
			"CH4:%d uW (%d), CH5:%d uW (%d), CH6:%d uW (%d), CH7:%d uW (%d)\n",
			(adc_meter->adc_val[0] * get_coeff(dev, 0))/100, adc_meter->adc_val[0],
			(adc_meter->adc_val[1] * get_coeff(dev, 1))/100, adc_meter->adc_val[1],
			(adc_meter->adc_val[2] * get_coeff(dev, 2))/100, adc_meter->adc_val[2],
			(adc_meter->adc_val[3] * get_coeff(dev, 3))/100, adc_meter->adc_val[3],
			(adc_meter->adc_val[4] * get_coeff(dev, 4))/100, adc_meter->adc_val[4],
			(adc_meter->adc_val[5] * get_coeff(dev, 5))/100, adc_meter->adc_val[5],
			(adc_meter->adc_val[6] * get_coeff(dev, 6))/100, adc_meter->adc_val[6],
			(adc_meter->adc_val[7] * get_coeff(dev, 7))/100, adc_meter->adc_val[7]);
	} else {
		return snprintf(buf, PAGE_SIZE,
			"CH0:%d uA (%d), CH1:%d uA (%d), CH2:%d uA (%d), CH3:%d uA (%d)\n"
			"CH4:%d uA (%d), CH5:%d uA (%d), CH6:%d uA (%d), CH7:%d uA (%d)\n",
			adc_meter->adc_val[0] * get_coeff(dev, 0), adc_meter->adc_val[0],
			adc_meter->adc_val[1] * get_coeff(dev, 1), adc_meter->adc_val[1],
			adc_meter->adc_val[2] * get_coeff(dev, 2), adc_meter->adc_val[2],
			adc_meter->adc_val[3] * get_coeff(dev, 3), adc_meter->adc_val[3],
			adc_meter->adc_val[4] * get_coeff(dev, 4), adc_meter->adc_val[4],
			adc_meter->adc_val[5] * get_coeff(dev, 5), adc_meter->adc_val[5],
			adc_meter->adc_val[6] * get_coeff(dev, 6), adc_meter->adc_val[6],
			adc_meter->adc_val[7] * get_coeff(dev, 7), adc_meter->adc_val[7]);
	}
}

static ssize_t adc_en_show(struct device *dev,
			   struct device_attribute *attr, char *buf)
{
	struct adc_info *adc_meter = dev_get_drvdata(dev);
	u8 adc_ctrl3;

	s2dos05_read_reg(adc_meter->i2c, S2DOS05_REG_PWRMT_CTRL2, &adc_ctrl3);
	if ((adc_ctrl3 & 0x80) == 0x80)
		return snprintf(buf, PAGE_SIZE, "ADC enable (%x)\n", adc_ctrl3);
	else
		return snprintf(buf, PAGE_SIZE, "ADC disable (%x)\n", adc_ctrl3);
}

static ssize_t adc_en_store(struct device *dev, struct device_attribute *attr,
			    const char *buf, size_t count)
{
	struct adc_info *adc_meter = dev_get_drvdata(dev);
	int ret;
	u8 temp, val;

	ret = kstrtou8(buf, 16, &temp);
	if (ret)
		return -EINVAL;

	switch (temp) {
	case 0:
		val = 0x00;
		break;
	case 1:
		val = 0x80;
		break;
	default:
		val = 0x00;
		break;
	}

	s2dos05_update_reg(adc_meter->i2c, S2DOS05_REG_PWRMT_CTRL2,
			   val, ADC_EN_MASK);
	return count;
}

static ssize_t adc_mode_show(struct device *dev,
			     struct device_attribute *attr, char *buf)
{
	struct adc_info *adc_meter = dev_get_drvdata(dev);
	u8 adc_ctrl3;

	s2dos05_read_reg(adc_meter->i2c, S2DOS05_REG_PWRMT_CTRL2, &adc_ctrl3);

	adc_ctrl3 = adc_ctrl3 & 0x30;
	switch (adc_ctrl3) {
	case CURRENT_MODE:
		return snprintf(buf, PAGE_SIZE, "CURRENT MODE (%d)\n", CURRENT_METER);
	case POWER_MODE:
		return snprintf(buf, PAGE_SIZE, "POWER MODE (%d)\n", POWER_METER);
	default:
		return snprintf(buf, PAGE_SIZE, "error (%x)\n", adc_ctrl3);
	}
}

static ssize_t adc_mode_store(struct device *dev, struct device_attribute *attr,
				const char *buf, size_t count)
{
	struct adc_info *adc_meter = dev_get_drvdata(dev);
	int ret;
	u8 temp, val;

	ret = kstrtou8(buf, 16, &temp);
	if (ret)
		return -EINVAL;

	switch (temp) {
	case CURRENT_METER:
		adc_meter->adc_mode = 1;
		val = CURRENT_MODE;
		break;
	case POWER_METER:
		adc_meter->adc_mode = 2;
		val = POWER_MODE;
		break;
	default:
		val = CURRENT_MODE;
		break;
	}
	s2dos05_update_reg(adc_meter->i2c, S2DOS05_REG_PWRMT_CTRL2,
			(ADC_EN_MASK | val), (ADC_EN_MASK | ADC_PGEN_MASK));
	return count;

}

static ssize_t adc_sync_mode_show(struct device *dev,
				  struct device_attribute *attr, char *buf)
{
	struct adc_info *adc_meter = dev_get_drvdata(dev);

	switch (adc_meter->adc_sync_mode) {
	case SYNC_MODE:
		return snprintf(buf, PAGE_SIZE,
				"SYNC_MODE (%d)\n", adc_meter->adc_sync_mode);
	case ASYNC_MODE:
		return snprintf(buf, PAGE_SIZE,
				"ASYNC_MODE (%d)\n", adc_meter->adc_sync_mode);
	default:
		return snprintf(buf, PAGE_SIZE,
				"error (%d)\n", adc_meter->adc_sync_mode);
	}
}

static ssize_t adc_sync_mode_store(struct device *dev, struct device_attribute *attr,
				   const char *buf, size_t count)
{
	struct adc_info *adc_meter = dev_get_drvdata(dev);
	int ret;
	u8 temp;

	ret = kstrtou8(buf, 16, &temp);
	if (ret)
		return -EINVAL;

	switch (temp) {
	case SYNC_MODE:
		adc_meter->adc_sync_mode = 1;
		break;
	case ASYNC_MODE:
		adc_meter->adc_sync_mode = 2;
		break;
	default:
		adc_meter->adc_sync_mode = 1;
		break;
	}

	return count;

}

static int convert_adc_val(struct device *dev, char *buf, int channel)
{
	struct adc_info *adc_meter = dev_get_drvdata(dev);

	s2m_adc_read_data(dev, channel);

	if (adc_meter->adc_mode == POWER_METER)
		return snprintf(buf, PAGE_SIZE, "%d uW\n",
				(adc_meter->adc_val[channel] * get_coeff(dev, channel)) / 100);
	else
		return snprintf(buf, PAGE_SIZE, "%d uA\n",
				adc_meter->adc_val[channel] * get_coeff(dev, channel));

}

static ssize_t adc_val_0_show(struct device *dev,
			      struct device_attribute *attr, char *buf)
{
	return convert_adc_val(dev, buf, 0);
}

static ssize_t adc_val_1_show(struct device *dev,
			      struct device_attribute *attr, char *buf)
{
	return convert_adc_val(dev, buf, 1);
}

static ssize_t adc_val_2_show(struct device *dev,
			      struct device_attribute *attr, char *buf)
{
	return convert_adc_val(dev, buf, 2);
}

static ssize_t adc_val_3_show(struct device *dev,
			      struct device_attribute *attr, char *buf)
{
	return convert_adc_val(dev, buf, 3);
}

static ssize_t adc_val_4_show(struct device *dev,
			      struct device_attribute *attr, char *buf)
{
	return convert_adc_val(dev, buf, 4);
}

static ssize_t adc_val_5_show(struct device *dev,
			      struct device_attribute *attr, char *buf)
{
	return convert_adc_val(dev, buf, 5);
}

static ssize_t adc_val_6_show(struct device *dev,
			      struct device_attribute *attr, char *buf)
{
	return convert_adc_val(dev, buf, 6);
}

static ssize_t adc_val_7_show(struct device *dev,
			      struct device_attribute *attr, char *buf)
{
	return convert_adc_val(dev, buf, 7);
}

static void adc_ctrl1_update(struct device *dev)
{
	struct adc_info *adc_meter = dev_get_drvdata(dev);
	/* ADC temporarily off */
	s2dos05_update_reg(adc_meter->i2c,
			   S2DOS05_REG_PWRMT_CTRL2, 0x00, ADC_EN_MASK);

	/* update ADC_CTRL1 register */
	s2dos05_write_reg(adc_meter->i2c,
			  S2DOS05_REG_PWRMT_CTRL1, adc_meter->adc_ctrl1);

	/* ADC Continuous ON */
	s2dos05_update_reg(adc_meter->i2c,
			   S2DOS05_REG_PWRMT_CTRL2, ADC_EN_MASK, ADC_EN_MASK);
}

static ssize_t adc_ctrl1_show(struct device *dev,
			      struct device_attribute *attr, char *buf)
{
	struct adc_info *adc_meter = dev_get_drvdata(dev);
	return snprintf(buf, PAGE_SIZE, "0x%2x\n", adc_meter->adc_ctrl1);
}

static ssize_t adc_ctrl1_store(struct device *dev, struct device_attribute *attr,
				const char *buf, size_t count)
{
	struct adc_info *adc_meter = dev_get_drvdata(dev);
	int ret;
	u8 temp;

	ret = kstrtou8(buf, 16, &temp);
	if (ret)
		return -EINVAL;

	temp &= 0x0f;
	adc_meter->adc_ctrl1 &= 0xf0;
	adc_meter->adc_ctrl1 |= temp;
	adc_ctrl1_update(dev);
	return count;
}

static DEVICE_ATTR(adc_val_all, 0444, adc_val_all_show, NULL);
static DEVICE_ATTR(adc_en, 0644, adc_en_show, adc_en_store);
static DEVICE_ATTR(adc_mode, 0644, adc_mode_show, adc_mode_store);
static DEVICE_ATTR(adc_sync_mode, 0644, adc_sync_mode_show, adc_sync_mode_store);
static DEVICE_ATTR(adc_val_0, 0444, adc_val_0_show, NULL);
static DEVICE_ATTR(adc_val_1, 0444, adc_val_1_show, NULL);
static DEVICE_ATTR(adc_val_2, 0444, adc_val_2_show, NULL);
static DEVICE_ATTR(adc_val_3, 0444, adc_val_3_show, NULL);
static DEVICE_ATTR(adc_val_4, 0444, adc_val_4_show, NULL);
static DEVICE_ATTR(adc_val_5, 0444, adc_val_5_show, NULL);
static DEVICE_ATTR(adc_val_6, 0444, adc_val_6_show, NULL);
static DEVICE_ATTR(adc_val_7, 0444, adc_val_7_show, NULL);
static DEVICE_ATTR(adc_ctrl1, 0644, adc_ctrl1_show, adc_ctrl1_store);

int create_s2dos05_powermeter_sysfs(struct s2dos05_dev *s2dos05)
{
	struct device *s2dos05_adc_dev;
	struct device *dev = s2dos05->dev;
	char device_name[32] = {0, };
	int err = -ENODEV;

	pr_info("%s: display pmic powermeter sysfs start\n", __func__);

	/* Dynamic allocation for device name */
	snprintf(device_name, sizeof(device_name) - 1, "s2dos05-powermeter@%s",
		 dev_name(dev));

	s2dos05_adc_dev = pmic_device_create(s2dos05->adc_meter, device_name);
	s2dos05->powermeter_dev = s2dos05_adc_dev;

	/* create sysfs entries */
	err = device_create_file(s2dos05_adc_dev, &dev_attr_adc_en);
	if (err)
		goto remove_pmic_device;
	err = device_create_file(s2dos05_adc_dev, &dev_attr_adc_mode);
	if (err)
		goto remove_adc_en;
	err = device_create_file(s2dos05_adc_dev, &dev_attr_adc_sync_mode);
	if (err)
		goto remove_adc_mode;
	err = device_create_file(s2dos05_adc_dev, &dev_attr_adc_val_all);
	if (err)
		goto remove_adc_sync_mode;
	err = device_create_file(s2dos05_adc_dev, &dev_attr_adc_val_0);
	if (err)
		goto remove_adc_val_all;
	err = device_create_file(s2dos05_adc_dev, &dev_attr_adc_val_1);
	if (err)
		goto remove_adc_val_0;
	err = device_create_file(s2dos05_adc_dev, &dev_attr_adc_val_2);
	if (err)
		goto remove_adc_val_1;
	err = device_create_file(s2dos05_adc_dev, &dev_attr_adc_val_3);
	if (err)
		goto remove_adc_val_2;
	err = device_create_file(s2dos05_adc_dev, &dev_attr_adc_val_4);
	if (err)
		goto remove_adc_val_3;
	err = device_create_file(s2dos05_adc_dev, &dev_attr_adc_val_5);
	if (err)
		goto remove_adc_val_4;
	err = device_create_file(s2dos05_adc_dev, &dev_attr_adc_val_6);
	if (err)
		goto remove_adc_val_5;
	err = device_create_file(s2dos05_adc_dev, &dev_attr_adc_val_7);
	if (err)
		goto remove_adc_val_6;
	err = device_create_file(s2dos05_adc_dev, &dev_attr_adc_ctrl1);
	if (err)
		goto remove_adc_val_7;

	return 0;

remove_adc_val_7:
	device_remove_file(s2dos05_adc_dev, &dev_attr_adc_val_7);
remove_adc_val_6:
	device_remove_file(s2dos05_adc_dev, &dev_attr_adc_val_6);
remove_adc_val_5:
	device_remove_file(s2dos05_adc_dev, &dev_attr_adc_val_5);
remove_adc_val_4:
	device_remove_file(s2dos05_adc_dev, &dev_attr_adc_val_4);
remove_adc_val_3:
	device_remove_file(s2dos05_adc_dev, &dev_attr_adc_val_3);
remove_adc_val_2:
	device_remove_file(s2dos05_adc_dev, &dev_attr_adc_val_2);
remove_adc_val_1:
	device_remove_file(s2dos05_adc_dev, &dev_attr_adc_val_1);
remove_adc_val_0:
	device_remove_file(s2dos05_adc_dev, &dev_attr_adc_val_0);
remove_adc_val_all:
	device_remove_file(s2dos05_adc_dev, &dev_attr_adc_val_all);
remove_adc_sync_mode:
	device_remove_file(s2dos05_adc_dev, &dev_attr_adc_sync_mode);
remove_adc_mode:
	device_remove_file(s2dos05_adc_dev, &dev_attr_adc_mode);
remove_adc_en:
	device_remove_file(s2dos05_adc_dev, &dev_attr_adc_en);
remove_pmic_device:
	pmic_device_destroy(s2dos05->dev->devt);

	return 1;
}
#endif
void s2dos05_powermeter_init(struct s2dos05_dev *s2dos05)
{
#ifdef CONFIG_DRV_SAMSUNG_PMIC
	int ret;
#endif
	struct adc_info *adc_meter;

	adc_meter = devm_kzalloc(s2dos05->dev,
				 sizeof(struct adc_info), GFP_KERNEL);
	if (!adc_meter) {
		pr_err("%s: adc_meter alloc fail.\n", __func__);
		return;
	}

	adc_meter->adc_val = devm_kzalloc(s2dos05->dev,
					  sizeof(u16) * S2DOS05_MAX_ADC_CHANNEL,
					  GFP_KERNEL);

	pr_info("%s: s2dos05 power meter init start\n", __func__);

	/* adc_reg[] : ELVDD, ELVSS, AVDD, BUCK, LDO1. LDO2, LDO3, LDO4 */

	adc_meter->adc_mode = s2dos05->adc_mode;
	adc_meter->adc_sync_mode = s2dos05->adc_sync_mode;

	/* POWER_METER mode needs bigger SMP_NUM to get stable value */
	switch (adc_meter->adc_mode) {
	case CURRENT_METER:
		adc_meter->adc_ctrl1 = 0x0C;
		break;
	case POWER_METER:
		adc_meter->adc_ctrl1 = 0x0C;
		break;
	default:
		adc_meter->adc_ctrl1 = 0x0C;
		break;
	}

	/*  SMP_NUM = 1100(16384) ~16s in case of aync mode */
	if (adc_meter->adc_sync_mode == ASYNC_MODE)
		adc_meter->adc_ctrl1 = 0x0C;

	s2dos05_write_reg(s2dos05->i2c,
			  S2DOS05_REG_PWRMT_CTRL1, adc_meter->adc_ctrl1);

	/* IRQM unmask */
	/* s2dos05_update_reg(s2dos05->i2c, S2DOS05_REG_IRQ_MASK, 0x00); */

	/* ADC EN */
	switch (adc_meter->adc_mode) {
	case CURRENT_METER:
		s2dos05_update_reg(s2dos05->i2c, S2DOS05_REG_PWRMT_CTRL2,
				   (ADC_EN_MASK | CURRENT_MODE),
				   (ADC_EN_MASK | ADC_PGEN_MASK));
		pr_info("%s: current mode enable (0x%2x)\n",
			__func__, (ADC_EN_MASK | CURRENT_MODE));
		break;
	case POWER_METER:
		s2dos05_update_reg(s2dos05->i2c, S2DOS05_REG_PWRMT_CTRL2,
				   (ADC_EN_MASK | POWER_MODE),
				   (ADC_EN_MASK | ADC_PGEN_MASK));
		pr_info("%s: power mode enable (0x%2x)\n",
			__func__, (ADC_EN_MASK | POWER_MODE));
		break;
	default:
		s2dos05_update_reg(s2dos05->i2c, S2DOS05_REG_PWRMT_CTRL2,
				   (0x00 | CURRENT_MODE),
				   (ADC_EN_MASK | ADC_PGEN_MASK));
		pr_info("%s: current/power meter disable (0x%2x)\n",
			__func__, (ADC_EN_MASK | CURRENT_MODE));

	}

	adc_meter->i2c = s2dos05->i2c;
	s2dos05->adc_meter = adc_meter;

	/* create sysfs entries */
#ifdef CONFIG_DRV_SAMSUNG_PMIC
	ret = create_s2dos05_powermeter_sysfs(s2dos05);
	if (ret) {
		pr_info("%s: failed to create sysfs\n");

		return;
	}
#endif
	pr_info("%s: s2dos05 power meter init end\n", __func__);
}

void s2dos05_powermeter_deinit(struct s2dos05_dev *s2dos05)
{
#ifdef CONFIG_DRV_SAMSUNG_PMIC
	struct device *s2dos05_adc_dev = s2dos05->powermeter_dev;
	/* remove sysfs entries */
	device_remove_file(s2dos05_adc_dev, &dev_attr_adc_en);
	device_remove_file(s2dos05_adc_dev, &dev_attr_adc_val_all);
	device_remove_file(s2dos05_adc_dev, &dev_attr_adc_mode);
	device_remove_file(s2dos05_adc_dev, &dev_attr_adc_sync_mode);
	device_remove_file(s2dos05_adc_dev, &dev_attr_adc_val_0);
	device_remove_file(s2dos05_adc_dev, &dev_attr_adc_val_1);
	device_remove_file(s2dos05_adc_dev, &dev_attr_adc_val_2);
	device_remove_file(s2dos05_adc_dev, &dev_attr_adc_val_3);
	device_remove_file(s2dos05_adc_dev, &dev_attr_adc_val_4);
	device_remove_file(s2dos05_adc_dev, &dev_attr_adc_val_5);
	device_remove_file(s2dos05_adc_dev, &dev_attr_adc_val_6);
	device_remove_file(s2dos05_adc_dev, &dev_attr_adc_val_7);
	device_remove_file(s2dos05_adc_dev, &dev_attr_adc_ctrl1);
	pmic_device_destroy(s2dos05->dev->devt);
#endif

	/* ADC turned off */
	s2dos05_write_reg(s2dos05->i2c, S2DOS05_REG_PWRMT_CTRL2, 0);
	pr_info("%s: s2dos05 power meter deinit\n", __func__);
}
