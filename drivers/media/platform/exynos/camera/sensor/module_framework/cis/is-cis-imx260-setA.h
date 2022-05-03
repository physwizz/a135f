/*
 * Samsung Exynos5 SoC series Sensor driver
 *
 *
 * Copyright (c) 2011 Samsung Electronics Co., Ltd
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#ifndef IS_CIS_IMX260_SET_A_H
#define IS_CIS_IMX260_SET_A_H

#include "is-cis.h"
#include "is-cis-imx260.h"

const u32 sensor_imx260_setfile_A_Global[] = {
		0x0136, 0x1A, 0x01,
		0x0137, 0x00, 0x01,
		0x304C, 0x00, 0x01,
		0x307D, 0x01, 0x01,
		0x30F0, 0x02, 0x01,
		0x30F1, 0x02, 0x01,
		0x5812, 0x04, 0x01,
		0x5813, 0x04, 0x01,
		0x58D0, 0x07, 0x01,
		0x58E4, 0x01, 0x01,
		0x5E6C, 0x01, 0x01,
		0x5F20, 0x01, 0x01,
		0x5FD5, 0x0E, 0x01,
		0x5FD7, 0x62, 0x01,
		0x5FE1, 0x00, 0x01,
		0x5FE3, 0x54, 0x01,
		0x5FE5, 0x0E, 0x01,
		0x5FE7, 0x62, 0x01,
		0x5FED, 0x0E, 0x01,
		0x5FEF, 0x62, 0x01,
		0x687D, 0x8E, 0x01,
		0x687E, 0x01, 0x01,
		0x687F, 0xA7, 0x01,
		0x72A1, 0x05, 0x01,
		0x72C9, 0x84, 0x01,
		0x72CE, 0x19, 0x01,
		0x72E2, 0x65, 0x01,
		0x72E3, 0x96, 0x01,
		0x72E4, 0x59, 0x01,
		0x72E8, 0x96, 0x01,
		0x72E9, 0x59, 0x01,
		0x72EA, 0x65, 0x01,
		0x72EB, 0x2D, 0x01,
		0x72EC, 0xDD, 0x01,
		0x72ED, 0xD9, 0x01,
		0x72EE, 0x7F, 0x01,
		0x72EF, 0x9A, 0x01,
		0x72F0, 0x17, 0x01,
		0x72F1, 0xF3, 0x01,
		0x72F2, 0x3F, 0x01,
		0x72F3, 0xF3, 0x01,
		0x72F4, 0x3F, 0x01,
		0x72F7, 0xF3, 0x01,
		0x72F8, 0x3F, 0x01,
		0x72FB, 0x2C, 0x01,
		0x7333, 0xBF, 0x01,
		0x7334, 0xF3, 0x01,
		0x7338, 0xFF, 0x01,
		0x7339, 0xF6, 0x01,
		0x734A, 0x23, 0x01,
		0x734D, 0x00, 0x01,
		0x734F, 0x64, 0x01,
		0x7350, 0x00, 0x01,
		0x7360, 0x02, 0x01,
		0x7361, 0x30, 0x01,
		0x7363, 0x00, 0x01,
		0x7366, 0x10, 0x01,
		0x7367, 0x00, 0x01,
		0x7368, 0x23, 0x01,
		0x736B, 0x00, 0x01,
		0x736D, 0x39, 0x01,
		0x736E, 0x00, 0x01,
		0x7377, 0x23, 0x01,
		0x737A, 0x00, 0x01,
		0x737C, 0x64, 0x01,
		0x737D, 0x00, 0x01,
		0x7441, 0x84, 0x01,
		0x7447, 0x62, 0x01,
		0x744F, 0x0E, 0x01,
		0x747D, 0x3A, 0x01,
		0x7483, 0x54, 0x01,
		0x748B, 0x00, 0x01,
		0x7491, 0x60, 0x01,
		0x7497, 0x62, 0x01,
		0x749F, 0x0E, 0x01,
		0x74B9, 0x55, 0x01,
		0x74BF, 0x62, 0x01,
		0x74C7, 0x0E, 0x01,
		0x7932, 0x00, 0x01,
		0x7937, 0x01, 0x01,
		0x793C, 0x01, 0x01,
		0x793D, 0x02, 0x01,
		0x7947, 0x03, 0x01,
		0x811F, 0x01, 0x01,
		0x9333, 0x03, 0x01,
		0x9334, 0x04, 0x01,
		0x9335, 0x05, 0x01,
		0x9346, 0x96, 0x01,
		0x934A, 0x8C, 0x01,
		0x9352, 0xAA, 0x01,
		0xB011, 0x00, 0x01,
		0xB01E, 0x00, 0x01,
		0xB01F, 0x00, 0x01,
		0xB020, 0x00, 0x01,
		0xB021, 0x00, 0x01,
		0xB03C, 0x03, 0x01,
		0xB03D, 0x03, 0x01,
		0xB03E, 0x03, 0x01,
		0xB03F, 0x03, 0x01,
		0xB0B6, 0x05, 0x01,
		0xB0B7, 0x05, 0x01,
		0xB0B8, 0x06, 0x01,
		0xB0B9, 0x05, 0x01,
		0xB0BA, 0x06, 0x01,
		0xB0BB, 0x06, 0x01,
		0xB0BC, 0x06, 0x01,
		0xB0BD, 0x06, 0x01,
		0xB0BE, 0x06, 0x01,
		0xB0BF, 0x06, 0x01,
		0xB0C0, 0x06, 0x01,
		0xB0C1, 0x06, 0x01,
		0xB0C2, 0x06, 0x01,
		0xB0C3, 0x06, 0x01,
		0xB0C4, 0x06, 0x01,
		0xB0C5, 0x06, 0x01,
		0xB0E0, 0x31, 0x01,
		0xB0E1, 0x31, 0x01,
		0xB0E3, 0x26, 0x01,
		0xB0F1, 0x05, 0x01,
		0xBC7B, 0xD4, 0x01,
		0xBC81, 0x74, 0x01,
		0xBC83, 0x44, 0x01,
		0xBC86, 0x07, 0x01,
		0xBC87, 0x18, 0x01,
		0x5E64, 0x01, 0x01,
		0x5FE0, 0x00, 0x01,
		0x5FE1, 0xFB, 0x01,
		0x5FE3, 0x4F, 0x01,
		0x628D, 0x01, 0x01,
		0x6434, 0x01, 0x01,
		0x6435, 0x22, 0x01,
		0x6436, 0x00, 0x01,
		0x6437, 0xC5, 0x01,
		0x6604, 0x01, 0x01,
		0x6605, 0x22, 0x01,
		0x6606, 0x00, 0x01,
		0x6607, 0xC5, 0x01,
		0x660C, 0x00, 0x01,
		0x660D, 0x00, 0x01,
		0x660E, 0x03, 0x01,
		0x660F, 0xFF, 0x01,
		0x6614, 0x00, 0x01,
		0x6615, 0xD3, 0x01,
		0x6616, 0x01, 0x01,
		0x6617, 0x22, 0x01,
		0x6B7D, 0x32, 0x01,
		0x7366, 0xB0, 0x01,
		0x7483, 0x4F, 0x01,
		0x748A, 0x00, 0x01,
		0x748B, 0xFB, 0x01,
		0xBC81, 0x60, 0x01,
		0x5E6F, 0x3F, 0x01,
		0x5E72, 0x01, 0x01,
		0x7912, 0x01, 0x01,
};

/* EVT 2 */
/* Caustion: Mode 1: Use only with C3 */
/* 0: 8064 x 3024 @30 MIPI lane: 4, MIPI data rate(Mbps/lane): 2034.5, MIPI Mclk(Mhz): 26 */
/* 1: 8064 x 2268 @30 MIPI lane: 4, MIPI data rate(Mbps/lane): 2034.5, MIPI Mclk(Mhz): 26 */
/* 2: 6048 x 3024 @30 MIPI lane: 4, MIPI data rate(Mbps/lane): 2034.5, MIPI Mclk(Mhz): 26 */
/* 3: 8064 x 2268 @60 MIPI lane: 4, MIPI data rate(Mbps/lane): 2034.5, MIPI Mclk(Mhz): 26 */
/* 4: 2016 x 1134 @120 MIPI lane: 4, MIPI data rate(Mbps/lane): 1092, MIPI Mclk(Mhz): 26 */
/* 5: 2016 x 1134 @240 MIPI lane: 4, MIPI data rate(Mbps/lane): 1092, MIPI Mclk(Mhz): 26 */
/* 6: 1008 x 756 @120 MIPI lane: 4, MIPI data rate(Mbps/lane): 1800.5, MIPI Mclk(Mhz): 26 */
/* 7: 2016 x 1512 @30 MIPI lane: 4, MIPI data rate(Mbps/lane): 1092, MIPI Mclk(Mhz): 26 */
/* 8: 1504 x 1504 @30 MIPI lane: 4, MIPI data rate(Mbps/lane): 1092, MIPI Mclk(Mhz): 26 */
/* 9: 2016 x 1134 @30 MIPI lane: 4, MIPI data rate(Mbps/lane): 1800.5, MIPI Mclk(Mhz): 26 */

