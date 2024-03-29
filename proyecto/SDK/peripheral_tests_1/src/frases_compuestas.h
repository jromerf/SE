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

void write_winner(Xuint32 baseaddr){
	write_W(baseaddr,0);
	write_I(baseaddr,1);
	write_N(baseaddr,2);
	write_N(baseaddr,3);
	write_E(baseaddr,4);
	write_R(baseaddr,5);
	write_smile(baseaddr,6);
	write_espacio(baseaddr,7);
}

void write_looser(Xuint32 baseaddr){
	write_L(baseaddr,0);
	write_O(baseaddr,1);
	write_O(baseaddr,2);
	write_S(baseaddr,3);
	write_E(baseaddr,4);
	write_R(baseaddr,5);
	write_sad(baseaddr,6);
	write_espacio(baseaddr,7);
}

void varios(Xuint32 baseaddr){

	write_winner(baseaddr);
	while(BANNER_mWriteFIFOFull(baseaddr)){}
	normalDelay();
	write_looser(baseaddr);

}

#endif /** FRASES_COMPUESTAS_H */
