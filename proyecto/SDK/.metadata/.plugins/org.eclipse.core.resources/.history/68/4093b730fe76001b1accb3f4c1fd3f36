
/**
 * Author: Javier Romero Flores
 * Description:
 * Llamadas a caracteres más comunes en la matriz de 8 displays
 * */

#ifndef CARACTERES_H
#define CARACTERES_H
#include "banner.h"

#define TURN_RIGHT 0x0
#define TURN_LEFT 0x1
#define TURN_QUIET 0x2

const int A[7] = {0x0E,0x11,0x11,0x1F,0x11,0x11,0x11};
const int B[7] = {0x1C,0x12,0x12,0x1E,0x11,0x11,0x1F};
const int C[7] = {0x0E,0x11,0x10,0x10,0x10,0x11,0x0E};
const int D[7] = {0x1E,0x11,0x11,0x11,0x11,0x11,0x1E};
const int E[7] = {0x1E,0x10,0x10,0x1C,0x10,0x10,0x1E};
const int F[7] = {0x1F,0x10,0x10,0x1E,0x10,0x10,0x10};
const int G[7] = {0x0E,0x11,0x10,0x10,0x17,0x11,0x0E};
const int H[7] = {0x11,0x11,0x11,0x1F,0x11,0x11,0x11};
const int I[7] = {0x0E,0x04,0x04,0x04,0x04,0x04,0x0E};
const int J[7] = {0x0F,0x02,0x02,0x02,0x12,0x12,0x0C};
const int K[7] = {0x11,0x12,0x14,0x18,0x14,0x12,0x11};
const int L[7] = {0x10,0x10,0x10,0x10,0x10,0x10,0x1E};
const int M[7] = {0x11,0x1B,0x15,0x11,0x11,0x11,0x11};
const int N[7] = {0x11,0x11,0x19,0x15,0x13,0x11,0x11};
const int O[7] = {0x0E,0x11,0x11,0x11,0x11,0x11,0x0E};
const int P[7] = {0x1E,0x11,0x11,0x1E,0x10,0x10,0x10};
const int Q[7] = {0x0E,0x11,0x11,0x11,0x15,0x12,0x0D};
const int R[7] = {0x1E,0x11,0x11,0x1E,0x14,0x12,0x11};
const int S[7] = {0x0E,0x11,0x10,0x0E,0x01,0x11,0x0E};
const int T[7] = {0x1F,0x04,0x04,0x04,0x04,0x04,0x04};
const int U[7] = {0x11,0x11,0x11,0x11,0x11,0x11,0x0E};
const int V[7] = {0x11,0x11,0x11,0x11,0x11,0x0A,0x04};
const int W[7] = {0x11,0x11,0x11,0x11,0x15,0x1B,0x11};
const int X[7] = {0x11,0x11,0x0A,0x04,0x0A,0x11,0x11};
const int Y[7] = {0x11,0x11,0x0A,0x04,0x04,0x04,0x04};
const int Z[7] = {0x1F,0x01,0x02,0x04,0x08,0x10,0x1F};

const int cero[7] = {0x0E,0x11,0x13,0x15,0x19,0x11,0x0E};
const int uno[7] = {0x04,0x0C,0x04,0x04,0x04,0x04,0x0E};
const int dos[7] = {0x0E,0x11,0x01,0x02,0x04,0x08,0x1F};
const int tres[7] = {0x1F,0x02,0x04,0x02,0x01,0x11,0x0E};
const int cuatro[7] = {0x02,0x06,0x0A,0x12,0x1F,0x02,0x02};
const int cinco[7] = {0x1F,0x10,0x1E,0x01,0x01,0x11,0x0E};
const int seis[7] = {0x06,0x08,0x10,0x1E,0x11,0x11,0x0E};
const int siete[7] = {0x1F,0x01,0x02,0x04,0x08,0x08,0x08};
const int ocho[7] = {0x0E,0x11,0x11,0x0E,0x11,0x11,0x0E};
const int nueve[7] = {0x0E,0x11,0x11,0x0F,0x01,0x02,0x0C};

