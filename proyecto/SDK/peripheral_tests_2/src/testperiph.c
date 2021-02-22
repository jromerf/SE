/*
 *
 * Autor: Javier Romero Flores
 * Asignatura: Sistemas Empotrados
 * Tem�tica: Juego de Tutti frutti/Stop/Alto al l�piz con una cuenta regresiva de 4s
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
#include "banner.h"
#include "frases_compuestas.h"
#include "keypad.h"
#include "caracteres.h"


Xuint32 getOption(Xuint32 baseaddr){
	Xuint32 dato,value;
	value = KEYPAD_mReadReg(baseaddr,0);
	dato = (value>>28) & 0xF;
	KEYPAD_mWriteReg(baseaddr,0,value);
	return dato;
}


int main() 
{

   Xuint32 baseaddr,value,dato,oldValue;

   Xil_ICacheEnable();
   Xil_DCacheEnable();

   print("---Comezamos el juego---\n\r");
   startGame();
   print("---Selecciona el n� de jugadores (max 4)---\n\r");
   print("---                    				  ---\n\r");
   xil_printf("C�mo jugar: \n");
   xil_printf("1- Elige una carta para mostrarte una letra\n");
   xil_printf("2- Menciona el nombre de lo que ves en la pantalla que inicie por dicha letra \n");
   xil_printf("3- Empieza la cuenta atr�s , presiona 0 para detener la cuenta (si llegas a 0 pierdes)\n");
   xil_printf("4- Gana el que m�s puntos tenga\n");


      	baseaddr =  XPAR_KEYPAD_0_BASEADDR;
      	xil_printf("Pulsar una tecla:\n\r");
      	value = KEYPAD_mReadReg(baseaddr,0);
      	xil_printf("se ha leido: %04x el reg \n\r",value);
      	KEYPAD_mWriteReg(baseaddr,0,0);
      	oldValue =  value;


      	xil_printf("Escritura de banner\n\r");
      	BANNER_inicializa();
      	//write_A_DIR(1,TURN_QUIET);
      	mostrarCartasNumeros(TURN_QUIET);

      	cuentaAtras();
      	//varios(baseaddr);
      	//write_winner(XPAR_BANNER_0_BASEADDR);

      	while(1){
      	   if(value != oldValue){
      		   dato = (value>>28) & 0xF;
      		   xil_printf("se ha leido %01x \n\r",dato);
      		   oldValue = value;
      	   }
      	   value = KEYPAD_mReadReg(baseaddr,0);
      	   KEYPAD_mWriteReg(baseaddr,0,value);
      	   xil_printf("Empieza delay\n");
      	   slowDelay();
      	   xil_printf("termina delay\n");
      	}






   
   /*
    * Peripheral SelfTest will not be run for xps_uartlite_0
    * because it has been selected as the STDOUT device
    */


   print("---Exiting main---\n\r");

   Xil_DCacheDisable();
   Xil_ICacheDisable();

   return 0;
}

