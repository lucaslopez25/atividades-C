#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <string.h>

main () {
	setlocale (LC_ALL, "Portuguese");
	//variaveis
	float a,b,c;
	//programa
	printf ("------------------------------\n");
	printf ("LISTA DE EXERCICIOS I: LOGICA DE PROGRAMA��O\n");
	printf ("Escreva um Programa C para: Dado o tamanho do lado de um quadrado, calcular �rea e per�metro do mesmo.\n\n");
	//entrada de dados
	printf ("Por favor digite o lado do Quadrado (Em Cent�metros):");
	scanf ("%f", &a);
	printf ("\n\nLADO DO QUADRADO:'%.f'CM\n\n", a);
	//calculo de dados
	b=a*a; //area
	c=a*4; //perimetro
	//saida de dados
	printf ("\n\n------------------------------\n");
	printf ("A �rea do quadrado � '%.4f'cm�, e o per�metro do quadrado � '%.4f'cm.\n\n",b,c);
}
