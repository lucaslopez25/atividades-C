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
	printf ("LISTA DE EXERCICIOS I: LOGICA DE PROGRAMAÇÃO\n");
	printf ("Escreva um Programa C para: Dado o tamanho da base e da altura de um retângulo, encontrar área e perímetro.\n\n");
	//entrada de dados
	printf ("Por favor digite a Altura do Retângulo (Em Centímetros):");
	scanf ("%f", &a);
	printf ("\n\nALTURA CAPTURADA: '%.f'CM\n\n", a);
	printf ("\nPor favor digite a Base do Retângulo (Em Centímetros):");
	scanf ("%f", &b);
	printf ("\n\nALTURA CAPTURADA: '%.f'CM\n", b);
	//calculo de dados
	c=a*b; //area
	d=(a+b)+(a+b); //perimetro
	//resposta
	printf ("\n\n--------------------------------\n\n");
	printf ("Area do Retângulo: '%.2f'cm quadrados\nPerímetro do Retângulo: '%.2f'cm\n\n",c,d);
}
