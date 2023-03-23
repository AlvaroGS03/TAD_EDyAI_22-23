# Proyecto para entrega Tipos Abstractos de Datos 2022
#
# ( Añadir las reglas necesarias para la correcta compilación de todas las implementaciones que se piden)


pruebaRadixSort: pruebaRadixSort.c listas/lista.h listas/lista.o radixSort.o
	gcc -g pruebaRadixSort.c radixSort.o listas/lista.o -o pruebaRadixSort -lm

radixSort.o: radixSort.c radixSort.h listas/lista.h 
	gcc -g -c radixSort.c

listas/lista.o: listas/lista.c listas/lista.h 
	gcc -g -c listas/lista.c -o listas/lista.o
	
limpiar:
	rm *.o listas/lista.o	
	