const u32 sensor_imx260_setfile_A_8064x3024_30fps[] = {
		0x9007, 0x00, 0x01,
		0x30F2, 0x00, 0x01,
		0x0112, 0x0A, 0x01,
		0x0113, 0x0A, 0x01,
		0x0114, 0x03, 0x01,
		0x0220, 0x61, 0x01,
		0x0221, 0x11, 0x01,
		0x0340, 0x0C, 0x01,
		0x0341, 0x80, 0x01,
		0x0342, 0x22, 0x01,
		0x0343, 0x00, 0x01,
		0x0381, 0x01, 0x01,
		0x0383, 0x01, 0x01,
		0x0385, 0x01, 0x01,
		0x0387, 0x01, 0x01,
		0x0900, 0x00, 0x01,
		0x0901, 0x11, 0x01,
		0x30F4, 0x01, 0x01,
		0x30F5, 0xA4, 0x01,
		0x30F6, 0x01, 0x01,
		0x30F7, 0x90, 0x01,
		0x31A0, 0x01, 0x01,
		0x31A3, 0x01, 0x01,
		0x31A5, 0x01, 0x01,
		0x31A6, 0x00, 0x01,
		0x560F, 0x46, 0x01,
		0x0344, 0x00, 0x01,
		0x0345, 0x00, 0x01,
		0x0346, 0x00, 0x01,
		0x0347, 0x00, 0x01,
		0x0348, 0x0F, 0x01,
		0x0349, 0xBF, 0x01,
		0x034A, 0x0B, 0x01,
		0x034B, 0xCF, 0x01,
		0x034C, 0x1F, 0x01,
		0x034D, 0x80, 0x01,
		0x034E, 0x0B, 0x01,
		0x034F, 0xD0, 0x01,
		0x0408, 0x00, 0x01,
		0x0409, 0x00, 0x01,
		0x040A, 0x00, 0x01,
		0x040B, 0x00, 0x01,
		0x040C, 0x0F, 0x01,
		0x040D, 0xC0, 0x01,
		0x040E, 0x0B, 0x01,
		0x040F, 0xD0, 0x01,
		0x0301, 0x03, 0x01,
		0x0303, 0x02, 0x01,
		0x0305, 0x04, 0x01,
		0x0306, 0x00, 0x01,
		0x0307, 0xC1, 0x01,
		0x0309, 0x0A, 0x01,
		0x030B, 0x01, 0x01,
		0x030D, 0x04, 0x01,
		0x030E, 0x01, 0x01,
		0x030F, 0x3C, 0x01,
		0x0310, 0x01, 0x01,
};

