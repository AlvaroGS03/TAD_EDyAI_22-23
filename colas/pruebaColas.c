#include "pruebaColas.h"


void main(){
    Cola c,temp;
    FILE *f;
    clock_t t_ini, t_fin;

    f = fopen("pruebaColas.txt", "a+");
    t_ini = clock();
    printf("Creando cola vacía: %d\n", colaCreaVacia(&c));
    printf("¿Cola vacía?(1-vacía): %d\n", colaVacia(&c));
    fprintf(f, "Resultados de la prueba de la cola:\n\n");
    fprintf(f, " ¿Cola vacía?(1-vacía): %d\n", colaVacia(&c));
    
    printf("Insertando elemento 1: %d\n", colaInsertaC(&c,1));
    printf("Insertando elemento 2: %d\n", colaInsertaC(&c,2));
    printf("Insertando elemento 3: %d\n", colaInsertaC(&c,3));
    fprintf(f, " Insertando elementos...\n");

    
    printf("¿Cola vacía?(1-vacía): %d\n", colaVacia(&c));
    fprintf(f, " ¿Cola vacía?(1-vacía): %d\n", colaVacia(&c));

    printf("Elementos de la cola: \n");
    fprintf(f, " Elementos de la cola: \n");
    temp = c;
    while(temp.frente != NULL){
        printf("%d \n", temp.frente->elemento);
        fprintf(f, " %d \n", temp.frente->elemento);
        temp.frente = temp.frente->sig;
    }
    
    while (!colaVacia(&c))
    {
        printf("Eliminando elemento: %d\n", colaSuprime(&c));
    }
    
    fprintf(f, " Eliminando elementos...\n");

    printf("¿Cola vacía?(1-vacía): %d\n", colaVacia(&c));
    t_fin = clock();
    fprintf(f, " ¿Cola vacía?(1-vacía): %d\n", colaVacia(&c));
    printf("Tiempo de ejecución: %f segundos", (double)(t_fin - t_ini) / CLOCKS_PER_SEC);
    fprintf(f, " Tiempo de ejecución: %f segundos \n\n", (double)(t_fin - t_ini) / CLOCKS_PER_SEC);

    fclose(f);
}