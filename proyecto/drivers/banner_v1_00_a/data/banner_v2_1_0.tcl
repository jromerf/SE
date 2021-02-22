##############################################################################
## Filename:          D:\hlocal\SE\Practicas\proyecto/drivers/banner_v1_00_a/data/banner_v2_1_0.tcl
## Description:       Microprocess Driver Command (tcl)
## Date:              Sun Feb 21 20:24:59 2021 (by Create and Import Peripheral Wizard)
##############################################################################

#uses "xillib.tcl"

proc generate {drv_handle} {
  xdefine_include_file $drv_handle "xparameters.h" "banner" "NUM_INSTANCES" "DEVICE_ID" "C_BASEADDR" "C_HIGHADDR" 
}