const u32 sensor_imx260_setfile_A_8064x2268_30fps[] = {
		0x9007, 0x00, 0x01,
		0x30F2, 0x00, 0x01,
		0x0112, 0x0A, 0x01,
		0x0113, 0x0A, 0x01,
		0x0114, 0x03, 0x01,
		0x0220, 0x61, 0x01,
		0x0221, 0x11, 0x01,
		0x0340, 0x0C, 0x01,
		0x0341, 0x80, 0x01,
		0x0342, 0x22, 0x01,
		0x0343, 0x00, 0x01,
		0x0381, 0x01, 0x01,
		0x0383, 0x01, 0x01,
		0x0385, 0x01, 0x01,
		0x0387, 0x01, 0x01,
		0x0900, 0x00, 0x01,
		0x0901, 0x11, 0x01,
		0x30F4, 0x02, 0x01,
		0x30F5, 0x6C, 0x01,
		0x30F6, 0x00, 0x01,
		0x30F7, 0xF0, 0x01,
		0x31A0, 0x01, 0x01,
		0x31A3, 0x01, 0x01,
		0x31A5, 0x01, 0x01,
		0x31A6, 0x00, 0x01,
		0x560F, 0x46, 0x01,
		0x0344, 0x00, 0x01,
		0x0345, 0x00, 0x01,
		0x0346, 0x01, 0x01,
		0x0347, 0x78, 0x01,
		0x0348, 0x0F, 0x01,
		0x0349, 0xBF, 0x01,
		0x034A, 0x0A, 0x01,
		0x034B, 0x57, 0x01,
		0x034C, 0x1F, 0x01,
		0x034D, 0x80, 0x01,
		0x034E, 0x08, 0x01,
		0x034F, 0xDC, 0x01,
		0x0408, 0x00, 0x01,
		0x0409, 0x00, 0x01,
		0x040A, 0x00, 0x01,
		0x040B, 0x00, 0x01,
		0x040C, 0x0F, 0x01,
		0x040D, 0xC0, 0x01,
		0x040E, 0x08, 0x01,
		0x040F, 0xE0, 0x01,
		0x0301, 0x03, 0x01,
		0x0303, 0x02, 0x01,
		0x0305, 0x04, 0x01,
		0x0306, 0x00, 0x01,
		0x0307, 0xC1, 0x01,
		0x0309, 0x0A, 0x01,
		0x030B, 0x01, 0x01,
		0x030D, 0x04, 0x01,
		0x030E, 0x01, 0x01,
		0x030F, 0x3C, 0x01,
		0x0310, 0x01, 0x01,
};

const u32 sensor_imx260_setfile_A_6048x3024_30fps[] = {
		0x9007, 0x00, 0x01,
		0x30F2, 0x00, 0x01,
		0x0112, 0x0A, 0x01,
		0x0113, 0x0A, 0x01,
		0x0114, 0x03, 0x01,
		0x0220, 0x61, 0x01,
		0x0221, 0x11, 0x01,
		0x0340, 0x0C, 0x01,
		0x0341, 0x80, 0x01,
		0x0342, 0x22, 0x01,
		0x0343, 0x00, 0x01,
		0x0381, 0x01, 0x01,
		0x0383, 0x01, 0x01,
		0x0385, 0x01, 0x01,
		0x0387, 0x01, 0x01,
		0x0900, 0x00, 0x01,
		0x0901, 0x11, 0x01,
		0x30F4, 0x02, 0x01,
		0x30F5, 0x1C, 0x01,
		0x30F6, 0x01, 0x01,
		0x30F7, 0x90, 0x01,
		0x31A0, 0x01, 0x01,
		0x31A3, 0x01, 0x01,
		0x31A5, 0x01, 0x01,
		0x31A6, 0x00, 0x01,
		0x560F, 0xE6, 0x01,
		0x0344, 0x01, 0x01,
		0x0345, 0xF8, 0x01,
		0x0346, 0x00, 0x01,
		0x0347, 0x00, 0x01,
		0x0348, 0x0D, 0x01,
		0x0349, 0xC7, 0x01,
		0x034A, 0x0B, 0x01,
		0x034B, 0xCF, 0x01,
		0x034C, 0x17, 0x01,
		0x034D, 0xA0, 0x01,
		0x034E, 0x0B, 0x01,
		0x034F, 0xD0, 0x01,
		0x0408, 0x00, 0x01,
		0x0409, 0x00, 0x01,
		0x040A, 0x00, 0x01,
		0x040B, 0x00, 0x01,
		0x040C, 0x0B, 0x01,
		0x040D, 0xD0, 0x01,
		0x040E, 0x0B, 0x01,
		0x040F, 0xD0, 0x01,
		0x0301, 0x03, 0x01,
		0x0303, 0x02, 0x01,
		0x0305, 0x04, 0x01,
		0x0306, 0x00, 0x01,
		0x0307, 0xC1, 0x01,
		0x0309, 0x0A, 0x01,
		0x030B, 0x01, 0x01,
		0x030D, 0x04, 0x01,
		0x030E, 0x01, 0x01,
		0x030F, 0x3C, 0x01,
		0x0310, 0x01, 0x01,
};


