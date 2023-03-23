#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "cola.h"



int colaCreaVacia(Cola *c)
{
    c->frente = NULL;
    c->fondo = NULL;
 	return 0; 
}

int colaVacia(Cola *c)
{
    if(c->frente == NULL && c->fondo == NULL)
        return 1; //VERDADERO --> La cola esta vacia.
    
    return 0; 
}

int colaInsertaC(Cola *c,tipoElemento elemento)
{
    tipoCelda *nuevo = malloc(sizeof (Cola));

    if(nuevo == NULL)
        return -1;

    nuevo->elemento = elemento;
    nuevo->sig = NULL;
    
    
    if(colaVacia(c)){
        c->frente = nuevo;
        c->fondo = nuevo;

    }else{
        (c->fondo)->sig = nuevo;
         c->fondo=nuevo;
    }
    return 0;
}

tipoElemento colaSuprime(Cola *c)
{
        tipoElemento elemento;
        tipoCelda *suprimir = c->frente;
    
        if(colaVacia(c)){
            printf("Error: cola vacia");
            exit(-1);
        }

        elemento = (c->frente)->elemento;
    
        if(c->frente == c->fondo){
            c->fondo = NULL;
            c->frente = NULL;
        }else{
            c->frente = (c->frente)->sig;
        }
        free(suprimir);
        return elemento;   
}