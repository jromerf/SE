
/**
 * Author: Javier Romero Flores
 * Description:
 * Llamadas a caracteres m�s comunes en la matriz de 8 displays
 * */

#ifndef CARACTERES_H
#define CARACTERES_H
#include "banner.h"

#define TURN_RIGHT 0x0
#define TURN_LEFT 0x1
#define TURN_QUIET 0x2

void BANNER_enviarcondireccion(Xuint32 col, Xuint32 fil,Xuint32 dato,Xuint32 dir){


	while(BANNER_mWriteFIFOFull(XPAR_BANNER_0_BASEADDR)){}

	Xuint32 data;

	data = ((fil & 0xff)<< (31-7)) + ((col & 0xff) << (31-15)) + ((dato & 0xff)<< (31-23))+ ((dir & 0xff)<<(30));

	//xil_printf("data %08x\n",data);
	BANNER_mWriteToFIFO(XPAR_BANNER_0_BASEADDR,0,data);

}

void BANNER_inicializa(){
	Xuint32 dato,fila,columna,data;
	dato=0x0;
	for(fila = 0; fila < 7; fila++){
			for(columna = 0; columna < 8; columna++){
				data = (( fila & 0xff ) << (31 -7)) +  (( columna & 0xff ) << (31 -15)) + (( dato & 0xff ) << (31 -23));
				//XPAR_BANNER_0_BASEADDR = XPAR_BANNER_0_XPAR_BANNER_0_BASEADDR;
				BANNER_mWriteToFIFO( XPAR_BANNER_0_BASEADDR , 0, data );
			}
	}
}

void BANNER_enviar(Xuint32 col, Xuint32 fil,Xuint32 dato){

	while(BANNER_mWriteFIFOFull(XPAR_BANNER_0_BASEADDR)){}

	Xuint32 data;

	data = ((fil & 0xff)<< (31-7)) + ((col & 0xff) << (31-15)) + ((dato & 0xff)<< (31-23));
	xil_printf("data %08x\n",data);
	BANNER_mWriteToFIFO(XPAR_BANNER_0_BASEADDR,0,data);
}

void write_A_DIR(Xuint32 col,Xuint32 dir){
	BANNER_enviarcondireccion(col,0,0x0E,dir);
	BANNER_enviarcondireccion(col,1,0x11,dir);
	BANNER_enviarcondireccion(col,2,0x11,dir);
	BANNER_enviarcondireccion(col,3,0x1F,dir);
	BANNER_enviarcondireccion(col,4,0x11,dir);
	BANNER_enviarcondireccion(col,5,0x11,dir);
	BANNER_enviarcondireccion(col,6,0x11,dir);
}

void write_A(Xuint32 col){
	BANNER_enviar(col,0,0x0E);
	BANNER_enviar(col,1,0x11);
	BANNER_enviar(col,2,0x11);
	BANNER_enviar(col,3,0x1F);
	BANNER_enviar(col,4,0x11);
	BANNER_enviar(col,5,0x11);
	BANNER_enviar(col,6,0x11);
}

void write_B_DIR(Xuint32 col,Xuint32 dir){
	BANNER_enviarcondireccion(col,0,0x1C,dir);
	BANNER_enviarcondireccion(col,1,0x12,dir);
	BANNER_enviarcondireccion(col,2,0x12,dir);
	BANNER_enviarcondireccion(col,3,0x1E,dir);
	BANNER_enviarcondireccion(col,4,0x11,dir);
	BANNER_enviarcondireccion(col,5,0x11,dir);
	BANNER_enviarcondireccion(col,6,0x1F,dir);
}

void write_B(Xuint32 col){
	BANNER_enviar(col,0,0x1C);
	BANNER_enviar(col,1,0x12);
	BANNER_enviar(col,2,0x12);
	BANNER_enviar(col,3,0x1E);
	BANNER_enviar(col,4,0x11);
	BANNER_enviar(col,5,0x11);
	BANNER_enviar(col,6,0x1F);
}

void write_C_DIR(Xuint32 col,Xuint32 dir){
	BANNER_enviarcondireccion(col,0,0x0E,dir);
	BANNER_enviarcondireccion(col,1,0x11,dir);
	BANNER_enviarcondireccion(col,2,0x10,dir);
	BANNER_enviarcondireccion(col,3,0x10,dir);
	BANNER_enviarcondireccion(col,4,0x10,dir);
	BANNER_enviarcondireccion(col,5,0x11,dir);
	BANNER_enviarcondireccion(col,6,0x0E,dir);
}

