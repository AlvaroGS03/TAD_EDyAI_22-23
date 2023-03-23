/*
 * radixSort.h 
 *
 *  Created on: 03/11/2014
 *      Author: M.J. Polo
 */
#include "listas/lista.h"
#ifndef __RADIX_H
#define __RADIX_H

extern long int contadorWhileListaVacia,contadorIfTraspasar,contadorBucleConcatena,contadorBucleAnulaDestruye;

int traspasarNodo(tipoPosicion p, Lista *la, tipoPosicion q, Lista *lb);
int concatenarListas (Lista *la, Lista *lb);
void radixSort(Lista *lista,int numGrupos,int numCifras);

#endif // 



