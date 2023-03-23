#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "pila.h"



int pilaCreaVacia(Pila *p)
{
    *p = NULL;
    return 0;
}

int pilaVacia(Pila *p)
{
    if (*p == NULL) {
        return 1; //VERDADERO --> La cola esta vacia.
    }
    return 0;
}

int pilaInserta(Pila *p,tipoElemento elemento)
{
    Pila nueva = malloc(sizeof (tipoCelda));

    if (nueva == NULL) {
        return -1;
    }
    nueva->sig = NULL;
    nueva->elemento = elemento;

    if (pilaVacia(p)) {
        *p = nueva;
    } else {
        nueva->sig = *p;
        *p = nueva;
    }
    return 0;
}

tipoElemento pilaSuprime(Pila *p)
{
    Pila aux;
    tipoElemento elemento;

    if (pilaVacia(p)) {
        return -1;
    }
    aux = *p;
    elemento = aux->elemento;
    *p = aux->sig;
    free(aux);
    return elemento;
}