void write_C(Xuint32 col){
	BANNER_enviar(col,0,0x0E);
	BANNER_enviar(col,1,0x11);
	BANNER_enviar(col,2,0x10);
	BANNER_enviar(col,3,0x10);
	BANNER_enviar(col,4,0x10);
	BANNER_enviar(col,5,0x11);
	BANNER_enviar(col,6,0x0E);
}

void write_D_DIR(Xuint32 col,Xuint32 dir){
	BANNER_enviarcondireccion(col,0,0x1E,dir);
	BANNER_enviarcondireccion(col,1,0x11,dir);
	BANNER_enviarcondireccion(col,2,0x11,dir);
	BANNER_enviarcondireccion(col,3,0x11,dir);
	BANNER_enviarcondireccion(col,4,0x11,dir);
	BANNER_enviarcondireccion(col,5,0x11,dir);
	BANNER_enviarcondireccion(col,6,0x1E,dir);
}

void write_D(Xuint32 col){
	BANNER_enviar(col,0,0x1E);
	BANNER_enviar(col,1,0x11);
	BANNER_enviar(col,2,0x11);
	BANNER_enviar(col,3,0x11);
	BANNER_enviar(col,4,0x11);
	BANNER_enviar(col,5,0x11);
	BANNER_enviar(col,6,0x1E);
}

void write_E(Xuint32 col){
	BANNER_enviar(col,0,0x1E);
	BANNER_enviar(col,1,0x10);
	BANNER_enviar(col,2,0x10);
	BANNER_enviar(col,3,0x1C);
	BANNER_enviar(col,4,0x10);
	BANNER_enviar(col,5,0x10);
	BANNER_enviar(col,6,0x1E);
}

void write_F(Xuint32 col){
	BANNER_enviar(col,0,0x1F);
	BANNER_enviar(col,1,0x10);
	BANNER_enviar(col,2,0x10);
	BANNER_enviar(col,3,0x1E);
	BANNER_enviar(col,4,0x10);
	BANNER_enviar(col,5,0x10);
	BANNER_enviar(col,6,0x10);
}

void write_G(Xuint32 col){
	BANNER_enviar(col,0,0x0E);
	BANNER_enviar(col,1,0x11);
	BANNER_enviar(col,2,0x10);
	BANNER_enviar(col,3,0x10);
	BANNER_enviar(col,4,0x17);
	BANNER_enviar(col,5,0x11);
	BANNER_enviar(col,6,0x0E);
}

void write_H(Xuint32 col){
	BANNER_enviar(col,0,0x11);
	BANNER_enviar(col,1,0x11);
	BANNER_enviar(col,2,0x11);
	BANNER_enviar(col,3,0x1F);
	BANNER_enviar(col,4,0x11);
	BANNER_enviar(col,5,0x11);
	BANNER_enviar(col,6,0x11);
}

void write_I(Xuint32 col){
	BANNER_enviar(col,0,0x0E);
	BANNER_enviar(col,1,0x04);
	BANNER_enviar(col,2,0x04);
	BANNER_enviar(col,3,0x04);
	BANNER_enviar(col,4,0x04);
	BANNER_enviar(col,5,0x04);
	BANNER_enviar(col,6,0x0E);
}

void write_J(Xuint32 col){
	BANNER_enviar(col,0,0x0F);
	BANNER_enviar(col,1,0x02);
	BANNER_enviar(col,2,0x02);
	BANNER_enviar(col,3,0x02);
	BANNER_enviar(col,4,0x12);
	BANNER_enviar(col,5,0x12);
	BANNER_enviar(col,6,0x0C);
}

void write_K(Xuint32 col){
	BANNER_enviar(col,0,0x11);
	BANNER_enviar(col,1,0x12);
	BANNER_enviar(col,2,0x14);
	BANNER_enviar(col,3,0x18);
	BANNER_enviar(col,4,0x14);
	BANNER_enviar(col,5,0x12);
	BANNER_enviar(col,6,0x11);
}

void write_L(Xuint32 col){
	BANNER_enviar(col,0,0x10);
	BANNER_enviar(col,1,0x10);
	BANNER_enviar(col,2,0x10);
	BANNER_enviar(col,3,0x10);
	BANNER_enviar(col,4,0x10);
	BANNER_enviar(col,5,0x10);
	BANNER_enviar(col,6,0x1E);
}

void write_M(Xuint32 col){
	BANNER_enviar(col,0,0x11);
	BANNER_enviar(col,1,0x1B);
	BANNER_enviar(col,2,0x15);
	BANNER_enviar(col,3,0x11);
	BANNER_enviar(col,4,0x11);
	BANNER_enviar(col,5,0x11);
	BANNER_enviar(col,6,0x11);
}

