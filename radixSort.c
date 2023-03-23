#include <stdlib.h>
#include <stdio.h>
#include "listas/lista.h"
#include "radixSort.h"
#include <math.h>
#define N 20

long int contadorWhileListaVacia,contadorIfTraspasar,contadorBucleConcatena,contadorBucleAnulaDestruye;

void radixSort(Lista *lista,int numGrupos,int numCifras)
{
    Lista aux[numGrupos];
    int i,j;
    tipoElemento x;
    tipoPosicion p;
    contadorWhileListaVacia=0;
    contadorIfTraspasar=0;
    contadorBucleConcatena=0;
    contadorBucleAnulaDestruye=0;
    
    for(i=0;i<numGrupos;i++)
        creaVacia(&aux[i]);
        
    for(i=0;i<numCifras;i++)
    {
        while(!vacia(lista))
        {
            contadorWhileListaVacia++;
            if((p=primero(lista)->sig)!=NULL){
                x=recupera(p,lista);
                x=(x/(int)pow(10,i))%numGrupos;
                traspasarNodo(p,lista,fin(&aux[x]),&aux[x]);
                contadorIfTraspasar++;
            }
        }
        for(j=0;j<numGrupos;j++)
        {
            concatenarListas(lista,&aux[j]);
            contadorBucleConcatena++;
        }
    }
    for(i=0;i<numGrupos;i++){
        anula(&aux[i]);
        destruye(&aux[i]);
        contadorBucleAnulaDestruye++;
    }
    anula(aux);
    destruye(aux);
}

int traspasarNodo(tipoPosicion p, Lista *la, tipoPosicion q, Lista *lb) {
    tipoElemento x;
    if(la == NULL){
    	printf("La lista A esta vacia\n");
    	return -2;
    }
    
    if(lb == NULL){
    	printf("La lista B esta vacia\n");
    	return -2;
    }
    
    if(p == NULL){
    	printf("Posicion invalida.\n");
    	return -1;
    }
    
    if(q == NULL){
    	printf("Posicion invalida.\n");
    	return -1;
    }
    
    suprime(p, la);
    if (q == lb->ultimo){
        q->sig = p;
        p->sig = NULL;
        lb->ultimo = p;
    }
    else{
        anterior(q,lb)->sig = p;
        p->sig = q;
    }

    return 0;
}

int concatenarListas (Lista *la, Lista *lb) {
    if(la==NULL){
    	printf("La lista A no existe\n");
    	return -2;
    }
    
    if(lb==NULL){
    	printf("La lista B no existe\n");
    	return -2;
    }

    if(vacia(lb)){
        return 0;
    }

    if(vacia(la)){
        primero(la)->sig = primero(lb)->sig;
    }
    else{
        fin(la)->sig = primero(lb)->sig;
    }
    la->ultimo = lb->ultimo;

    lb->raiz->sig = NULL;
    lb->ultimo = lb->raiz;

    return 0;
}