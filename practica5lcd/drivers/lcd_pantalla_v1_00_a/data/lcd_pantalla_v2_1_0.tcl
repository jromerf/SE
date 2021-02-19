##############################################################################
## Filename:          D:\hlocal\SE\Practicas\practica5lcd/drivers/lcd_pantalla_v1_00_a/data/lcd_pantalla_v2_1_0.tcl
## Description:       Microprocess Driver Command (tcl)
## Date:              Fri Feb 19 18:53:54 2021 (by Create and Import Peripheral Wizard)
##############################################################################

#uses "xillib.tcl"

proc generate {drv_handle} {
  xdefine_include_file $drv_handle "xparameters.h" "lcd_pantalla" "NUM_INSTANCES" "DEVICE_ID" "C_BASEADDR" "C_HIGHADDR" 
}
