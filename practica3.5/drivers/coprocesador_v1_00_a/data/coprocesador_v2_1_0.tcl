##############################################################################
## Filename:          D:\hlocal\SE\Practicas\practica3.5/drivers/coprocesador_v1_00_a/data/coprocesador_v2_1_0.tcl
## Description:       Microprocess Driver Command (tcl)
## Date:              Sat Dec 19 04:09:48 2020 (by Create and Import Peripheral Wizard)
##############################################################################

#uses "xillib.tcl"

proc generate {drv_handle} {
  xdefine_include_file $drv_handle "xparameters.h" "coprocesador" "NUM_INSTANCES" "DEVICE_ID" "C_BASEADDR" "C_HIGHADDR" 
}