void write_N(Xuint32 col){
	BANNER_enviar(col,0,0x11);
	BANNER_enviar(col,1,0x11);
	BANNER_enviar(col,2,0x19);
	BANNER_enviar(col,3,0x15);
	BANNER_enviar(col,4,0x13);
	BANNER_enviar(col,5,0x11);
	BANNER_enviar(col,6,0x11);
}
void write_O(Xuint32 col){
	BANNER_enviar(col,0,0x0E);
	BANNER_enviar(col,1,0x11);
	BANNER_enviar(col,2,0x11);
	BANNER_enviar(col,3,0x11);
	BANNER_enviar(col,4,0x11);
	BANNER_enviar(col,5,0x11);
	BANNER_enviar(col,6,0x0E);
}

void write_P(Xuint32 col){
	BANNER_enviar(col,0,0x1E);
	BANNER_enviar(col,1,0x11);
	BANNER_enviar(col,2,0x11);
	BANNER_enviar(col,3,0x1E);
	BANNER_enviar(col,4,0x10);
	BANNER_enviar(col,5,0x10);
	BANNER_enviar(col,6,0x10);
}

void write_Q(Xuint32 col){
	BANNER_enviar(col,0,0x0E);
	BANNER_enviar(col,1,0x11);
	BANNER_enviar(col,2,0x11);
	BANNER_enviar(col,3,0x11);
	BANNER_enviar(col,4,0x15);
	BANNER_enviar(col,5,0x12);
	BANNER_enviar(col,6,0x0D);
}

void write_R(Xuint32 col){
	BANNER_enviar(col,0,0x1E);
	BANNER_enviar(col,1,0x11);
	BANNER_enviar(col,2,0x11);
	BANNER_enviar(col,3,0x1E);
	BANNER_enviar(col,4,0x14);
	BANNER_enviar(col,5,0x12);
	BANNER_enviar(col,6,0x11);
}

void write_S(Xuint32 col){
	BANNER_enviar(col,0,0x0E);
	BANNER_enviar(col,1,0x11);
	BANNER_enviar(col,2,0x10);
	BANNER_enviar(col,3,0x0E);
	BANNER_enviar(col,4,0x01);
	BANNER_enviar(col,5,0x11);
	BANNER_enviar(col,6,0x0E);
}

void write_T(Xuint32 col){
	BANNER_enviar(col,0,0x1F);
	BANNER_enviar(col,1,0x04);
	BANNER_enviar(col,2,0x04);
	BANNER_enviar(col,3,0x04);
	BANNER_enviar(col,4,0x04);
	BANNER_enviar(col,5,0x04);
	BANNER_enviar(col,6,0x04);
}

void write_U(Xuint32 col){
	BANNER_enviar(col,0,0x11);
	BANNER_enviar(col,1,0x11);
	BANNER_enviar(col,2,0x11);
	BANNER_enviar(col,3,0x11);
	BANNER_enviar(col,4,0x11);
	BANNER_enviar(col,5,0x11);
	BANNER_enviar(col,6,0x0E);
}

void write_V(Xuint32 col){
	BANNER_enviar(col,0,0x11);
	BANNER_enviar(col,1,0x11);
	BANNER_enviar(col,2,0x11);
	BANNER_enviar(col,3,0x11);
	BANNER_enviar(col,4,0x11);
	BANNER_enviar(col,5,0x0A);
	BANNER_enviar(col,6,0x04);
}

void write_W(Xuint32 col){
	BANNER_enviar(col,0,0x11);
	BANNER_enviar(col,1,0x11);
	BANNER_enviar(col,2,0x11);
	BANNER_enviar(col,3,0x11);
	BANNER_enviar(col,4,0x15);
	BANNER_enviar(col,5,0x1B);
	BANNER_enviar(col,6,0x11);
}

void write_X(Xuint32 col){
	BANNER_enviar(col,0,0x11);
	BANNER_enviar(col,1,0x11);
	BANNER_enviar(col,2,0x0A);
	BANNER_enviar(col,3,0x04);
	BANNER_enviar(col,4,0x0A);
	BANNER_enviar(col,5,0x11);
	BANNER_enviar(col,6,0x11);
}

void write_Y(Xuint32 col){
	BANNER_enviar(col,0,0x11);
	BANNER_enviar(col,1,0x11);
	BANNER_enviar(col,2,0x0A);
	BANNER_enviar(col,3,0x04);
	BANNER_enviar(col,4,0x04);
	BANNER_enviar(col,5,0x04);
	BANNER_enviar(col,6,0x04);
}

