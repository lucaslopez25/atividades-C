#include <stdio.h>
#include <stdlib.h>

int main ()
{
	int num;
	char letra;
	printf ("Este eh o programa identificador de letras\n\n");
	printf ("Por favor, digite uma letra para identificar se eh consoante ou vogal\n\n");
	printf ("Digite aqui:");
	scanf ("%c", &letra);
	
	switch (letra)
	{
		case 'a':
			printf ("\n\nA letra %c eh uma vogal.\n", letra);
		break;
		case 'e':
			printf ("\n\nA letra %c eh uma vogal.\n", letra);
		break;
		case 'i':
			printf ("\n\nA letra %c eh uma vogal.\n", letra);
		break;
		case 'o':
			printf ("\n\nA letra %c eh uma vogal.\n", letra);
		break;
		case 'u':
			printf ("\n\nA letra %c eh uma vogal.\n", letra);
		break;
		case 'A':
			printf ("\n\nA letra %c eh uma vogal.\n", letra);
		break;
		case 'E':
			printf ("\n\nA letra %c eh uma vogal.\n", letra);
		break;
		case 'I':
			printf ("\n\nA letra %c eh uma vogal.\n", letra);
		break;
		case 'O':
			printf ("\n\nA letra %c eh uma vogal.\n", letra);
		break;
		case 'U':
			printf ("\n\nA letra %c eh uma vogal.\n", letra);
		break;
		default:
			printf ("\n\nA letra %c eh uma consoante.\n", letra);
		break;
	}
	
	
	system ("PAUSE");
}