const int diamante[7] = {0x00,0x00,0x04,0x0A,0x04,0x00,0x00};
const int sad[7] = {0x00,0x00,0x0A,0x00,0x0E,0x11,0x00};
const int smile[7] = {0x00,0x00,0x0A,0x00,0x0E,0x11,0x00};

int i;


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
	for(i = 0; i < 7; i++)
		BANNER_enviarcondireccion(col,i,A[i],dir);
	/*BANNER_enviarcondireccion(col,0,0x0E,dir);
	BANNER_enviarcondireccion(col,1,0x11,dir);
	BANNER_enviarcondireccion(col,2,0x11,dir);
	BANNER_enviarcondireccion(col,3,0x1F,dir);
	BANNER_enviarcondireccion(col,4,0x11,dir);
	BANNER_enviarcondireccion(col,5,0x11,dir);
	BANNER_enviarcondireccion(col,6,0x11,dir);*/
}

void write_B_DIR(Xuint32 col,Xuint32 dir){
	for(i = 0; i < 7; i++)
		BANNER_enviarcondireccion(col,i,B[i],dir);
	/*
	BANNER_enviarcondireccion(col,0,0x1C,dir);
	BANNER_enviarcondireccion(col,1,0x12,dir);
	BANNER_enviarcondireccion(col,2,0x12,dir);
	BANNER_enviarcondireccion(col,3,0x1E,dir);
	BANNER_enviarcondireccion(col,4,0x11,dir);
	BANNER_enviarcondireccion(col,5,0x11,dir);
	BANNER_enviarcondireccion(col,6,0x1F,dir);*/
}

void write_C_DIR(Xuint32 col,Xuint32 dir){
	for(i = 0; i < 7; i++)
		BANNER_enviarcondireccion(col,i,C[i],dir);
	/*
	BANNER_enviarcondireccion(col,0,0x0E,dir);
	BANNER_enviarcondireccion(col,1,0x11,dir);
	BANNER_enviarcondireccion(col,2,0x10,dir);
	BANNER_enviarcondireccion(col,3,0x10,dir);
	BANNER_enviarcondireccion(col,4,0x10,dir);
	BANNER_enviarcondireccion(col,5,0x11,dir);
	BANNER_enviarcondireccion(col,6,0x0E,dir);*/
}

void write_D_DIR(Xuint32 col,Xuint32 dir){
	for(i = 0; i < 7; i++)
		BANNER_enviarcondireccion(col,i,D[i],dir);
	/*
	BANNER_enviarcondireccion(col,0,0x1E,dir);
	BANNER_enviarcondireccion(col,1,0x11,dir);
	BANNER_enviarcondireccion(col,2,0x11,dir);
	BANNER_enviarcondireccion(col,3,0x11,dir);
	BANNER_enviarcondireccion(col,4,0x11,dir);
	BANNER_enviarcondireccion(col,5,0x11,dir);
	BANNER_enviarcondireccion(col,6,0x1E,dir);*/
}

void write_E_DIR(Xuint32 col,Xuint32 dir){
	for(i = 0; i < 7; i++)
		BANNER_enviarcondireccion(col,i,E[i],dir);
	/*
	BANNER_enviarcondireccion(col,0,0x1E,dir);
	BANNER_enviarcondireccion(col,1,0x10,dir);
	BANNER_enviarcondireccion(col,2,0x10,dir);
	BANNER_enviarcondireccion(col,3,0x1C,dir);
	BANNER_enviarcondireccion(col,4,0x10,dir);
	BANNER_enviarcondireccion(col,5,0x10,dir);
	BANNER_enviarcondireccion(col,6,0x1E,dir);*/
}