const u32 sensor_imx260_setfile_A_4032x2268_60fps[] = {
		0x9007, 0x00, 0x01,
		0x30F2, 0x00, 0x01,
		0x0112, 0x0A, 0x01,
		0x0113, 0x0A, 0x01,
		0x0114, 0x03, 0x01,
		0x0220, 0x61, 0x01,
		0x0221, 0x11, 0x01,
		0x0340, 0x0A, 0x01,
		0x0341, 0x40, 0x01,
		0x0342, 0x14, 0x01,
		0x0343, 0xB8, 0x01,
		0x0381, 0x01, 0x01,
		0x0383, 0x01, 0x01,
		0x0385, 0x01, 0x01,
		0x0387, 0x01, 0x01,
		0x0900, 0x00, 0x01,
		0x0901, 0x11, 0x01,
		0x30F4, 0x02, 0x01,
		0x30F5, 0xBC, 0x01,
		0x30F6, 0x01, 0x01,
		0x30F7, 0xB8, 0x01,
		0x31A0, 0x02, 0x01,
		0x31A3, 0x01, 0x01,
		0x31A5, 0x00, 0x01,
		0x31A6, 0x00, 0x01,
		0x560F, 0xC8, 0x01,
		0x0344, 0x00, 0x01,
		0x0345, 0x00, 0x01,
		0x0346, 0x01, 0x01,
		0x0347, 0x78, 0x01,
		0x0348, 0x0F, 0x01,
		0x0349, 0xBF, 0x01,
		0x034A, 0x0A, 0x01,
		0x034B, 0x57, 0x01,
		0x034C, 0x0F, 0x01,
		0x034D, 0xC0, 0x01,
		0x034E, 0x08, 0x01,
		0x034F, 0xDC, 0x01,
		0x0408, 0x00, 0x01,
		0x0409, 0x00, 0x01,
		0x040A, 0x00, 0x01,
		0x040B, 0x00, 0x01,
		0x040C, 0x0F, 0x01,
		0x040D, 0xC0, 0x01,
		0x040E, 0x08, 0x01,
		0x040F, 0xE0, 0x01,
		0x0301, 0x03, 0x01,
		0x0303, 0x02, 0x01,
		0x0305, 0x04, 0x01,
		0x0306, 0x00, 0x01,
		0x0307, 0xC1, 0x01,
		0x0309, 0x0A, 0x01,
		0x030B, 0x01, 0x01,
		0x030D, 0x04, 0x01,
		0x030E, 0x01, 0x01,
		0x030F, 0x3C, 0x01,
		0x0310, 0x01, 0x01,
};

const u32 sensor_imx260_setfile_A_2016x1134_120fps[] = {
		0x9007, 0x00, 0x01,
		0x30F2, 0x00, 0x01,
		0x0112, 0x0A, 0x01,
		0x0113, 0x0A, 0x01,
		0x0114, 0x03, 0x01,
		0x0220, 0x00, 0x01,
		0x0221, 0x11, 0x01,
		0x0340, 0x06, 0x01,
		0x0341, 0x40, 0x01,
		0x0342, 0x11, 0x01,
		0x0343, 0x00, 0x01,
		0x0381, 0x01, 0x01,
		0x0383, 0x01, 0x01,
		0x0385, 0x01, 0x01,
		0x0387, 0x01, 0x01,
		0x0900, 0x01, 0x01,
		0x0901, 0x22, 0x01,
		0x30F4, 0x02, 0x01,
		0x30F5, 0xBC, 0x01,
		0x30F6, 0x01, 0x01,
		0x30F7, 0x18, 0x01,
		0x31A0, 0x02, 0x01,
		0x31A3, 0x01, 0x01,
		0x31A5, 0x00, 0x01,
		0x31A6, 0x01, 0x01,
		0x560F, 0x14, 0x01,
		0x0344, 0x00, 0x01,
		0x0345, 0x00, 0x01,
		0x0346, 0x01, 0x01,
		0x0347, 0x78, 0x01,
		0x0348, 0x0F, 0x01,
		0x0349, 0xBF, 0x01,
		0x034A, 0x0A, 0x01,
		0x034B, 0x57, 0x01,
		0x034C, 0x07, 0x01,
		0x034D, 0xE0, 0x01,
		0x034E, 0x04, 0x01,
		0x034F, 0x6E, 0x01,
		0x0408, 0x00, 0x01,
		0x0409, 0x00, 0x01,
		0x040A, 0x00, 0x01,
		0x040B, 0x00, 0x01,
		0x040C, 0x07, 0x01,
		0x040D, 0xE0, 0x01,
		0x040E, 0x04, 0x01,
		0x040F, 0x70, 0x01,
		0x0301, 0x03, 0x01,
		0x0303, 0x02, 0x01,
		0x0305, 0x04, 0x01,
		0x0306, 0x00, 0x01,
		0x0307, 0xC1, 0x01,
		0x0309, 0x0A, 0x01,
		0x030B, 0x01, 0x01,
		0x030D, 0x04, 0x01,
		0x030E, 0x01, 0x01,
		0x030F, 0x3C, 0x01,
		0x0310, 0x01, 0x01,
};

const u32 sensor_imx260_setfile_A_2016x1134_240fps[] = {
		0x9007, 0x00, 0x01,
		0x30F2, 0x00, 0x01,
		0x0112, 0x0A, 0x01,
		0x0113, 0x0A, 0x01,
		0x0114, 0x03, 0x01,
		0x0220, 0x00, 0x01,
		0x0221, 0x11, 0x01,
		0x0340, 0x04, 0x01,
		0x0341, 0xE0, 0x01,
		0x0342, 0x0A, 0x01,
		0x0343, 0xE8, 0x01,
		0x0381, 0x01, 0x01,
		0x0383, 0x01, 0x01,
		0x0385, 0x01, 0x01,
		0x0387, 0x01, 0x01,
		0x0900, 0x01, 0x01,
		0x0901, 0x22, 0x01,
		0x30F4, 0x01, 0x01,
		0x30F5, 0xCC, 0x01,
		0x30F6, 0x01, 0x01,
		0x30F7, 0xEA, 0x01,
		0x31A0, 0x02, 0x01,
		0x31A3, 0x01, 0x01,
		0x31A5, 0x00, 0x01,
		0x31A6, 0x00, 0x01,
		0x560F, 0xC8, 0x01,
		0x0344, 0x00, 0x01,
		0x0345, 0x00, 0x01,
		0x0346, 0x01, 0x01,
		0x0347, 0x78, 0x01,
		0x0348, 0x0F, 0x01,
		0x0349, 0xBF, 0x01,
		0x034A, 0x0A, 0x01,
		0x034B, 0x57, 0x01,
		0x034C, 0x07, 0x01,
		0x034D, 0xE0, 0x01,
		0x034E, 0x04, 0x01,
		0x034F, 0x6E, 0x01,
		0x0408, 0x00, 0x01,
		0x0409, 0x00, 0x01,
		0x040A, 0x00, 0x01,
		0x040B, 0x00, 0x01,
		0x040C, 0x07, 0x01,
		0x040D, 0xE0, 0x01,
		0x040E, 0x04, 0x01,
		0x040F, 0x70, 0x01,
		0x0301, 0x03, 0x01,
		0x0303, 0x02, 0x01,
		0x0305, 0x04, 0x01,
		0x0306, 0x00, 0x01,
		0x0307, 0xC1, 0x01,
		0x0309, 0x0A, 0x01,
		0x030B, 0x01, 0x01,
		0x030D, 0x04, 0x01,
		0x030E, 0x01, 0x01,
		0x030F, 0x3C, 0x01,
		0x0310, 0x01, 0x01,
};

