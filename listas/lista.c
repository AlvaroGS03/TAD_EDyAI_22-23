#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "lista.h"

int creaVacia (Lista *l) {
    if (l == NULL)
        return -2;
    else if (NULL == (l->raiz = l->ultimo = (tipoCelda *)malloc(sizeof(tipoCelda))))
        return -1;
    else {
        l->raiz->sig = NULL;
        return 0;
    }
}

int vacia (Lista *l) {
    if (l == NULL || l->raiz == NULL) {
        return -1;
    }
    else if (l->raiz->sig == NULL)
        return 1;
    else
        return 0;
}

int anula (Lista *l) {
    tipoCelda *aBorrar;
    if (l == NULL || l->raiz == NULL) {
        return -1;
    }
    else {
        aBorrar = l->raiz->sig;
        while (aBorrar != NULL) {
            l->raiz->sig = aBorrar->sig;
            free(aBorrar);
            aBorrar = l->raiz->sig;
        }
        l->ultimo = l->raiz;
        return 0;
    }
}

int destruye (Lista *l) {
    if (l == NULL || l->raiz == NULL) {
        return -1;
    }
    else if (l->raiz->sig != NULL){
        return -2;
    }
    else {
        free(l->raiz);
        l->raiz = l->ultimo = NULL;
        return 0;
    }
}

void imprime (Lista *l) {
    tipoCelda *aImprimir;
    int posicion;

    if (l == NULL || l->raiz == NULL) {
        return;
    }
    else {
        posicion = 1;
        aImprimir = l->raiz->sig;
        while (aImprimir != NULL) {
            printf("Valor: %d en posición: %d\n",aImprimir->elemento, posicion++);
            aImprimir = aImprimir->sig;
        }
        printf("%d valores en la lista\n",posicion-1);
    }
}

tipoPosicion siguiente (tipoPosicion p, Lista *l) {
    if (l == NULL || l->raiz == NULL || p == NULL) {
        return NULL;
    }
    else if (p == l->ultimo) {
        return NULL;
    }
    else {
        return p->sig;
    }
}

tipoPosicion anterior (tipoPosicion p, Lista *l) {
    tipoCelda *anterior;
    if (l == NULL || l->raiz == NULL || p == NULL) {
        return NULL;
    }
    else if (p == l->raiz) {
        return l->raiz;
    }
    else {
        anterior = l->raiz;
        while (anterior->sig != p) {
            anterior = anterior->sig;
        }
        return anterior;
    }
}

tipoPosicion primero (Lista *l) {
    if (l == NULL) {
        fprintf(stderr,"Fallo precondición lista no existente!\n");
        return NULL;
    }
    else if (l->raiz == NULL){
        fprintf(stderr,"Fallo precondición lista no inicializada!\n");
        return NULL;
    } else
        return l->raiz;
}

tipoPosicion fin (Lista *l) {
    if (l == NULL) {
        fprintf(stderr,"Fallo precondición lista no existente!\n");
        return NULL;
    }
    else if (l->ultimo == NULL){
        fprintf(stderr,"Fallo precondición lista no existente!\n");
        return NULL;
    } else
        return l->ultimo;
}

int inserta (tipoElemento x, tipoPosicion p, Lista *l) {
    tipoCelda *nueva;
    if (l == NULL) {
        fprintf(stderr,"Fallo precondición lista no existente!\n");
        return -1;
    }
    else if (l->raiz == NULL) {
        fprintf(stderr,"Fallo precondición nodo ficticio no existente!\n");
        return -2;
    }
    else if (p == NULL){
        fprintf(stderr,"Fallo precondición posición no válida!\n");
        return -3;
    }
    else if (NULL == (nueva = (tipoCelda*)malloc(sizeof(tipoCelda)))) {
        fprintf(stderr,"Fallo reserva memoria!\n");
        return -4;
    }
    else {
        nueva->elemento = x;
        nueva->sig = p->sig;
        p->sig = nueva;
        if (p == l->ultimo)
            l->ultimo = nueva;
        return 0;
    }
}

int suprime (tipoPosicion p, Lista *l) {
    tipoPosicion aBorrar;
    tipoPosicion aAnterior;
    if (l == NULL || l->raiz == NULL || p == NULL) {
        return -1;
    }
    else if (p == l->ultimo) {
        l->raiz->sig = NULL;
        l->ultimo = l->raiz;
        //free(p);
        return -2;
    }
    else {
        aBorrar = p;
        aAnterior = anterior(p,l);
        aAnterior->sig = aBorrar->sig;
        //free(aBorrar);
        if (p->sig == NULL)
            l->ultimo = p;
        return 0;
    }
}

tipoElemento recupera (tipoPosicion p, Lista *l) {
    if (l == NULL || l->raiz == NULL || p == NULL) {
        fprintf(stderr,"Fallo precondición lista no existente!\n");
        return -1;
    }
    else {
        return p->elemento;
    }
}