void write_F_DIR(Xuint32 col,Xuint32 dir){
	for(i = 0; i < 7; i++)
		BANNER_enviarcondireccion(col,i,F[i],dir);
	/*
	BANNER_enviarcondireccion(col,0,0x1F,dir);
	BANNER_enviarcondireccion(col,1,0x10,dir);
	BANNER_enviarcondireccion(col,2,0x10,dir);
	BANNER_enviarcondireccion(col,3,0x1E,dir);
	BANNER_enviarcondireccion(col,4,0x10,dir);
	BANNER_enviarcondireccion(col,5,0x10,dir);
	BANNER_enviarcondireccion(col,6,0x10,dir);*/
}

void write_G_DIR(Xuint32 col,Xuint32 dir){
	for(i = 0; i < 7; i++)
		BANNER_enviarcondireccion(col,i,G[i],dir);
	/*
	BANNER_enviarcondireccion(col,0,0x0E,dir);
	BANNER_enviarcondireccion(col,1,0x11,dir);
	BANNER_enviarcondireccion(col,2,0x10,dir);
	BANNER_enviarcondireccion(col,3,0x10,dir);
	BANNER_enviarcondireccion(col,4,0x17,dir);
	BANNER_enviarcondireccion(col,5,0x11,dir);
	BANNER_enviarcondireccion(col,6,0x0E,dir);*/
}

void write_H_DIR(Xuint32 col,Xuint32 dir){
	for(i = 0; i < 7; i++)
		BANNER_enviarcondireccion(col,i,H[i],dir);
	/*
	BANNER_enviarcondireccion(col,0,0x11,dir);
	BANNER_enviarcondireccion(col,1,0x11,dir);
	BANNER_enviarcondireccion(col,2,0x11,dir);
	BANNER_enviarcondireccion(col,3,0x1F,dir);
	BANNER_enviarcondireccion(col,4,0x11,dir);
	BANNER_enviarcondireccion(col,5,0x11,dir);
	BANNER_enviarcondireccion(col,6,0x11,dir);*/
}

void write_I_DIR(Xuint32 col,Xuint32 dir){
	for(i = 0; i < 7; i++)
		BANNER_enviarcondireccion(col,i,I[i],dir);
	/*
	BANNER_enviarcondireccion(col,0,0x0E,dir);
	BANNER_enviarcondireccion(col,1,0x04,dir);
	BANNER_enviarcondireccion(col,2,0x04,dir);
	BANNER_enviarcondireccion(col,3,0x04,dir);
	BANNER_enviarcondireccion(col,4,0x04,dir);
	BANNER_enviarcondireccion(col,5,0x04,dir);
	BANNER_enviarcondireccion(col,6,0x0E,dir);*/
}

void write_J_DIR(Xuint32 col,Xuint32 dir){
	for(i = 0; i < 7; i++)
		BANNER_enviarcondireccion(col,i,J[i],dir);
	/*
	BANNER_enviarcondireccion(col,0,0x0F,dir);
	BANNER_enviarcondireccion(col,1,0x02,dir);
	BANNER_enviarcondireccion(col,2,0x02,dir);
	BANNER_enviarcondireccion(col,3,0x02,dir);
	BANNER_enviarcondireccion(col,4,0x12,dir);
	BANNER_enviarcondireccion(col,5,0x12,dir);
	BANNER_enviarcondireccion(col,6,0x0C,dir);*/
}

void write_K_DIR(Xuint32 col,Xuint32 dir){
	for(i = 0; i < 7; i++)
		BANNER_enviarcondireccion(col,i,K[i],dir);
	/*
	BANNER_enviarcondireccion(col,0,0x11,dir);
	BANNER_enviarcondireccion(col,1,0x12,dir);
	BANNER_enviarcondireccion(col,2,0x14,dir);
	BANNER_enviarcondireccion(col,3,0x18,dir);
	BANNER_enviarcondireccion(col,4,0x14,dir);
	BANNER_enviarcondireccion(col,5,0x12,dir);
	BANNER_enviarcondireccion(col,6,0x11,dir);
	*/
}