const u32 sensor_imx260_setfile_A_1008x756_120fps[] = {
		0x9007, 0x00, 0x01,
		0x30F2, 0x00, 0x01,
		0x0112, 0x0A, 0x01,
		0x0113, 0x0A, 0x01,
		0x0114, 0x03, 0x01,
		0x0220, 0x00, 0x01,
		0x0221, 0x11, 0x01,
		0x0340, 0x04, 0x01,
		0x0341, 0x0E, 0x01,
		0x0342, 0x1A, 0x01,
		0x0343, 0x30, 0x01,
		0x0381, 0x01, 0x01,
		0x0383, 0x01, 0x01,
		0x0385, 0x01, 0x01,
		0x0387, 0x03, 0x01,
		0x0900, 0x01, 0x01,
		0x0901, 0x42, 0x01,
		0x30F4, 0x03, 0x01,
		0x30F5, 0x20, 0x01,
		0x30F6, 0x01, 0x01,
		0x30F7, 0xFE, 0x01,
		0x31A0, 0x02, 0x01,
		0x31A3, 0x01, 0x01,
		0x31A5, 0x00, 0x01,
		0x31A6, 0x00, 0x01,
		0x560F, 0xC8, 0x01,
		0x0344, 0x00, 0x01,
		0x0345, 0x00, 0x01,
		0x0346, 0x00, 0x01,
		0x0347, 0x00, 0x01,
		0x0348, 0x0F, 0x01,
		0x0349, 0xBF, 0x01,
		0x034A, 0x0B, 0x01,
		0x034B, 0xCF, 0x01,
		0x034C, 0x03, 0x01,
		0x034D, 0xF0, 0x01,
		0x034E, 0x02, 0x01,
		0x034F, 0xF4, 0x01,
		0x0408, 0x00, 0x01,
		0x0409, 0x00, 0x01,
		0x040A, 0x00, 0x01,
		0x040B, 0x00, 0x01,
		0x040C, 0x03, 0x01,
		0x040D, 0xF0, 0x01,
		0x040E, 0x02, 0x01,
		0x040F, 0xF4, 0x01,
		0x0301, 0x03, 0x01,
		0x0303, 0x02, 0x01,
		0x0305, 0x04, 0x01,
		0x0306, 0x00, 0x01,
		0x0307, 0xC1, 0x01,
		0x0309, 0x0A, 0x01,
		0x030B, 0x01, 0x01,
		0x030D, 0x04, 0x01,
		0x030E, 0x01, 0x01,
		0x030F, 0x3C, 0x01,
		0x0310, 0x01, 0x01,
};

const u32 sensor_imx260_setfile_A_2016x1512_30fps[] = {
		0x9007, 0x00, 0x01,
		0x30F2, 0x00, 0x01,
		0x0112, 0x0A, 0x01,
		0x0113, 0x0A, 0x01,
		0x0114, 0x03, 0x01,
		0x0220, 0x00, 0x01,
		0x0221, 0x11, 0x01,
		0x0340, 0x06, 0x01,
		0x0341, 0x40, 0x01,
		0x0342, 0x44, 0x01,
		0x0343, 0x00, 0x01,
		0x0381, 0x01, 0x01,
		0x0383, 0x01, 0x01,
		0x0385, 0x01, 0x01,
		0x0387, 0x01, 0x01,
		0x0900, 0x01, 0x01,
		0x0901, 0x22, 0x01,
		0x30F4, 0x02, 0x01,
		0x30F5, 0x8A, 0x01,
		0x30F6, 0x00, 0x01,
		0x30F7, 0x14, 0x01,
		0x31A0, 0x02, 0x01,
		0x31A3, 0x01, 0x01,
		0x31A5, 0x00, 0x01,
		0x31A6, 0x00, 0x01,
		0x560F, 0xC8, 0x01,
		0x0344, 0x00, 0x01,
		0x0345, 0x00, 0x01,
		0x0346, 0x00, 0x01,
		0x0347, 0x00, 0x01,
		0x0348, 0x0F, 0x01,
		0x0349, 0xBF, 0x01,
		0x034A, 0x0B, 0x01,
		0x034B, 0xCF, 0x01,
		0x034C, 0x07, 0x01,
		0x034D, 0xE0, 0x01,
		0x034E, 0x05, 0x01,
		0x034F, 0xE8, 0x01,
		0x0408, 0x00, 0x01,
		0x0409, 0x00, 0x01,
		0x040A, 0x00, 0x01,
		0x040B, 0x00, 0x01,
		0x040C, 0x07, 0x01,
		0x040D, 0xE0, 0x01,
		0x040E, 0x05, 0x01,
		0x040F, 0xE8, 0x01,
		0x0301, 0x03, 0x01,
		0x0303, 0x02, 0x01,
		0x0305, 0x04, 0x01,
		0x0306, 0x00, 0x01,
		0x0307, 0xC1, 0x01,
		0x0309, 0x0A, 0x01,
		0x030B, 0x01, 0x01,
		0x030D, 0x04, 0x01,
		0x030E, 0x01, 0x01,
		0x030F, 0x3C, 0x01,
		0x0310, 0x01, 0x01,
};

