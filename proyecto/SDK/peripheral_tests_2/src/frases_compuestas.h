/**
 * Author: Javier Romero Flores
 * Description:
 * Composicion de frases completas para la matriz de 8 displays
 * */

#ifndef FRASES_COMPUESTAS_H
#define FRASES_COMPUESTAS_H

#include "caracteres.h"


void normalDelay(){
	int c;
	for ( c = 1 ; c <= 1500 ; c++ ){}
}

void slowDelay(){
	int c,j;

	for ( c = 1 ; c <= 13500 ; c++ ){
		for ( j = 1 ; j <= 250 ; j++ ){}
	}

	//for(c = 1; c <= 843750;c++){}
}

void aSecondDelay(){
	int c,j;

	for ( c = 1 ; c <= 13500 ; c++ ){
		for ( j = 1 ; j <= 63 ; j++ ){}
	}
}

void write_winner(){
	write_W(0);
	write_I(1);
	write_N(2);
	write_N(3);
	write_E(4);
	write_R(5);
	write_smile(6);
	write_espacio(7);
}

void write_looser(){
	write_L(0);
	write_O(1);
	write_O(2);
	write_S(3);
	write_E(4);
	write_R(5);
	write_sad(6);
	write_espacio(7);
}

void varios(Xuint32 baseaddr){

	write_winner(baseaddr);
	while(BANNER_mWriteFIFOFull(baseaddr)){}
	normalDelay();
	write_looser(baseaddr);

}

void mostrarCartasLetras(Xuint32 dir){
	write_A_DIR(0,dir);
	write_diamante_DIR(1,dir);
	write_B_DIR(2,dir);
	write_diamante_DIR(3,dir);
	write_C_DIR(4,dir);
	write_diamante_DIR(5,dir);
	write_D_DIR(6,dir);
	write_diamante_DIR(7,dir);
}

void mostrarCartasNumeros(Xuint32 dir){
	write_1_DIR(0,dir);
	write_diamante_DIR(1,dir);
	write_2_DIR(2,dir);
	write_diamante_DIR(3,dir);
	write_3_DIR(4,dir);
	write_diamante_DIR(5,dir);
	write_4_DIR(6,dir);
	write_diamante_DIR(7,dir);
}

void cuentaAtras(){
	aSecondDelay();
	BANNER_inicializa();
	write_4_DIR(3,TURN_QUIET);
	aSecondDelay();
	BANNER_inicializa();
	write_3_DIR(3,TURN_QUIET);
	aSecondDelay();
	BANNER_inicializa();
	write_2_DIR(3,TURN_QUIET);
	aSecondDelay();
	BANNER_inicializa();
	write_1_DIR(3,TURN_QUIET);
	aSecondDelay();
	BANNER_inicializa();
}

void startGame(){

	BANNER_inicializa();

	BANNER_enviarcondireccion(0,0,0x15,TURN_QUIET);
	BANNER_enviarcondireccion(0,1,0x00,TURN_QUIET);
	BANNER_enviarcondireccion(0,2,0x10,TURN_QUIET);
	BANNER_enviarcondireccion(0,3,0x00,TURN_QUIET);
	BANNER_enviarcondireccion(0,4,0x10,TURN_QUIET);
	BANNER_enviarcondireccion(0,5,0x00,TURN_QUIET);
	BANNER_enviarcondireccion(0,6,0x15,TURN_QUIET);

	BANNER_enviarcondireccion(1,0,0x0A,TURN_QUIET);
	BANNER_enviarcondireccion(1,1,0x00,TURN_QUIET);
	BANNER_enviarcondireccion(1,2,0x00,TURN_QUIET);
	BANNER_enviarcondireccion(1,3,0x00,TURN_QUIET);
	BANNER_enviarcondireccion(1,4,0x00,TURN_QUIET);
	BANNER_enviarcondireccion(1,5,0x00,TURN_QUIET);
	BANNER_enviarcondireccion(1,6,0x0A,TURN_QUIET);

	BANNER_enviarcondireccion(2,0,0x00,TURN_QUIET);
	BANNER_enviarcondireccion(2,1,0x07,TURN_QUIET);
	BANNER_enviarcondireccion(2,2,0x04,TURN_QUIET);
	BANNER_enviarcondireccion(2,3,0x07,TURN_QUIET);
	BANNER_enviarcondireccion(2,4,0x01,TURN_QUIET);
	BANNER_enviarcondireccion(2,5,0x07,TURN_QUIET);
	BANNER_enviarcondireccion(2,6,0x00,TURN_QUIET);

	BANNER_enviarcondireccion(3,0,0x00,TURN_QUIET);
	BANNER_enviarcondireccion(3,1,0x0E,TURN_QUIET);
	BANNER_enviarcondireccion(3,2,0x04,TURN_QUIET);
	BANNER_enviarcondireccion(3,3,0x04,TURN_QUIET);
	BANNER_enviarcondireccion(3,4,0x04,TURN_QUIET);
	BANNER_enviarcondireccion(3,5,0x04,TURN_QUIET);
	BANNER_enviarcondireccion(3,6,0x00,TURN_QUIET);

	BANNER_enviarcondireccion(4,0,0x00,TURN_QUIET);
	BANNER_enviarcondireccion(4,1,0x1D,TURN_QUIET);
	BANNER_enviarcondireccion(4,2,0x15,TURN_QUIET);
	BANNER_enviarcondireccion(4,3,0x15,TURN_QUIET);
	BANNER_enviarcondireccion(4,4,0x15,TURN_QUIET);
	BANNER_enviarcondireccion(4,5,0x1D,TURN_QUIET);
	BANNER_enviarcondireccion(4,6,0x00,TURN_QUIET);

	BANNER_enviarcondireccion(5,0,0x02,TURN_QUIET);
	BANNER_enviarcondireccion(5,1,0x18,TURN_QUIET);
	BANNER_enviarcondireccion(5,2,0x08,TURN_QUIET);
	BANNER_enviarcondireccion(5,3,0x18,TURN_QUIET);
	BANNER_enviarcondireccion(5,4,0x00,TURN_QUIET);
	BANNER_enviarcondireccion(5,5,0x00,TURN_QUIET);
	BANNER_enviarcondireccion(5,6,0x02,TURN_QUIET);

	BANNER_enviarcondireccion(6,0,0x0A,TURN_QUIET);
	BANNER_enviarcondireccion(6,1,0x00,TURN_QUIET);
	BANNER_enviarcondireccion(6,2,0x00,TURN_QUIET);
	BANNER_enviarcondireccion(6,3,0x00,TURN_QUIET);
	BANNER_enviarcondireccion(6,4,0x00,TURN_QUIET);
	BANNER_enviarcondireccion(6,5,0x00,TURN_QUIET);
	BANNER_enviarcondireccion(6,6,0x0A,TURN_QUIET);

	BANNER_enviarcondireccion(7,0,0x15,TURN_QUIET);
	BANNER_enviarcondireccion(7,1,0x00,TURN_QUIET);
	BANNER_enviarcondireccion(7,2,0x01,TURN_QUIET);
	BANNER_enviarcondireccion(7,3,0x00,TURN_QUIET);
	BANNER_enviarcondireccion(7,4,0x01,TURN_QUIET);
	BANNER_enviarcondireccion(7,5,0x00,TURN_QUIET);
	BANNER_enviarcondireccion(7,6,0x15,TURN_QUIET);

	slowDelay();
	slowDelay();
	BANNER_inicializa();
}

#endif /** FRASES_COMPUESTAS_H */
