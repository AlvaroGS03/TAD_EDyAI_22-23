#include "pruebaPilas.h"


void main(){
    Pila p,temp;
    FILE *f;
    clock_t t_ini, t_fin;

    f = fopen("pruebaPilas.txt", "a+");
    t_ini = clock();
    printf("Creando pila vacía: %d\n", pilaCreaVacia(&p));
    printf("Pila vacía?(1-vacía): %d\n", pilaVacia(&p));
    fprintf(f, "Resultados de la prueba de la pila:\n\n");
    fprintf(f, " Pila vacía?(1-vacía): %d\n", pilaVacia(&p));
    
    printf("Insertando elemento 1: %d\n", pilaInserta(&p,1));
    printf("Insertando elemento 2: %d\n", pilaInserta(&p,2));
    printf("Insertando elemento 3: %d\n", pilaInserta(&p,3));
    fprintf(f, " Insertando elementos...\n");

    
    printf("Pila vacía?(1-vacía): %d\n", pilaVacia(&p));
    fprintf(f, " Pila vacía?(1-vacía): %d\n", pilaVacia(&p));

    printf("Elementos de la pila: \n");
    fprintf(f, " Elementos de la pila: \n");
    temp = p;
    while(temp != NULL){
        printf("%d \n", temp->elemento);
        fprintf(f, " %d \n", temp->elemento);
        temp = temp->sig;
    }

    while(!pilaVacia(&p)){
        printf("Suprimiendo elemento: %d\n", pilaSuprime(&p));
    }
    fprintf(f, " Suprimiendo elementos...\n");

    printf("Pila vacía?(1-vacía): %d\n", pilaVacia(&p));
    t_fin = clock();
    fprintf(f, " Pila vacía?(1-vacía): %d\n", pilaVacia(&p));
    printf("Tiempo de ejecución: %f segundos", (double)(t_fin - t_ini) / CLOCKS_PER_SEC);
    fprintf(f, " Tiempo de ejecución: %f segundos \n\n", (double)(t_fin - t_ini) / CLOCKS_PER_SEC);

    fclose(f);
}