void write_Z(Xuint32 col){
	BANNER_enviar(col,0,0x1F);
	BANNER_enviar(col,1,0x01);
	BANNER_enviar(col,2,0x02);
	BANNER_enviar(col,3,0x04);
	BANNER_enviar(col,4,0x08);
	BANNER_enviar(col,5,0x10);
	BANNER_enviar(col,6,0x1F);
}

/********************************************************************************************/
/**************************          NUMEROS                              *******************/
/********************************************************************************************/

void write_0(Xuint32 col){
	BANNER_enviar(col,0,0x1E);
	BANNER_enviar(col,1,0x11);
	BANNER_enviar(col,2,0x13);
	BANNER_enviar(col,3,0x15);
	BANNER_enviar(col,4,0x19);
	BANNER_enviar(col,5,0x11);
	BANNER_enviar(col,6,0x0E);
}

void write_1_DIR(Xuint32 col,Xuint32 dir){
	BANNER_enviarcondireccion(col,0,0x04,dir);
	BANNER_enviarcondireccion(col,1,0x0C,dir);
	BANNER_enviarcondireccion(col,2,0x04,dir);
	BANNER_enviarcondireccion(col,3,0x04,dir);
	BANNER_enviarcondireccion(col,4,0x04,dir);
	BANNER_enviarcondireccion(col,5,0x04,dir);
	BANNER_enviarcondireccion(col,6,0x0E,dir);
}

void write_1(Xuint32 col){
	BANNER_enviar(col,0,0x04);
	BANNER_enviar(col,1,0x0C);
	BANNER_enviar(col,2,0x04);
	BANNER_enviar(col,3,0x04);
	BANNER_enviar(col,4,0x04);
	BANNER_enviar(col,5,0x04);
	BANNER_enviar(col,6,0x0E);
}

void write_2_DIR(Xuint32 col,Xuint32 dir){
	BANNER_enviarcondireccion(col,0,0x0E,dir);
	BANNER_enviarcondireccion(col,1,0x11,dir);
	BANNER_enviarcondireccion(col,2,0x01,dir);
	BANNER_enviarcondireccion(col,3,0x02,dir);
	BANNER_enviarcondireccion(col,4,0x04,dir);
	BANNER_enviarcondireccion(col,5,0x08,dir);
	BANNER_enviarcondireccion(col,6,0x1F,dir);
}

void write_2(Xuint32 col){
	BANNER_enviar(col,0,0x0E);
	BANNER_enviar(col,1,0x11);
	BANNER_enviar(col,2,0x01);
	BANNER_enviar(col,3,0x02);
	BANNER_enviar(col,4,0x04);
	BANNER_enviar(col,5,0x08);
	BANNER_enviar(col,6,0x1F);
}

void write_3_DIR(Xuint32 col,Xuint32 dir){
	BANNER_enviarcondireccion(col,0,0x0E,dir);
	BANNER_enviarcondireccion(col,1,0x11,dir);
	BANNER_enviarcondireccion(col,2,0x01,dir);
	BANNER_enviarcondireccion(col,3,0x0E,dir);
	BANNER_enviarcondireccion(col,4,0x01,dir);
	BANNER_enviarcondireccion(col,5,0x11,dir);
	BANNER_enviarcondireccion(col,6,0x0E,dir);
}

void write_3(Xuint32 col){
	BANNER_enviar(col,0,0x0E);
	BANNER_enviar(col,1,0x11);
	BANNER_enviar(col,2,0x01);
	BANNER_enviar(col,3,0x0E);
	BANNER_enviar(col,4,0x01);
	BANNER_enviar(col,5,0x11);
	BANNER_enviar(col,6,0x0E);
}

void write_4_DIR(Xuint32 col,Xuint32 dir){
	BANNER_enviarcondireccion(col,0,0x02,dir);
	BANNER_enviarcondireccion(col,1,0x06,dir);
	BANNER_enviarcondireccion(col,2,0x0A,dir);
	BANNER_enviarcondireccion(col,3,0x12,dir);
	BANNER_enviarcondireccion(col,4,0x1F,dir);
	BANNER_enviarcondireccion(col,5,0x02,dir);
	BANNER_enviarcondireccion(col,6,0x02,dir);
}

void write_4(Xuint32 col){
	BANNER_enviar(col,0,0x02);
	BANNER_enviar(col,1,0x06);
	BANNER_enviar(col,2,0x0A);
	BANNER_enviar(col,3,0x12);
	BANNER_enviar(col,4,0x1F);
	BANNER_enviar(col,5,0x02);
	BANNER_enviar(col,6,0x02);
}