void write_L_DIR(Xuint32 col,Xuint32 dir){
	for(i = 0; i < 7; i++)
		BANNER_enviarcondireccion(col,i,L[i],dir);
	/*
	BANNER_enviarcondireccion(col,0,0x10,dir);
	BANNER_enviarcondireccion(col,1,0x10,dir);
	BANNER_enviarcondireccion(col,2,0x10,dir);
	BANNER_enviarcondireccion(col,3,0x10,dir);
	BANNER_enviarcondireccion(col,4,0x10,dir);
	BANNER_enviarcondireccion(col,5,0x10,dir);
	BANNER_enviarcondireccion(col,6,0x1E,dir);*/
}

void write_M_DIR(Xuint32 col,Xuint32 dir){
	for(i = 0; i < 7; i++)
		BANNER_enviarcondireccion(col,i,M[i],dir);
	/*
	BANNER_enviarcondireccion(col,0,0x11,dir);
	BANNER_enviarcondireccion(col,1,0x1B,dir);
	BANNER_enviarcondireccion(col,2,0x15,dir);
	BANNER_enviarcondireccion(col,3,0x11,dir);
	BANNER_enviarcondireccion(col,4,0x11,dir);
	BANNER_enviarcondireccion(col,5,0x11,dir);
	BANNER_enviarcondireccion(col,6,0x11,dir);*/
}

void write_N_DIR(Xuint32 col,Xuint32 dir){
	for(i = 0; i < 7; i++)
		BANNER_enviarcondireccion(col,i,N[i],dir);
	/*
	BANNER_enviarcondireccion(col,0,0x11,dir);
	BANNER_enviarcondireccion(col,1,0x11,dir);
	BANNER_enviarcondireccion(col,2,0x19,dir);
	BANNER_enviarcondireccion(col,3,0x15,dir);
	BANNER_enviarcondireccion(col,4,0x13,dir);
	BANNER_enviarcondireccion(col,5,0x11,dir);
	BANNER_enviarcondireccion(col,6,0x11,dir);*/
}
void write_O_DIR(Xuint32 col,Xuint32 dir){
	for(i = 0; i < 7; i++)
		BANNER_enviarcondireccion(col,i,O[i],dir);
	/*
	BANNER_enviarcondireccion(col,0,0x0E,dir);
	BANNER_enviarcondireccion(col,1,0x11,dir);
	BANNER_enviarcondireccion(col,2,0x11,dir);
	BANNER_enviarcondireccion(col,3,0x11,dir);
	BANNER_enviarcondireccion(col,4,0x11,dir);
	BANNER_enviarcondireccion(col,5,0x11,dir);
	BANNER_enviarcondireccion(col,6,0x0E,dir);*/
}

void write_P_DIR(Xuint32 col,Xuint32 dir){
	for(i = 0; i < 7; i++)
		BANNER_enviarcondireccion(col,i,P[i],dir);
	/*
	BANNER_enviarcondireccion(col,0,0x1E,dir);
	BANNER_enviarcondireccion(col,1,0x11,dir);
	BANNER_enviarcondireccion(col,2,0x11,dir);
	BANNER_enviarcondireccion(col,3,0x1E,dir);
	BANNER_enviarcondireccion(col,4,0x10,dir);
	BANNER_enviarcondireccion(col,5,0x10,dir);
	BANNER_enviarcondireccion(col,6,0x10,dir);*/
}

void write_Q_DIR(Xuint32 col,Xuint32 dir){
	for(i = 0; i < 7; i++)
		BANNER_enviarcondireccion(col,i,Q[i],dir);
	/*
	BANNER_enviarcondireccion(col,0,0x0E,dir);
	BANNER_enviarcondireccion(col,1,0x11,dir);
	BANNER_enviarcondireccion(col,2,0x11,dir);
	BANNER_enviarcondireccion(col,3,0x11,dir);
	BANNER_enviarcondireccion(col,4,0x15,dir);
	BANNER_enviarcondireccion(col,5,0x12,dir);
	BANNER_enviarcondireccion(col,6,0x0D,dir);*/
}

