#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

main (void)
{
	//variaveis
	int q,p,r;
	
	setlocale (LC_ALL,"Portuguese");
	
	printf ("...PROGRAMA DESENVOLVIDO PARA RESOLU��O DA PROVA 2017.1...");
	
	printf ("\n\nEscreva um programa em C, que leia a posi��o das portinhas P, Q e R e indique em qual das sa�das a bolinha ir� cair\n");
	
	//coleta de dados
	printf ("Informe a posi��o da porta Q, P, R (d� valores 0 ou 1).\n");
	scanf ("%d %d %d", &q,&p,&r);
	
	//saida de dados
	if (q==0)
	{
		if (r==0)
		{
			printf ("A bolinha ir� passar pela porta D\n");
		}
		else
		{
			printf ("A bolinha ir� passar pela porta C\n");
		}
	}
	else if (q==1)
	{
		if (p==0)
		{
			printf ("A bolinha ir� passar pela porta B\n");
		}
		else
		{
			printf ("A bolinha ir� passar pela porta A\n");
		}
	}
	else
	{
		printf ("N�o h� como calcular a saida da bolinha.\n");
	}
	
}
