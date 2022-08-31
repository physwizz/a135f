#!/bin/bash

make clean && make mrproper
export ARCH=arm64
export PLATFORM_VERSION=12
export ANDROID_MAJOR_VERSION=s


make ARCH=arm64 mcrazymanu_defconfig
make ARCH=arm64 -j16

cp -r arch/arm64/boot/Image AIK/Image
cp -r arch/arm64/boot/dtb_exynos.img AIK/dtb
cp -r arch/arm64/boot/dtbo_exynos.img AIK/dtbo
cd AIK
rm -rf mcrazymanu_kernel_a13.zip
rm -rf mcrazymanu_kernel_a13.zip
zip -r3 mcrazymanu_kernel_a13.zip * -x .git README.md *placeholder
cd ..
