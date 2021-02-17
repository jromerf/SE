##############################################################################
## Filename:          D:\hlocal\SE\Practicas\practica4/drivers/pantalla_v1_00_a/data/pantalla_v2_1_0.tcl
## Description:       Microprocess Driver Command (tcl)
## Date:              Tue Jan 12 01:07:49 2021 (by Create and Import Peripheral Wizard)
##############################################################################

#uses "xillib.tcl"

proc generate {drv_handle} {
  xdefine_include_file $drv_handle "xparameters.h" "pantalla" "NUM_INSTANCES" "DEVICE_ID" "C_BASEADDR" "C_HIGHADDR" 
}