const u32 sensor_imx260_setfile_A_1504x1504_30fps[] = {
		0x9007, 0x00, 0x01,
		0x30F2, 0x00, 0x01,
		0x0112, 0x0A, 0x01,
		0x0113, 0x0A, 0x01,
		0x0114, 0x03, 0x01,
		0x0220, 0x00, 0x01,
		0x0221, 0x11, 0x01,
		0x0340, 0x06, 0x01,
		0x0341, 0x40, 0x01,
		0x0342, 0x44, 0x01,
		0x0343, 0x00, 0x01,
		0x0381, 0x01, 0x01,
		0x0383, 0x01, 0x01,
		0x0385, 0x01, 0x01,
		0x0387, 0x01, 0x01,
		0x0900, 0x01, 0x01,
		0x0901, 0x22, 0x01,
		0x30F4, 0x02, 0x01,
		0x30F5, 0x44, 0x01,
		0x30F6, 0x00, 0x01,
		0x30F7, 0x14, 0x01,
		0x31A0, 0x02, 0x01,
		0x31A3, 0x01, 0x01,
		0x31A5, 0x00, 0x01,
		0x31A6, 0x00, 0x01,
		0x560F, 0xC8, 0x01,
		0x0344, 0x02, 0x01,
		0x0345, 0x00, 0x01,
		0x0346, 0x00, 0x01,
		0x0347, 0x00, 0x01,
		0x0348, 0x0D, 0x01,
		0x0349, 0xBF, 0x01,
		0x034A, 0x0B, 0x01,
		0x034B, 0xCF, 0x01,
		0x034C, 0x05, 0x01,
		0x034D, 0xE0, 0x01,
		0x034E, 0x05, 0x01,
		0x034F, 0xE0, 0x01,
		0x0408, 0x00, 0x01,
		0x0409, 0x00, 0x01,
		0x040A, 0x00, 0x01,
		0x040B, 0x04, 0x01,
		0x040C, 0x05, 0x01,
		0x040D, 0xE0, 0x01,
		0x040E, 0x05, 0x01,
		0x040F, 0xE0, 0x01,
		0x0301, 0x03, 0x01,
		0x0303, 0x02, 0x01,
		0x0305, 0x04, 0x01,
		0x0306, 0x00, 0x01,
		0x0307, 0xC1, 0x01,
		0x0309, 0x0A, 0x01,
		0x030B, 0x01, 0x01,
		0x030D, 0x04, 0x01,
		0x030E, 0x01, 0x01,
		0x030F, 0x3C, 0x01,
		0x0310, 0x01, 0x01,
};

const u32 sensor_imx260_setfile_A_2016x1134_30fps[] = {
		0x9007, 0x00, 0x01,
		0x30F2, 0x00, 0x01,
		0x0112, 0x0A, 0x01,
		0x0113, 0x0A, 0x01,
		0x0114, 0x03, 0x01,
		0x0220, 0x00, 0x01,
		0x0221, 0x11, 0x01,
		0x0340, 0x06, 0x01,
		0x0341, 0x40, 0x01,
		0x0342, 0x44, 0x01,
		0x0343, 0x00, 0x01,
		0x0381, 0x01, 0x01,
		0x0383, 0x01, 0x01,
		0x0385, 0x01, 0x01,
		0x0387, 0x01, 0x01,
		0x0900, 0x01, 0x01,
		0x0901, 0x22, 0x01,
		0x30F4, 0x02, 0x01,
		0x30F5, 0xE4, 0x01,
		0x30F6, 0x00, 0x01,
		0x30F7, 0x14, 0x01,
		0x31A0, 0x02, 0x01,
		0x31A3, 0x01, 0x01,
		0x31A5, 0x00, 0x01,
		0x31A6, 0x01, 0x01,
		0x560F, 0xB4, 0x01,
		0x0344, 0x00, 0x01,
		0x0345, 0x00, 0x01,
		0x0346, 0x01, 0x01,
		0x0347, 0x78, 0x01,
		0x0348, 0x0F, 0x01,
		0x0349, 0xBF, 0x01,
		0x034A, 0x0A, 0x01,
		0x034B, 0x57, 0x01,
		0x034C, 0x07, 0x01,
		0x034D, 0xE0, 0x01,
		0x034E, 0x04, 0x01,
		0x034F, 0x6E, 0x01,
		0x0408, 0x00, 0x01,
		0x0409, 0x00, 0x01,
		0x040A, 0x00, 0x01,
		0x040B, 0x00, 0x01,
		0x040C, 0x07, 0x01,
		0x040D, 0xE0, 0x01,
		0x040E, 0x04, 0x01,
		0x040F, 0x70, 0x01,
		0x0301, 0x03, 0x01,
		0x0303, 0x02, 0x01,
		0x0305, 0x04, 0x01,
		0x0306, 0x00, 0x01,
		0x0307, 0xC1, 0x01,
		0x0309, 0x0A, 0x01,
		0x030B, 0x01, 0x01,
		0x030D, 0x04, 0x01,
		0x030E, 0x01, 0x01,
		0x030F, 0x3C, 0x01,
		0x0310, 0x01, 0x01,
};

