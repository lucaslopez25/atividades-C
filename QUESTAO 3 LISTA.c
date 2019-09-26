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
	printf ("LISTA DE EXERCICIOS I: LOGICA DE PROGRAMAÇÃO\n");
	printf ("Escreva um Programa C para: Dado o raio de uma circunferência, calcular área e perímetro da mesma.\n\n");
	//entrada de dados
	printf ("Por favor digite o raio (R) da circunferência (Em Centímetros):");
	scanf ("%f", &a);
	printf ("\n\nRAIO DA CIRCUNFERÊNCIA:'%.f'CM\nESTE PROGRAMA CALCULA USANDO pi=3,1416 (Concorde com isso para prosseguir)\n\n", a);
	//calculo de dados
		c=2*3.1416*a; //perimetro
		b=3.1416*pow(a,2); //area
	//saida de dados
	printf ("\n\n------------------------------\n");
	printf ("A área do círculo é '%.4f'cm², e o perímetro do círculo é '%.4f'cm.\n\n",b,c);
}
