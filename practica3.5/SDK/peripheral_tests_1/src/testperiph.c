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
/*#include "xil_cache.h"
#include "xbasic_types.h"
#include "xbram.h"
#include "bram_header.h"*/
#include "coprocesador.h"



#define coprocessBaseAd 0x84018000

int getNumber (){

	Xuint8 byte;
	Xuint8 uartBuffer[16];
	Xboolean validNumber;
	int digitIndex;
	int digit, number, sign;
	int c;

	while(1){
		byte = 0x00;
		digit = 0;
		digitIndex = 0;
		number = 0;
		validNumber = XTRUE;

		//get bytes from uart until RETURN is entered

		while(byte != 0x0d && byte != 0x0A){

			//byte = XUartLite_RecvByte(XPAR_RS232_UART_1_BASEADDR);

			byte = XUartLite_RecvByte(XPAR_XPS_UARTLITE_0_BASEADDR);

			uartBuffer[digitIndex] = byte;

			//XUartLite_SendByte(XPAR_RS232_UART_1_BASEADDR,byte);

			XUartLite_SendByte(XPAR_XPS_UARTLITE_0_BASEADDR,byte);

			digitIndex++;

			//xil_printf("byte -> = %d\n", byte);

		}

		//calculate number from string of digits
		//xil_printf("Entraremos al for\n");
		for(c = 0; c < (digitIndex - 1); c++){
			if(c == 0){
				//check if first byte is a "-"
				if(uartBuffer[c] == 0x2D){
					sign = -1;
					digit = 0;
				}
				//check if first byte is a digit
				else if((uartBuffer[c] >> 4) == 0x03){
					sign = 1;
					digit = (uartBuffer[c] & 0x0F);
				}
				else
					validNumber = XFALSE;
			}
			else{
				//check byte is a digit
				if((uartBuffer[c] >> 4) == 0x03){
					digit = (uartBuffer[c] & 0x0F);
				}
				else
					validNumber = XFALSE;
			}
			number = (number * 10) + digit;

			//xil_printf("numero -> : %d\n", number);

		}
		number *= sign;
		if(validNumber == XTRUE){
			//xil_printf("Devolvemos numero ->: %d",number);
			return number;
		}
		print("This is not a valid number.\n\r");
		////number = atoi(byte);
		//xil_printf("lo tranformamos a numero -> : %d", number);
		//return number;
	}
}


int main() 
{


  // Xil_ICacheEnable();
  // Xil_DCacheEnable();

   print("---Entering main---\n\r");

   //COPROCESADOR_SelfTest(COPROCESADOR_USER_SLV_SPACE_OFFSET);
   
   /*
    * Peripheral SelfTest will not be run for xps_uartlite_0
    * because it has been selected as the STDOUT device
    */

   int exit = 0, value;

    while(exit == 0){
	    	print(" MENU: \n\r");
	    	print(" 1 - Choose (+) or (-) \n\r");
			print(" 2 - Introduce first number. \n\r");
			print(" 3 - Introduce second number. \n\r");
			print(" 4 - Result from operation [reg3] . \n\r");
			print(" 5 - Introduce a value to [reg3] . \n\r");
			print(" 6 - EXIT \n\r");

			value = COPROCESADOR_mReadReg(XPAR_COPROCESADOR_0_BASEADDR, COPROCESADOR_SLV_REG0_OFFSET);
			xil_printf(" read %d from register 0\n\r", value);
			value = COPROCESADOR_mReadReg(XPAR_COPROCESADOR_0_BASEADDR, COPROCESADOR_SLV_REG1_OFFSET);
			xil_printf(" read %d from register 1\n\r", value);
			value = COPROCESADOR_mReadReg(XPAR_COPROCESADOR_0_BASEADDR, COPROCESADOR_SLV_REG2_OFFSET);
			xil_printf(" read %d from register 2\n\r", value);
			value = COPROCESADOR_mReadReg(XPAR_COPROCESADOR_0_BASEADDR, COPROCESADOR_SLV_REG3_OFFSET);
			xil_printf(" read %d from register 3\n\r", value);

			value = getNumber();

			switch(value){

			case 1:
				xil_printf(" 1 - Introduce 0 for (+) or 1 for (-) \n\r");
				value = getNumber();

				COPROCESADOR_mWriteReg(XPAR_COPROCESADOR_0_BASEADDR,COPROCESADOR_SLV_REG0_OFFSET,value);
				value = COPROCESADOR_mReadReg(XPAR_COPROCESADOR_0_BASEADDR,COPROCESADOR_SLV_REG0_OFFSET);
				xil_printf(" Value from Reg0: %d\n\r", value);

				break;
			case 2:
				xil_printf("Introduce a number from 0 to 9: \n\r");
				value = getNumber();

				COPROCESADOR_mWriteReg(XPAR_COPROCESADOR_0_BASEADDR,COPROCESADOR_SLV_REG1_OFFSET,value);
				value = COPROCESADOR_mReadReg(XPAR_COPROCESADOR_0_BASEADDR,COPROCESADOR_SLV_REG1_OFFSET);
				xil_printf(" Value from Reg1: %d\n\r", value);
				break;
			case 3:
				xil_printf("Introduce a number from 0 to 9: \n\r");
				value = getNumber();

				COPROCESADOR_mWriteReg(XPAR_COPROCESADOR_0_BASEADDR,COPROCESADOR_SLV_REG2_OFFSET,value);
				value = COPROCESADOR_mReadReg(XPAR_COPROCESADOR_0_BASEADDR,COPROCESADOR_SLV_REG2_OFFSET);
				xil_printf(" Value from Reg2: %d\n\r", value);
				break;
			case 4:
				value = COPROCESADOR_mReadReg(XPAR_COPROCESADOR_0_BASEADDR,COPROCESADOR_SLV_REG3_OFFSET);
				xil_printf(" Your result on Reg3: %d\n\r", value);
				break;
			case 5:
				xil_printf("Introduce a number from 0 to 9: \n\r");
				value = getNumber();
				COPROCESADOR_mWriteReg(XPAR_COPROCESADOR_0_BASEADDR,COPROCESADOR_SLV_REG3_OFFSET,value);

				value = COPROCESADOR_mReadReg(XPAR_COPROCESADOR_0_BASEADDR,COPROCESADOR_SLV_REG3_OFFSET);
				xil_printf(" Your result on Reg3: %d\n\r", value);
				break;
			case 6:
				exit = 1;
				break;
			default:
						print("Wrong number, enter again\n\r");
			}


	    }

   print("---Exiting main---\n\r");

   Xil_DCacheDisable();
   Xil_ICacheDisable();

   return 0;
}

