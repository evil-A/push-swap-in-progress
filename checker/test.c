#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *g_int;

int main()
{
	char *str; // <----- declara una variable. 
	char *str1;
	char r;  // 1 byte
	char j; 	 // 4 bytes
	char c;  // 1 byte
	int i;


	str = NULL;
	printf("direccion de memoria de main = %p\n", main);
	printf("contenido de str antes de asignar nada = %16p\n", str);
	printf("dirección de str antes de asignar nada = %16p\n", &str);
	str = "Hola, estes mi contenido";
	str1 = "Hola, estes mi contenido.";
	printf("diferencia str - str1 = %li\n", str - str1);
	printf("contenido de str despues de asignar =    %16p\n", str);
	printf("contenido de str1 despues de asignar =    %16p\n", str1);
//	printf("dirección de str despues de asignar =    %p\n", &str);
	c = 'j';


	/*
	 * *str es una variable y tiene su propia direccion de memoria que es 5
	 * *str alverga una direccion de memoria.
	*/
/*
	printf("El tamaño de un (int *)       es %lu\n", sizeof(int *));
	printf("El tamaño de un (char *)      es %lu\n", sizeof(char *));
	printf("El tamaño de un (short int *) es %lu\n", sizeof(short int *));
	printf("El tamaño de un (long int *)  es %lu\n", sizeof(long int *));
	printf("El tamaño de un (void *)      es %lu\n", sizeof(void *));
	printf("El tamaño de un (int)         es %lu\n", sizeof(int));
	printf("El tamaño de un (short int)   es %lu\n", sizeof(short int));
	printf("El tamaño de un (long int)    es %lu\n", sizeof(long int));
	printf("El tamaño de un (char)        es %lu\n", sizeof(char));
	printf("El tamaño de un (void)        es %lu\n", sizeof(void));
*/
//	printf("str es un puntero y sólo puede contener direcciones de memoria. Mi contenido es = %i\n", c);
	printf("el contenido al que apunta str es '%s'\n", str);
	printf("el contenido al que apunta str es '%c'\n", *(str + 10));
	printf("Entramos en un bucle\n");
//	i = 0;
//	while (*(str + i))
//	{
//		printf("%c <--- %p\n" , *(str + i), str + i);
//		i++;
//	}
//	printf("\nY salimos\n");
//	printf("contenido de c     = %c\n", c);
//	printf("direccion de g_int = %p\n", &g_int);
//	printf("direccion de c     = %p\n", &c);
//	printf("direccion de r     = %p\n", &r);
	printf("dirección de str   = %p\n", &str);
//	printf("direccion de j     = %p\n", &j);
	return (0);
}
