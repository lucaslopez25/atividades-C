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
	printf ("Escreva um Programa C para: Dado o raio de uma circunfer�ncia, calcular �rea e per�metro da mesma.\n\n");
	//entrada de dados
	printf ("Por favor digite o raio (R) da circunfer�ncia (Em Cent�metros):");
	scanf ("%f", &a);
	printf ("\n\nRAIO DA CIRCUNFER�NCIA:'%.f'CM\nESTE PROGRAMA CALCULA USANDO pi=3,1416 (Concorde com isso para prosseguir)\n\n", a);
	//calculo de dados
		c=2*3.1416*a; //perimetro
		b=3.1416*pow(a,2); //area
	//saida de dados
	printf ("\n\n------------------------------\n");
	printf ("A �rea do c�rculo � '%.4f'cm�, e o per�metro do c�rculo � '%.4f'cm.\n\n",b,c);
}
