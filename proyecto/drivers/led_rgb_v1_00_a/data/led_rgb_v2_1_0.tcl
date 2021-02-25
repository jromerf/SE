##############################################################################
## Filename:          D:\hlocal\SE\Practicas\proyecto/drivers/led_rgb_v1_00_a/data/led_rgb_v2_1_0.tcl
## Description:       Microprocess Driver Command (tcl)
## Date:              Wed Feb 24 23:04:15 2021 (by Create and Import Peripheral Wizard)
##############################################################################

#uses "xillib.tcl"

proc generate {drv_handle} {
  xdefine_include_file $drv_handle "xparameters.h" "led_rgb" "NUM_INSTANCES" "DEVICE_ID" "C_BASEADDR" "C_HIGHADDR" 
}
