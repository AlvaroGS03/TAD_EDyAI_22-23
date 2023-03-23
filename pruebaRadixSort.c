#include <stdio.h>
#include <stdlib.h>
#include "listas/lista.h"
#include "radixSort.h"
#include <math.h>
#include <time.h>


int purga(Lista *l);

int main(int argc, char *argv[]){   
    Lista miLista;
    tipoPosicion p;
    int numElementos = 100, codigoError,i;
    int numCifras = 3;
    double division = pow(10,numCifras);
    clock_t t_ini, t_fin;
    FILE *f;
    f = fopen("resultadosRadixSort.txt", "a+");

	if (argc > 2) {
            printf("\n Uso: ./pruebaRadixSort <número de elementos de la lista>\n\n");
            return -1;
        }
       if (argc==2) 
		numElementos=atoi(argv[1]); 

    printf("Creando lista vacía: %d\n", creaVacia(&miLista));

    printf("Se crea una lista de %d elementos\n", numElementos);
    anula(&miLista);	
    p = primero(&miLista);
    for (i = 0; i < numElementos; i++) { 
    	codigoError = inserta(rand()%(int)division,p,&miLista);
    	p = siguiente(p,&miLista);
    	}
    imprime(&miLista);
    t_ini = clock();
    radixSort(&miLista,10,numCifras);
    t_fin = clock();
    printf("\nLista Ordenada \n");
    imprime(&miLista);
    printf("\nTiempo de ejecución: %f segundos\n", (double)(t_fin - t_ini) / CLOCKS_PER_SEC);

    fprintf(f, "Nº Elementos: %d \n Nº Cifras: %d \n Tiempo de Ejecución: %f segundos \n Contador While Lista Vacia: %ld \n Contador If Traspasar: %ld \n Contador Bucle Concatena: %ld \n Contador Bucle Anula Destruye: %ld \n\n", numElementos, numCifras, (double)(t_fin - t_ini) / CLOCKS_PER_SEC, contadorWhileListaVacia,contadorIfTraspasar,contadorBucleConcatena,contadorBucleAnulaDestruye);
    anula(&miLista);
    destruye(&miLista);
    fclose(f);

    return 0;
}