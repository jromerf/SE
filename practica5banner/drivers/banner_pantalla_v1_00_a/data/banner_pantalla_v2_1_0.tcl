##############################################################################
## Filename:          D:\hlocal\SE\Practicas\practica5banner/drivers/banner_pantalla_v1_00_a/data/banner_pantalla_v2_1_0.tcl
## Description:       Microprocess Driver Command (tcl)
## Date:              Fri Feb 19 19:44:23 2021 (by Create and Import Peripheral Wizard)
##############################################################################

#uses "xillib.tcl"

proc generate {drv_handle} {
  xdefine_include_file $drv_handle "xparameters.h" "banner_pantalla" "NUM_INSTANCES" "DEVICE_ID" "C_BASEADDR" "C_HIGHADDR" 
}
