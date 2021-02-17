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
#include "xgpio.h"
#include "gpio_header.h"
#include "xbasic_types.h"
#include "xbram.h"
#include "bram_header.h"
#include "pantalla.h"

#define pantalla_ 0xCD400000
#define N_FILAS 16
#define ROJO 0x000001c0
#define VERDE 0x00000038
#define VERDE_OSCURO 0x00000018


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

	Xuint32 row,col,position,color,r,g,b,data,exit = 1;
	Xil_ICacheEnable();
	Xil_DCacheEnable();

	print("---Entering main---\n\r");


	while(exit > 0){

		xil_printf("Ingrese 1 para mostrar el menu o 0 para salir \n\r");
		exit = getNumber();
		if(exit == 0){
			exit = 0;
			break;
		}else if(exit == 1){
			xil_printf("Ingrese la fila que quiere cambiar el color (del 1 al 16): \n\r");
			row = getNumber();
			while( row < 1 || row > 16){
				xil_printf("Valor erroneo, verifique fila \n\r");
				row = getNumber();
			}
			row -= 1;

			xil_printf("Ingrese la columna que quiere cambiar el color (del 1 al 8): \n\r");
			col = getNumber();
			while( col < 1 || col > 8){
				xil_printf("Valor erroneo, verifique columna \n\r");
				col = getNumber();
			}
			col -= 1;

			xil_printf("Ingrese la cantidad de rojo que desea (del 0 al 7):\n\r ");
			xil_printf("0 2 4 6 son mas oscuros y 1 3 5 7 son mas claros\n\r ");
			r = getNumber();
			while( r < 0 || r > 9){
				xil_printf("Valor erroneo, verifique color \n\r");
				r = getNumber();
			}

			xil_printf("Ingrese la cantidad de verde que desea (del 0 al 7):\n\r ");
			xil_printf("0 2 4 6 son mas oscuros y 1 3 5 7 son mas claros\n\r ");
			g = getNumber();
			while( g < 0 || g > 9){
				xil_printf("Valor erroneo, verifique color \n\r");
				g = getNumber();
			}

			xil_printf("Ingrese la cantidad de azul que desea (del 0 al 7): \n\r");
			xil_printf("0 2 4 6 son mas oscuros y 1 3 5 7 son mas claros\n\r ");
			b = getNumber();
			while( b < 0 || b > 9){
				xil_printf("Valor erroneo, verifique color \n\r");
				b = getNumber();
			}


			position = col*N_FILAS + row;
			color = color & 0x0; //limpiamos la variable
			color |= r;
			color |= g<<3;
			color |= b<<6;

			data = ((color & 0x1FF) << 23) | (position & 0x7F);

			PANTALLA_mWriteToFIFO(pantalla_,0,data);
		}
	}

   print("---Exiting main---\n\r");

   Xil_DCacheDisable();
   Xil_ICacheDisable();

   return 0;
}

//funcion para testear la intensidad de colores , cambiamos g por r o b
void testColors(){
	int cnt = 0, fin = 16*8,i;
	Xuint32 row,col,position,color,r,g,b,data,exit = 1;
	for( i = 0; i < 999999; i++);

	g=0;
	while(cnt < fin){

		xil_printf("%d\n\r", g);
		position = 0;
		color = color & 0x0; //limpiamos la variable
		color |= g<< 3;

		data = ((color & 0x1FF) << 23) | (position & 0x7F);
		PANTALLA_mWriteToFIFO(pantalla_,0,data);
		cnt++;
		g++;
		if(g == 8) g=0;
		for( i = 0; i < 999999; i++);
	}
}