#ifdef CONFIG_SENSOR_RETENTION_USE
const u32 sensor_imx260_setfile_A_global_retention[] = {
		0x0136, 0x1A, 0x01,
		0x0137, 0x00, 0x01,
		0x5812, 0x04, 0x01,
		0x5813, 0x04, 0x01,
		0x5F20, 0x01, 0x01,
		0x72E8, 0x96, 0x01,
		0x72E9, 0x59, 0x01,
		0x72EA, 0x65, 0x01,
		0x72FB, 0x2C, 0x01,
		0x9333, 0x03, 0x01,
		0x9334, 0x04, 0x01,
		0x9335, 0x05, 0x01,
		0x9346, 0x96, 0x01,
		0x934A, 0x8C, 0x01,
		0x9352, 0xAA, 0x01,
		0xB0B6, 0x05, 0x01,
		0xB0B7, 0x05, 0x01,
		0xB0B9, 0x05, 0x01,
		0x7937, 0x01, 0x01,
		0x793D, 0x02, 0x01,
		0x5E64, 0x01, 0x01,
		0x5FE0, 0x00, 0x01,
		0x5FE1, 0xFB, 0x01,
		0x5FE3, 0x4F, 0x01,
		0x628D, 0x01, 0x01,
		0x6434, 0x01, 0x01,
		0x6435, 0x22, 0x01,
		0x6436, 0x00, 0x01,
		0x6437, 0xC5, 0x01,
		0x6604, 0x01, 0x01,
		0x6605, 0x22, 0x01,
		0x6606, 0x00, 0x01,
		0x6607, 0xC5, 0x01,
		0x660C, 0x00, 0x01,
		0x660D, 0x00, 0x01,
		0x660E, 0x03, 0x01,
		0x660F, 0xFF, 0x01,
		0x6614, 0x00, 0x01,
		0x6615, 0xD3, 0x01,
		0x6616, 0x01, 0x01,
		0x6617, 0x22, 0x01,
		0x6B7D, 0x32, 0x01,
		0x7366, 0xB0, 0x01,
		0x7483, 0x4F, 0x01,
		0x748A, 0x00, 0x01,
		0x748B, 0xFB, 0x01,
		0xBC81, 0x60, 0x01,
		0x5E6F, 0x3F, 0x01,
		0x5E72, 0x01, 0x01,
		0x7912, 0x01, 0x01,
};

const u32 sensor_imx260_setfile_A_8064x3024_30fps_retention[] = {
		0x9007, 0x02, 0x01,
		0x0340, 0x0C, 0x01,
		0x0341, 0x80, 0x01,
		0x0342, 0x22, 0x01,
		0x0343, 0x00, 0x01,
		0x30F4, 0x01, 0x01,
		0x30F5, 0xA4, 0x01,
		0x30F6, 0x01, 0x01,
		0x30F7, 0x90, 0x01,
		0x560F, 0x46, 0x01,
		0x0306, 0x00, 0x01,
		0x0307, 0xC1, 0x01,
		0x030E, 0x01, 0x01,
		0x030F, 0x3C, 0x01,
};

const u32 sensor_imx260_setfile_A_8064x2268_30fps_retention[] = {
		0x9007, 0x12, 0x01,
		0x0340, 0x0C, 0x01,
		0x0341, 0x80, 0x01,
		0x0342, 0x22, 0x01,
		0x0343, 0x00, 0x01,
		0x30F4, 0x02, 0x01,
		0x30F5, 0x6C, 0x01,
		0x30F6, 0x00, 0x01,
		0x30F7, 0xF0, 0x01,
		0x560F, 0x46, 0x01,
		0x0306, 0x00, 0x01,
		0x0307, 0xC1, 0x01,
		0x030E, 0x01, 0x01,
		0x030F, 0x3C, 0x01,
};

const u32 sensor_imx260_setfile_A_4032x2268_60fps_retention[] = {
		0x9007, 0x32, 0x01,
		0x0340, 0x0A, 0x01,
		0x0341, 0x40, 0x01,
		0x0342, 0x14, 0x01,
		0x0343, 0xB8, 0x01,
		0x30F4, 0x02, 0x01,
		0x30F5, 0xBC, 0x01,
		0x30F6, 0x01, 0x01,
		0x30F7, 0xB8, 0x01,
		0x560F, 0xC8, 0x01,
		0x0306, 0x00, 0x01,
		0x0307, 0xC1, 0x01,
		0x030E, 0x01, 0x01,
		0x030F, 0x3C, 0x01,
};

const u32 sensor_imx260_setfile_A_1008x756_120fps_retention[] = {
		0x9007, 0x22, 0x01,
		0x0340, 0x04, 0x01,
		0x0341, 0x0E, 0x01,
		0x0342, 0x1A, 0x01,
		0x0343, 0x30, 0x01,
		0x30F4, 0x03, 0x01,
		0x30F5, 0x20, 0x01,
		0x30F6, 0x01, 0x01,
		0x30F7, 0xFE, 0x01,
		0x560F, 0xC8, 0x01,
		0x0306, 0x00, 0x01,
		0x0307, 0xC1, 0x01,
		0x030E, 0x01, 0x01,
		0x030F, 0x3C, 0x01,
};
#endif

const struct sensor_pll_info_compact sensor_imx260_pllinfo_A_8064x3024_30fps = {
	EXT_CLK_Mhz * 1000 * 1000, /* ext_clk */
	2054000000,
	836330000,
	0x0C80,
	0x2200,
};

const struct sensor_pll_info_compact sensor_imx260_pllinfo_A_8064x2268_30fps = {
	EXT_CLK_Mhz * 1000 * 1000, /* ext_clk */
	2054000000,
	836330000,
	0x0C80,
	0x2200,
};

const struct sensor_pll_info_compact sensor_imx260_pllinfo_A_6048x3024_30fps = {
	EXT_CLK_Mhz * 1000 * 1000, /* ext_clk */
	2054000000,
	836330000,
	0x0C80,
	0x2200,
};

const struct sensor_pll_info_compact sensor_imx260_pllinfo_A_4032x2268_60fps = {
	EXT_CLK_Mhz * 1000 * 1000, /* ext_clk */
	2054000000,
	836330000,
	0x0A40,
	0x14B8,
};

