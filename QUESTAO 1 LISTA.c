#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <string.h>

main () {
	setlocale (LC_ALL, "Portuguese");
	//variaveis
	float a,b,c,d;
	//programa
	printf ("------------------------------\n");
	printf ("LISTA DE EXERCICIOS I: LOGICA DE PROGRAMA��O\n");
	printf ("Escreva um Programa C para: Dado o tamanho da base e da altura de um ret�ngulo, encontrar �rea e per�metro.\n\n");
	//entrada de dados
	printf ("Por favor digite a Altura do Ret�ngulo (Em Cent�metros):");
	scanf ("%f", &a);
	printf ("\n\nALTURA CAPTURADA: '%.f'CM\n\n", a);
	printf ("\nPor favor digite a Base do Ret�ngulo (Em Cent�metros):");
	scanf ("%f", &b);
	printf ("\n\nALTURA CAPTURADA: '%.f'CM\n", b);
	//calculo de dados
	c=a*b; //area
	d=(a+b)+(a+b); //perimetro
	//resposta
	printf ("\n\n--------------------------------\n\n");
	printf ("Area do Ret�ngulo: '%.2f'cm quadrados\nPer�metro do Ret�ngulo: '%.2f'cm\n\n",c,d);
}
