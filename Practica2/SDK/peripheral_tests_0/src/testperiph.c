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
#include "xbasic_types.h"
#include "xgpio.h"
#include "gpio_header.h"
#include "xuartlite_l.h"
#include <xstatus.h>
#include <stdlib.h>

/*
 * LEDs; configured as Salida
 * SWITCHes; configured as Entrada
 */


#define CHANNEL 1
#define OUTPUT 0x00000000
#define INPUT 0xFFFFFFFF


#define XPAR_RS232_UART_1_BASEADDR 0x84000000

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

			byte = XUartLite_RecvByte(XPAR_RS232_UART_1_BASEADDR);

			//byte = XUartLite_RecvByte(XPAR_XPS_UARTLITE_0_BASEADDR);

			uartBuffer[digitIndex] = byte;

			XUartLite_SendByte(XPAR_RS232_UART_1_BASEADDR,byte);

			//XUartLite_SendByte(XPAR_XPS_UARTLITE_0_BASEADDR,byte);

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
	XGpio GPIO_LEDS,GPIO_SWITCHES;
	int exit = 0, option = 0, opa=0,opb=0,resul = 0;

	//CLEAN LEDS
	XGpio_Initialize(&GPIO_LEDS,XPAR_LEDS_GPIO_DEVICE_ID);
	XGpio_SetDataDirection(&GPIO_LEDS, CHANNEL, OUTPUT);
	XGpio_DiscreteWrite(&GPIO_LEDS, 1, 0);
	while(exit == 0){
		print(" MENU: \n\r");
		print(" 1 - Introduce first number. \n\r");
		print(" 2 - Introduce second number. \n\r");
		print(" 3 - Add and show on leds . \n\r");
		print(" 4 - Read from switches. \n\r");
		print(" 5 - EXIT \n\r");

		option = getNumber();

		switch(option){
		case 1:
			/*if(XGpio_Initialize(&GpioOutput,XPAR_XPS_GPIO_0_LEDS_DEVICE_ID) == XST_SUCCESS){

			}*/
			XGpio_Initialize(&GPIO_LEDS,XPAR_LEDS_GPIO_DEVICE_ID);
			XGpio_SetDataDirection(&GPIO_LEDS, CHANNEL, OUTPUT);
			XGpio_DiscreteWrite(&GPIO_LEDS, CHANNEL, 0);
			print("Introduce a number from 0 to 9: \n\r");
			opa = getNumber();
			XGpio_Initialize(&GPIO_LEDS,XPAR_LEDS_GPIO_DEVICE_ID);
			XGpio_SetDataDirection(&GPIO_LEDS, CHANNEL, OUTPUT);
			XGpio_DiscreteWrite(&GPIO_LEDS, CHANNEL, opa);
			break;
		case 2:
			XGpio_Initialize(&GPIO_LEDS,XPAR_LEDS_GPIO_DEVICE_ID);
			XGpio_SetDataDirection(&GPIO_LEDS, CHANNEL, OUTPUT);
			XGpio_DiscreteWrite(&GPIO_LEDS, CHANNEL, 0);
			print("Introduce a number from 0 to 9: \n\r");
			opb = getNumber();
			XGpio_Initialize(&GPIO_LEDS,XPAR_LEDS_GPIO_DEVICE_ID);
			XGpio_SetDataDirection(&GPIO_LEDS, CHANNEL, OUTPUT);
			XGpio_DiscreteWrite(&GPIO_LEDS, CHANNEL, opb);
			break;
		case 3:
			resul = opa + opb;
			xil_printf("Your result is: %d\n\r",resul);

			XGpio_Initialize(&GPIO_LEDS, XPAR_LEDS_GPIO_DEVICE_ID);
			XGpio_SetDataDirection(&GPIO_LEDS, CHANNEL, OUTPUT);
			XGpio_DiscreteWrite(&GPIO_LEDS, CHANNEL, resul);
			break;
		case 4:
			//0
			XGpio_Initialize(&GPIO_LEDS, XPAR_LEDS_GPIO_DEVICE_ID);
			XGpio_SetDataDirection(&GPIO_LEDS, CHANNEL, OUTPUT);
			// 1
			XGpio_Initialize(&GPIO_SWITCHES, XPAR_SWITCHES_GPIO_DEVICE_ID);
			XGpio_SetDataDirection(&GPIO_SWITCHES, CHANNEL, INPUT);

			u32 Data = XGpio_DiscreteRead(&GPIO_SWITCHES, XPAR_SWITCHES_GPIO_DEVICE_ID);
			XGpio_DiscreteWrite(&GPIO_LEDS, CHANNEL, Data);
			xil_printf("Data readed from switches: %d\n\r", Data);
			break;
		case 5:
			print("Exit terminal\n\r");
			exit = 1;
			break;
		default:
			print("Wrong number, enter again\n\r");
		}
	}
	print("-- Exiting main() --\n\r");
	return 0;

}