const struct sensor_pll_info_compact sensor_imx260_pllinfo_A_2016x1134_120fps = {
	EXT_CLK_Mhz * 1000 * 1000, /* ext_clk */
	2054000000,
	836330000,
	0x0640,
	0x1100,
};

const struct sensor_pll_info_compact sensor_imx260_pllinfo_A_2016x1134_240fps = {
	EXT_CLK_Mhz * 1000 * 1000, /* ext_clk */
	2054000000,
	836330000,
	0x04E0,
	0x0AE8,
};

const struct sensor_pll_info_compact sensor_imx260_pllinfo_A_1008x756_120fps = {
	EXT_CLK_Mhz * 1000 * 1000, /* ext_clk */
	2054000000,
	836330000,
	0x040E,
	0x1A30,
};

const struct sensor_pll_info_compact sensor_imx260_pllinfo_A_2016x1512_30fps = {
	EXT_CLK_Mhz * 1000 * 1000, /* ext_clk */
	2054000000,
	836330000,
	0x0640,
	0x4400,
};

const struct sensor_pll_info_compact sensor_imx260_pllinfo_A_1504x1504_30fps = {
	EXT_CLK_Mhz * 1000 * 1000, /* ext_clk */
	2054000000,
	836330000,
	0x0640,
	0x4400,
};

const struct sensor_pll_info_compact sensor_imx260_pllinfo_A_2016x1134_30fps = {
	EXT_CLK_Mhz * 1000 * 1000, /* ext_clk */
	2054000000,
	836330000,
	0x0640,
	0x4400,
};

static const u32 *sensor_imx260_setfiles_A[] = {
	sensor_imx260_setfile_A_8064x3024_30fps,
	sensor_imx260_setfile_A_8064x2268_30fps,
	sensor_imx260_setfile_A_6048x3024_30fps,
	sensor_imx260_setfile_A_4032x2268_60fps,
	sensor_imx260_setfile_A_2016x1134_120fps,
	sensor_imx260_setfile_A_2016x1134_240fps,
	sensor_imx260_setfile_A_1008x756_120fps,
	sensor_imx260_setfile_A_2016x1512_30fps,
	sensor_imx260_setfile_A_1504x1504_30fps,
	sensor_imx260_setfile_A_2016x1134_30fps,
};

static const u32 sensor_imx260_setfile_A_sizes[] = {
	sizeof(sensor_imx260_setfile_A_8064x3024_30fps) / sizeof(sensor_imx260_setfile_A_8064x3024_30fps[0]),
	sizeof(sensor_imx260_setfile_A_8064x2268_30fps) / sizeof(sensor_imx260_setfile_A_8064x2268_30fps[0]),
	sizeof(sensor_imx260_setfile_A_6048x3024_30fps) / sizeof(sensor_imx260_setfile_A_6048x3024_30fps[0]),
	sizeof(sensor_imx260_setfile_A_4032x2268_60fps) / sizeof(sensor_imx260_setfile_A_4032x2268_60fps[0]),
	sizeof(sensor_imx260_setfile_A_2016x1134_120fps) / sizeof(sensor_imx260_setfile_A_2016x1134_120fps[0]),
	sizeof(sensor_imx260_setfile_A_2016x1134_240fps) / sizeof(sensor_imx260_setfile_A_2016x1134_240fps[0]),
	sizeof(sensor_imx260_setfile_A_1008x756_120fps) / sizeof(sensor_imx260_setfile_A_1008x756_120fps[0]),
	sizeof(sensor_imx260_setfile_A_2016x1512_30fps) / sizeof(sensor_imx260_setfile_A_2016x1512_30fps[0]),
	sizeof(sensor_imx260_setfile_A_1504x1504_30fps) / sizeof(sensor_imx260_setfile_A_1504x1504_30fps[0]),
	sizeof(sensor_imx260_setfile_A_2016x1134_30fps) / sizeof(sensor_imx260_setfile_A_2016x1134_30fps[0]),
};

#ifdef CONFIG_SENSOR_RETENTION_USE
static const u32 *sensor_imx260_setfiles_A_retention[] = {
	sensor_imx260_setfile_A_8064x3024_30fps_retention,
	sensor_imx260_setfile_A_8064x2268_30fps_retention,
	sensor_imx260_setfile_A_1008x756_120fps_retention,
	sensor_imx260_setfile_A_4032x2268_60fps_retention,
};

static const u32 sensor_imx260_setfile_A_sizes_retention[] = {
	sizeof(sensor_imx260_setfile_A_8064x3024_30fps_retention) / sizeof(sensor_imx260_setfile_A_8064x3024_30fps_retention[0]),
	sizeof(sensor_imx260_setfile_A_8064x2268_30fps_retention) / sizeof(sensor_imx260_setfile_A_8064x2268_30fps_retention[0]),
	sizeof(sensor_imx260_setfile_A_1008x756_120fps_retention) / sizeof(sensor_imx260_setfile_A_1008x756_120fps_retention[0]),
	sizeof(sensor_imx260_setfile_A_4032x2268_60fps_retention) / sizeof(sensor_imx260_setfile_A_4032x2268_60fps_retention[0]),
};
#endif

static const struct sensor_pll_info_compact *sensor_imx260_pllinfos_A[] = {
	&sensor_imx260_pllinfo_A_8064x3024_30fps,
	&sensor_imx260_pllinfo_A_8064x2268_30fps,
	&sensor_imx260_pllinfo_A_6048x3024_30fps,
	&sensor_imx260_pllinfo_A_4032x2268_60fps,
	&sensor_imx260_pllinfo_A_2016x1134_120fps,
	&sensor_imx260_pllinfo_A_2016x1134_240fps,
	&sensor_imx260_pllinfo_A_1008x756_120fps,
	&sensor_imx260_pllinfo_A_2016x1512_30fps,
	&sensor_imx260_pllinfo_A_1504x1504_30fps,
	&sensor_imx260_pllinfo_A_2016x1134_30fps,
};

#endif