void write_R_DIR(Xuint32 col,Xuint32 dir){
	for(i = 0; i < 7; i++)
		BANNER_enviarcondireccion(col,i,R[i],dir);
	/*
	BANNER_enviarcondireccion(col,0,0x1E,dir);
	BANNER_enviarcondireccion(col,1,0x11,dir);
	BANNER_enviarcondireccion(col,2,0x11,dir);
	BANNER_enviarcondireccion(col,3,0x1E,dir);
	BANNER_enviarcondireccion(col,4,0x14,dir);
	BANNER_enviarcondireccion(col,5,0x12,dir);
	BANNER_enviarcondireccion(col,6,0x11,dir);*/
}

void write_S_DIR(Xuint32 col,Xuint32 dir){
	for(i = 0; i < 7; i++)
		BANNER_enviarcondireccion(col,i,S[i],dir);
	/*
	BANNER_enviarcondireccion(col,0,0x0E,dir);
	BANNER_enviarcondireccion(col,1,0x11,dir);
	BANNER_enviarcondireccion(col,2,0x10,dir);
	BANNER_enviarcondireccion(col,3,0x0E,dir);
	BANNER_enviarcondireccion(col,4,0x01,dir);
	BANNER_enviarcondireccion(col,5,0x11,dir);
	BANNER_enviarcondireccion(col,6,0x0E,dir);*/
}

void write_T_DIR(Xuint32 col,Xuint32 dir){
	for(i = 0; i < 7; i++)
		BANNER_enviarcondireccion(col,i,T[i],dir);
	/*
	BANNER_enviarcondireccion(col,0,0x1F,dir);
	BANNER_enviarcondireccion(col,1,0x04,dir);
	BANNER_enviarcondireccion(col,2,0x04,dir);
	BANNER_enviarcondireccion(col,3,0x04,dir);
	BANNER_enviarcondireccion(col,4,0x04,dir);
	BANNER_enviarcondireccion(col,5,0x04,dir);
	BANNER_enviarcondireccion(col,6,0x04,dir);*/
}

void write_U_DIR(Xuint32 col,Xuint32 dir){
	for(i = 0; i < 7; i++)
		BANNER_enviarcondireccion(col,i,U[i],dir);
	/*
	BANNER_enviarcondireccion(col,0,0x11,dir);
	BANNER_enviarcondireccion(col,1,0x11,dir);
	BANNER_enviarcondireccion(col,2,0x11,dir);
	BANNER_enviarcondireccion(col,3,0x11,dir);
	BANNER_enviarcondireccion(col,4,0x11,dir);
	BANNER_enviarcondireccion(col,5,0x11,dir);
	BANNER_enviarcondireccion(col,6,0x0E,dir);*/
}

void write_V_DIR(Xuint32 col,Xuint32 dir){
	for(i = 0; i < 7; i++)
		BANNER_enviarcondireccion(col,i,V[i],dir);
	/*
	BANNER_enviarcondireccion(col,0,0x11,dir);
	BANNER_enviarcondireccion(col,1,0x11,dir);
	BANNER_enviarcondireccion(col,2,0x11,dir);
	BANNER_enviarcondireccion(col,3,0x11,dir);
	BANNER_enviarcondireccion(col,4,0x11,dir);
	BANNER_enviarcondireccion(col,5,0x0A,dir);
	BANNER_enviarcondireccion(col,6,0x04,dir);*/
}

void write_W_DIR(Xuint32 col,Xuint32 dir){
	for(i = 0; i < 7; i++)
		BANNER_enviarcondireccion(col,i,W[i],dir);
	/*
	BANNER_enviarcondireccion(col,0,0x11,dir);
	BANNER_enviarcondireccion(col,1,0x11,dir);
	BANNER_enviarcondireccion(col,2,0x11,dir);
	BANNER_enviarcondireccion(col,3,0x11,dir);
	BANNER_enviarcondireccion(col,4,0x15,dir);
	BANNER_enviarcondireccion(col,5,0x1B,dir);
	BANNER_enviarcondireccion(col,6,0x11,dir);*/
}