void write_5(Xuint32 col){
	BANNER_enviar(col,0,0x1F);
	BANNER_enviar(col,1,0x10);
	BANNER_enviar(col,2,0x1E);
	BANNER_enviar(col,3,0x01);
	BANNER_enviar(col,4,0x01);
	BANNER_enviar(col,5,0x11);
	BANNER_enviar(col,6,0x0E);
}

void write_6(Xuint32 col){
	BANNER_enviar(col,0,0x06);
	BANNER_enviar(col,1,0x08);
	BANNER_enviar(col,2,0x10);
	BANNER_enviar(col,3,0x1E);
	BANNER_enviar(col,4,0x11);
	BANNER_enviar(col,5,0x11);
	BANNER_enviar(col,6,0x0E);
}

void write_7(Xuint32 col){
	BANNER_enviar(col,0,0x1F);
	BANNER_enviar(col,1,0x01);
	BANNER_enviar(col,2,0x02);
	BANNER_enviar(col,3,0x04);
	BANNER_enviar(col,4,0x08);
	BANNER_enviar(col,5,0x08);
	BANNER_enviar(col,6,0x08);
}

void write_8(Xuint32 col){
	BANNER_enviar(col,0,0x0E);
	BANNER_enviar(col,1,0x11);
	BANNER_enviar(col,2,0x11);
	BANNER_enviar(col,3,0x0E);
	BANNER_enviar(col,4,0x11);
	BANNER_enviar(col,5,0x11);
	BANNER_enviar(col,6,0x0E);
}

void write_9(Xuint32 col){
	BANNER_enviar(col,0,0x0E);
	BANNER_enviar(col,1,0x11);
	BANNER_enviar(col,2,0x11);
	BANNER_enviar(col,3,0x0F);
	BANNER_enviar(col,4,0x01);
	BANNER_enviar(col,5,0x02);
	BANNER_enviar(col,6,0x0C);
}

/********************************************************************************************/
/**************************         CARACTERES VARIOS                     *******************/
/********************************************************************************************/

void write_exclamacion(Xuint32 col){
	BANNER_enviar(col,0,0x06);
	BANNER_enviar(col,1,0x06);
	BANNER_enviar(col,2,0x06);
	BANNER_enviar(col,3,0x06);
	BANNER_enviar(col,4,0x06);
	BANNER_enviar(col,5,0x00);
	BANNER_enviar(col,6,0x06);
}

void write_espacio(Xuint32 col){
	BANNER_enviar(col,0,0x00);
	BANNER_enviar(col,1,0x00);
	BANNER_enviar(col,2,0x00);
	BANNER_enviar(col,3,0x00);
	BANNER_enviar(col,4,0x00);
	BANNER_enviar(col,5,0x00);
	BANNER_enviar(col,6,0x00);
}

void write_smile(Xuint32 col){
	BANNER_enviar(col,0,0x00);
	BANNER_enviar(col,1,0x00);
	BANNER_enviar(col,2,0x0A);
	BANNER_enviar(col,3,0x00);
	BANNER_enviar(col,4,0x11);
	BANNER_enviar(col,5,0x0E);
	BANNER_enviar(col,6,0x00);
}

void write_sad(Xuint32 col){
	BANNER_enviar(col,0,0x00);
	BANNER_enviar(col,1,0x00);
	BANNER_enviar(col,2,0x0A);
	BANNER_enviar(col,3,0x00);
	BANNER_enviar(col,4,0x0E);
	BANNER_enviar(col,5,0x11);
	BANNER_enviar(col,6,0x00);
}

void write_diamante(Xuint32 col){
	BANNER_enviar(col,0,0x00);
	BANNER_enviar(col,1,0x00);
	BANNER_enviar(col,2,0x04);
	BANNER_enviar(col,3,0x0A);
	BANNER_enviar(col,4,0x04);
	BANNER_enviar(col,5,0x00);
	BANNER_enviar(col,6,0x00);
}

void write_diamante_DIR(Xuint32 col,Xuint32 dir){
	BANNER_enviarcondireccion(col,0,0x00,dir);
	BANNER_enviarcondireccion(col,1,0x00,dir);
	BANNER_enviarcondireccion(col,2,0x04,dir);
	BANNER_enviarcondireccion(col,3,0x0A,dir);
	BANNER_enviarcondireccion(col,4,0x04,dir);
	BANNER_enviarcondireccion(col,5,0x00,dir);
	BANNER_enviarcondireccion(col,6,0x00,dir);
}

#endif /** CARACTERES_H */
