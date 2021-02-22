##############################################################################
## Filename:          D:\hlocal\SE\Practicas\proyecto/drivers/pantallas_v1_00_a/data/pantallas_v2_1_0.tcl
## Description:       Microprocess Driver Command (tcl)
## Date:              Sat Feb 20 18:00:37 2021 (by Create and Import Peripheral Wizard)
##############################################################################

#uses "xillib.tcl"

proc generate {drv_handle} {
  xdefine_include_file $drv_handle "xparameters.h" "pantallas" "NUM_INSTANCES" "DEVICE_ID" "C_BASEADDR" "C_HIGHADDR" 
}
