##############################################################################
## Filename:          D:\hlocal\SE\Practicas\practica5/drivers/lcd_pantalla_v1_00_a/data/lcd_pantalla_v2_1_0.tcl
## Description:       Microprocess Driver Command (tcl)
## Date:              Wed Feb 17 20:08:44 2021 (by Create and Import Peripheral Wizard)
##############################################################################

#uses "xillib.tcl"

proc generate {drv_handle} {
  xdefine_include_file $drv_handle "xparameters.h" "lcd_pantalla" "NUM_INSTANCES" "DEVICE_ID" "C_BASEADDR" "C_HIGHADDR" 
}
