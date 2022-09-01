# AnyKernel3 Ramdisk Mod Script
# osm0sis @ xda-developers

## AnyKernel setup
# begin properties
properties() { '
kernel.string= Kernel by MCRAZYMANU
do.devicecheck=0
do.modules=0
do.systemless=1
do.cleanup=1
do.cleanuponabort=0
device.name1=a13
device.name2=a135s
device.name3=a135f
device.name4=a135
device.name5=a135g
supported.versions=
supported.patchlevels=
'; } # end properties

# shell variables
block=/dev/block/platform/12100000.dwmmc0/by-name/boot;
bdtbolock=/dev/block/platform/12100000.dwmmc0/by-name/dtbo;
is_slot_device=0;
ramdisk_compression=auto;


## AnyKernel methods (DO NOT CHANGE)
# import patching functions/variables - see for reference
. tools/ak3-core.sh;


## AnyKernel file attributes
# set permissions/ownership for included ramdisk files
set_perm_recursive 0 0 755 644 $ramdisk/*;
set_perm_recursive 0 0 750 750 $ramdisk/init* $ramdisk/sbin;

## AnyKernel install
dump_boot;

write_boot;
## end install