void write_X_DIR(Xuint32 col,Xuint32 dir){
	for(i = 0; i < 7; i++)
		BANNER_enviarcondireccion(col,i,X[i],dir);
	/*
	BANNER_enviarcondireccion(col,0,0x11,dir);
	BANNER_enviarcondireccion(col,1,0x11,dir);
	BANNER_enviarcondireccion(col,2,0x0A,dir);
	BANNER_enviarcondireccion(col,3,0x04,dir);
	BANNER_enviarcondireccion(col,4,0x0A,dir);
	BANNER_enviarcondireccion(col,5,0x11,dir);
	BANNER_enviarcondireccion(col,6,0x11,dir);*/
}

void write_Y_DIR(Xuint32 col,Xuint32 dir){
	for(i = 0; i < 7; i++)
		BANNER_enviarcondireccion(col,i,Y[i],dir);
	/*
	BANNER_enviarcondireccion(col,0,0x11,dir);
	BANNER_enviarcondireccion(col,1,0x11,dir);
	BANNER_enviarcondireccion(col,2,0x0A,dir);
	BANNER_enviarcondireccion(col,3,0x04,dir);
	BANNER_enviarcondireccion(col,4,0x04,dir);
	BANNER_enviarcondireccion(col,5,0x04,dir);
	BANNER_enviarcondireccion(col,6,0x04,dir);*/
}

void write_Z_DIR(Xuint32 col,Xuint32 dir){
	for(i = 0; i < 7; i++)
		BANNER_enviarcondireccion(col,i,Z[i],dir);
	/*
	BANNER_enviarcondireccion(col,0,0x1F,dir);
	BANNER_enviarcondireccion(col,1,0x01,dir);
	BANNER_enviarcondireccion(col,2,0x02,dir);
	BANNER_enviarcondireccion(col,3,0x04,dir);
	BANNER_enviarcondireccion(col,4,0x08,dir);
	BANNER_enviarcondireccion(col,5,0x10,dir);
	BANNER_enviarcondireccion(col,6,0x1F,dir);*/
}



/********************************************************************************************/
/**************************          NUMEROS                              *******************/
/********************************************************************************************/

void write_0_DIR(Xuint32 col,Xuint32 dir){
	for(i = 0; i < 7; i++)
		BANNER_enviarcondireccion(col,i,cero[i],dir);
	/*
	BANNER_enviar(col,0,0x1E);
	BANNER_enviar(col,1,0x11);
	BANNER_enviar(col,2,0x13);
	BANNER_enviar(col,3,0x15);
	BANNER_enviar(col,4,0x19);
	BANNER_enviar(col,5,0x11);
	BANNER_enviar(col,6,0x0E);*/
}

void write_1_DIR(Xuint32 col,Xuint32 dir){
	for(i = 0; i < 7; i++)
		BANNER_enviarcondireccion(col,i,uno[i],dir);
/*
	BANNER_enviarcondireccion(col,0,0x04,dir);
	BANNER_enviarcondireccion(col,1,0x0C,dir);
	BANNER_enviarcondireccion(col,2,0x04,dir);
	BANNER_enviarcondireccion(col,3,0x04,dir);
	BANNER_enviarcondireccion(col,4,0x04,dir);
	BANNER_enviarcondireccion(col,5,0x04,dir);
	BANNER_enviarcondireccion(col,6,0x0E,dir);*/
}

void write_2_DIR(Xuint32 col,Xuint32 dir){
	for(i = 0; i < 7; i++)
		BANNER_enviarcondireccion(col,i,dos[i],dir);
/*
	BANNER_enviarcondireccion(col,0,0x0E,dir);
	BANNER_enviarcondireccion(col,1,0x11,dir);
	BANNER_enviarcondireccion(col,2,0x01,dir);
	BANNER_enviarcondireccion(col,3,0x02,dir);
	BANNER_enviarcondireccion(col,4,0x04,dir);
	BANNER_enviarcondireccion(col,5,0x08,dir);
	BANNER_enviarcondireccion(col,6,0x1F,dir);*/
}

