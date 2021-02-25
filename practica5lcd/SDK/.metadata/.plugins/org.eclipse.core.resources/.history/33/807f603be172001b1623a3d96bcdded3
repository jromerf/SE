/*
 *
 * Xilinx, Inc.
 * XILINX IS PROVIDING THIS DESIGN, CODE, OR INFORMATION "AS IS" AS A 
 * COURTESY TO YOU.  BY PROVIDING THIS DESIGN, CODE, OR INFORMATION AS
 * ONE POSSIBLE   IMPLEMENTATION OF THIS FEATURE, APPLICATION OR 
 * STANDARD, XILINX IS MAKING NO REPRESENTATION THAT THIS IMPLEMENTATION 
 * IS FREE FROM ANY CLAIMS OF INFRINGEMENT, AND YOU ARE RESPONSIBLE 
 * FOR OBTAINING ANY RIGHTS YOU MAY REQUIRE FOR YOUR IMPLEMENTATION
 * XILINX EXPRESSLY DISCLAIMS ANY WARRANTY WHATSOEVER WITH RESPECT TO 
 * THE ADEQUACY OF THE IMPLEMENTATION, INCLUDING BUT NOT LIMITED TO 
 * ANY WARRANTIES OR REPRESENTATIONS THAT THIS IMPLEMENTATION IS FREE 
 * FROM CLAIMS OF INFRINGEMENT, IMPLIED WARRANTIES OF MERCHANTABILITY 
 * AND FITNESS FOR A PARTICULAR PURPOSE.
 */

/*
 * 
 *
 * This file is a generated sample test application.
 *
 * This application is intended to test and/or illustrate some 
 * functionality of your system.  The contents of this file may
 * vary depending on the IP in your system and may use existing
 * IP driver functions.  These drivers will be generated in your
 * SDK application project when you run the "Generate Libraries" menu item.
 *
 */


#include <stdio.h>
#include "xparameters.h"
#include "xil_cache.h"
#include "xbasic_types.h"
#include "xbram.h"
#include "bram_header.h"
#include "lcd_pantalla.h"

#define CLEAR_DISPLAY_CMD 0X00000001
#define RETURN_HOME_CMD 0X00000002
#define WRITE_CMD 0X00000200
#define FIRST_ROW 0X00000080
#define SECOND_ROW 0X000000C0


void LCD_enviarCMD(Xuint32 cmd){

	while(LCD_PANTALLA_mWriteFIFOFull(XPAR_LCD_PANTALLA_0_BASEADDR)){}
	LCD_PANTALLA_mWriteToFIFO(XPAR_LCD_PANTALLA_0_BASEADDR,0,cmd);
}

void LCD_inicializa(){
	LCD_PANTALLA_mResetWriteFIFO(XPAR_LCD_PANTALLA_0_BASEADDR);
	LCD_enviarCMD(CLEAR_DISPLAY_CMD);
	LCD_enviarCMD(RETURN_HOME_CMD);
	LCD_enviarCMD(WRITE_CMD);
}

int main() 
{


   Xil_ICacheEnable();
   Xil_DCacheEnable();

   print("---Entering main---\n\r");
   

   {
      int status;
      
      print("\r\nRunning Bram Example() for xps_bram_if_cntlr_0...\r\n");

      status = BramExample(XPAR_XPS_BRAM_IF_CNTLR_0_DEVICE_ID);

      if (status == 0) {
         xil_printf("Bram Example PASSED.\r\n");
      }
      else {
         print("Bram Example FAILED.\r\n");
      }
   }

   
	xil_printf("Inicializando lcd\n\r");
	LCD_inicializa();
	LCD_enviarCMD(WRITE_CMD + 'H');
	LCD_enviarCMD(WRITE_CMD + 'O');
	LCD_enviarCMD(WRITE_CMD + 'L');
	LCD_enviarCMD(WRITE_CMD + 'A');
	LCD_enviarCMD(SECOND_ROW);
	LCD_enviarCMD(WRITE_CMD + 'J');
	LCD_enviarCMD(WRITE_CMD + 'A');
	LCD_enviarCMD(WRITE_CMD + 'L');
	LCD_enviarCMD(WRITE_CMD + 'O');


   /*
    * Peripheral SelfTest will not be run for xps_uartlite_0
    * because it has been selected as the STDOUT device
    */


   print("---Exiting main---\n\r");

   Xil_DCacheDisable();
   Xil_ICacheDisable();

   return 0;
}