void write_3_DIR(Xuint32 col,Xuint32 dir){
	for(i = 0; i < 7; i++)
		BANNER_enviarcondireccion(col,i,tres[i],dir);
/*
	BANNER_enviarcondireccion(col,0,0x0E,dir);
	BANNER_enviarcondireccion(col,1,0x11,dir);
	BANNER_enviarcondireccion(col,2,0x01,dir);
	BANNER_enviarcondireccion(col,3,0x0E,dir);
	BANNER_enviarcondireccion(col,4,0x01,dir);
	BANNER_enviarcondireccion(col,5,0x11,dir);
	BANNER_enviarcondireccion(col,6,0x0E,dir);*/
}


void write_4_DIR(Xuint32 col,Xuint32 dir){
	for(i = 0; i < 7; i++)
		BANNER_enviarcondireccion(col,i,cuatro[i],dir);
/*
	BANNER_enviarcondireccion(col,0,0x02,dir);
	BANNER_enviarcondireccion(col,1,0x06,dir);
	BANNER_enviarcondireccion(col,2,0x0A,dir);
	BANNER_enviarcondireccion(col,3,0x12,dir);
	BANNER_enviarcondireccion(col,4,0x1F,dir);
	BANNER_enviarcondireccion(col,5,0x02,dir);
	BANNER_enviarcondireccion(col,6,0x02,dir);*/
}
/*
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
*/
/********************************************************************************************/
/**************************         CARACTERES VARIOS                     *******************/
/********************************************************************************************/

/*
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
*/

void write_smile(Xuint32 col){
	for(i = 0; i < 7; i++)
		BANNER_enviar(col,i,smile[i]);
	/*
	BANNER_enviar(col,0,0x00);
	BANNER_enviar(col,1,0x00);
	BANNER_enviar(col,2,0x0A);
	BANNER_enviar(col,3,0x00);
	BANNER_enviar(col,4,0x11);
	BANNER_enviar(col,5,0x0E);
	BANNER_enviar(col,6,0x00);*/
}

void write_sad(Xuint32 col){
	for(i = 0; i < 7; i++)
		BANNER_enviar(col,i,sad[i]);
	/*
	BANNER_enviar(col,0,0x00);
	BANNER_enviar(col,1,0x00);
	BANNER_enviar(col,2,0x0A);
	BANNER_enviar(col,3,0x00);
	BANNER_enviar(col,4,0x0E);
	BANNER_enviar(col,5,0x11);
	BANNER_enviar(col,6,0x00);*/
}
/*
void write_diamante(Xuint32 col){
	BANNER_enviar(col,0,0x00);
	BANNER_enviar(col,1,0x00);
	BANNER_enviar(col,2,0x04);
	BANNER_enviar(col,3,0x0A);
	BANNER_enviar(col,4,0x04);
	BANNER_enviar(col,5,0x00);
	BANNER_enviar(col,6,0x00);
}*/


void write_diamante_DIR(Xuint32 col,Xuint32 dir){
	for(i = 0; i < 7; i++)
		BANNER_enviarcondireccion(col,i,diamante[i],dir);
	/*
	BANNER_enviarcondireccion(col,0,0x00,dir);
	BANNER_enviarcondireccion(col,1,0x00,dir);
	BANNER_enviarcondireccion(col,2,0x04,dir);
	BANNER_enviarcondireccion(col,3,0x0A,dir);
	BANNER_enviarcondireccion(col,4,0x04,dir);
	BANNER_enviarcondireccion(col,5,0x00,dir);
	BANNER_enviarcondireccion(col,6,0x00,dir);*/
}


#endif /** CARACTERES_H */
