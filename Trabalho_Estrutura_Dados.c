#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <unistd.h>

#define tru 1
#define fal 0

void flush_in() {
    int ch;
    do {
        ch = fgetc(stdin);
    } while (ch != EOF && ch != '\n');
}

//funcoes arvore
typedef int bol;
typedef int TIPOCHAVE;
int INDICE=1;
/*
TIPO DE ARQUIVO
1 = PASTA
2 = ARQUIVO
*/


typedef struct no{
	TIPOCHAVE chave;
	int tipo;
	char nome[30];
	struct no *primFilho;
	struct no *proxIrmao;	
}NO;

typedef NO* PONT;
PONT buscaChave(TIPOCHAVE ch, PONT raiz);

PONT criaNovoNo(TIPOCHAVE ch, char name[], int tipo){
	PONT novo = (PONT)malloc(sizeof(NO));
	novo->primFilho=NULL;
	novo->proxIrmao=NULL;
	novo->chave=ch;
	strcpy(novo->nome,name);
	novo->tipo=tipo;
	return(novo);
}

PONT inicializa(TIPOCHAVE ch,char name[], int tipo){
	return(criaNovoNo(ch,name,tipo));
}

bol insere(PONT raiz, TIPOCHAVE novaChave, TIPOCHAVE chavePai,char name[], int tipo){
	PONT pai=buscaChave(chavePai,raiz);
	if(!pai) return(fal);
	PONT filho=criaNovoNo(novaChave,name,tipo);
	PONT p=pai->primFilho;
	if(!p) pai->primFilho=filho;
	else{
		while(p->proxIrmao)
			p=p->proxIrmao;
		p->proxIrmao=filho;
	}
	return(tru);
}

void exibirArvore(PONT raiz){
	if(raiz==NULL) return;
	if(raiz->tipo==1){
		printf("\nPASTA:");
	}else{
		printf("\nARQUIVO:");
	}
	printf("%s ", raiz->nome);
	printf("\n");
	PONT p = raiz->primFilho;
	while(p){
		exibirArvore(p);
		p=p->proxIrmao;
	}
}

PONT buscaChave(TIPOCHAVE ch, PONT raiz){
	if(raiz==NULL) return NULL;
	if(raiz->chave==ch) return raiz;
	PONT p = raiz->primFilho;
	while(p){
		PONT resp = buscaChave(ch, p);
		if(resp) return(resp);
		p = p->proxIrmao;
	}
	return(NULL);
}

int confereNome(PONT raiz,char name[], int tipo){
	if(raiz==NULL) return 0;
	PONT p = raiz->primFilho;
	while(p){
		if(strcmp(p->nome,name)==0){
			if(p->tipo==tipo){
				return 1;
			}
		}
		exibirArvore(p);
		p=p->proxIrmao;
	}
	return 0;
}
//funcoes system
void criarPasta(char aux[],char usu[]){
	strcat(aux,"\\");
	strcat(aux,usu);
	if(!CreateDirectory(aux, NULL))
        printf("\nNao foi possivel criar essa pasta.\n");
    else
        printf("\nPasta criada com sucesso.\n");
}

int ListDirectoryContents(const char *sDir){
    WIN32_FIND_DATA fdFile;
    HANDLE hFind = NULL;

    char sPath[2048];

    sprintf(sPath, "%s\\*.*", sDir);

    if((hFind = FindFirstFile(sPath, &fdFile)) == INVALID_HANDLE_VALUE){
        printf("Diretorio nao econtrado: [%s]\n", sDir);
        return 0;
    }
	int tam;
    do{
        if(strcmp(fdFile.cFileName, ".") != 0
                && strcmp(fdFile.cFileName, "..") != 0){
            sprintf(sPath, "%s\\%s", sDir, fdFile.cFileName);
            tam=strlen(sPath);
            while(sPath[tam]!='\\') tam--;
            if(fdFile.dwFileAttributes &FILE_ATTRIBUTE_DIRECTORY){
            	printf("\nPasta: ");
				for(tam++;sPath[tam]!='\0';tam++){
            		printf("%c",sPath[tam]);
				}
            }
            else{
                printf("\nArquivo: ");
                for(tam++;sPath[tam]!='\0';tam++){
            		printf("%c",sPath[tam]);
				}
            }
        }else{
        	printf("..");
		}
    }while(FindNextFile(hFind, &fdFile));
	printf("\n");
    FindClose(hFind);
    return 1;
}

void apagarPasta(char aux[]){
	if(RemoveDirectory(aux) != 0)
        printf("\n Pasta apagada com sucesso.\n");
    else
        printf("\n Nao foi possivel apagar essa pasta.\n");
}

void apagarArquivo(char aux[]){
	int status;
    status = remove(aux);
    if (status == 0)
        printf("Arquivo deletado com sucesso.\n");
    else{
        printf("Nao foi possivel excluir o arquivo.\n");
        perror("Um Erro aoconteceu.\n");
    }
}

void Redundancia (char endereco[], char nome_do_arquivo [], int tipo) {

    if (tipo == 2) {

        strcat (endereco, "\\");
        strcat (endereco, nome_do_arquivo);
        strcat(endereco,".txt");
        printf ("%s", endereco);
    }
}

void FuncaoCriaTexto (char endereco[], char nome_do_arquivo [], int tipo) { //endereco onde vai criar o texto, o endereco deve seguir o exemplo:
	//"C://User/Aluno/Documentos/Programa/Pasta1/Pasta2/nome_do_arquivo_de_texto.txt"
	FILE *arquivo;
	int tamanho = strlen(endereco);
    char local[tamanho];

    strcpy(local, endereco);
    Redundancia(local,nome_do_arquivo,tipo);
	arquivo = fopen (local , "w");
	if (arquivo == NULL) {
		printf ("\nARQUIVO NAO PODE SER CRIADO \n");
		exit (-1);
	}
	char texto[100];
	printf("Digite seu texto:\n");
	scanf("%s",texto);
	fputs(texto,arquivo);
	
	printf("\nArquvio Criado Com Sucesso!!!!\n");

	fclose (arquivo);
}

void FuncaoLeTexto (char endereco[], char nome_do_arquivo [], int tipo ) {
//precisa testar se o endereco eh valido!!!!
	FILE *arquivo;
	int tamanho = strlen(endereco);
    char local[tamanho];

    strcpy(local, endereco);
    Redundancia(local,nome_do_arquivo,tipo);

	if ((arquivo = fopen ( local , "r")) == NULL) {
		printf ("ARQUIVO NAO PODE SER ABERTO \n");
		exit (-1);
	}

	if (tipo == 2) {

		char carac;
		printf("\n->TEXTO:\n");
		do {
			carac = getc (arquivo); //le um caracter
			putchar(carac); //imprime um caracter
		} while (carac != EOF); //EOF = End Of File, Fim de Arquivo!

	}
}

void FuncaoEditaTexto(char endereco[], char nome_do_arquivo [], int tipo){
	FILE *arquivo;
    int tamanho = strlen(endereco);
    char local[tamanho];

    strcpy(local, endereco);
    Redundancia(local,nome_do_arquivo,tipo);

	if ((arquivo = fopen (local , "r+")) == NULL) {
		printf ("ARQUIVO NAO PODE SER ABERTO\n");
		exit (-1);
	}

	if (tipo == 2) {

		char carac;
		char opc;
		char cara2;

		printf("\nEste eh o texto em seu estado atual:\n");

		do {
			carac = getc (arquivo); //le um caracter
			putchar(carac); //imprime um caracter
		} while (carac != EOF); //EOF = End Of File, Fim de Arquivo!

		printf("\n...\n");
		printf("Deseja editar? Y para editar, N para sair:\n");
		flush_in();
		opc = getchar ();

		if (opc == 'Y' || opc == 'y'){
			rewind (arquivo);
			printf ("O cursor de digitacao esta no inicio do arquivo. Voce podera reescrever o arquivo de texto, agora...\n");
			printf ("Digite (para sair digite um @):\n");

			do {
				cara2 = getchar();
				putc (cara2, arquivo);
			} while (cara2!='@');

			rewind (arquivo);
			printf("\nEste eh o texto em seu estado atual:\n");

			do {
				carac = getc (arquivo); //le um caracter
				putchar(carac); //imprime um caracter
			} while (carac != EOF); //EOF = End Of File, Fim de Arquivo!

			printf("\n...\n");

			printf("Deseja reeditar? Y para reeditar, N para sair:\n");
			flush_in();
			opc = getchar ();

			if (opc == 'Y' || opc == 'y') {
				printf("\n\nRecalling FUNCAOEDITATEXTO...\n\n");
				FuncaoEditaTexto ( endereco , nome_do_arquivo , tipo );
			}
			else if (opc == 'N' || opc == 'n') {
				printf ("\nSaindo...\n\n");
			}
			else {
				printf("Resposta nao identificada, reiniciando a funcao...\n");
				printf("\n\nRecalling FUNCAOEDITATEXTO...\n\n");
				FuncaoEditaTexto ( endereco , nome_do_arquivo , tipo );
			}
		}
		else if (opc == 'N' || opc == 'n') {
			printf ("\nSaindo...\n");
		}
		else {
			printf("Resposta nao identificada, reiniciando a funcao...\n");
			printf("\n\nRecalling FUNCAOEDITATEXTO...\n\n");
			FuncaoEditaTexto ( endereco , nome_do_arquivo , tipo );
		}
	}

	fclose (arquivo);
}

void FuncaoApagaTexto (char endereco[], char nome_do_arquivo [], int tipo) {
	FILE *arquivo;
	int aux;
    int tamanho = strlen(endereco);
    char local[tamanho];

    strcpy(local, endereco);
    Redundancia(local,nome_do_arquivo,tipo);

	if ((arquivo = fopen (local , "w")) == NULL) {
		printf ("ARQUIVO NAO PODE SER DELETADO \n");
		exit (-1);
	}

	fclose(arquivo);
}

void copiarArquivo(char origem[],char destino[]){
	FILE *sourceFile;
    FILE *destFile;
	sourceFile = fopen(origem, "r");
    destFile = fopen(destino,   "w");
    if (sourceFile == NULL || destFile == NULL){
        printf("\nUnable to open file.\n");
        printf("Please check if file exists and you have read/write privilege.\n");
        exit(EXIT_FAILURE);
    }
	char ch;
    ch = fgetc(sourceFile);
    while (ch != EOF){
        fputc(ch, destFile);
        ch = fgetc(sourceFile);
    }

    printf("\nFiles copied successfully.\n");

    fclose(sourceFile);
    fclose(destFile);
}

int menu(void){
 int opt;
 printf("\nEscolha a opcao\n");
 printf("0. Sair\n");
 printf("1. Criar Pasta\n");
 printf("2. Criar Arquivo txt\n");
 printf("3. Apagar pasta\n");
 printf("4. Apagar arquivo txt\n");
 printf("5. Copiar arquivo txt\n");
 printf("6. Modificar Arquivo txt\n");
 printf("7. Entrar na pasta\n");
 printf("8. Voltar pasta principal\n");
 printf("9. Ler arquivo txt\n");
 printf("10. Apagar conteudo do arquivo txt\n");
 do{
 	printf("Opcao: "); scanf("%d", &opt);
 	if(opt<0 || opt>10){
 		printf("\nOpcao Invalida! Digite somente os numeros apresentados acima.\n");
	 }
 }while(opt<0 || opt>10);
 return opt;
}

int main(){
	char c[10]={"diret"};
	PONT r = inicializa(1, c, 1);
	//char x[40]={"kelvintt"};
	//insere(r, 2, r->chave, x,1);
	
	char cwd[256];
	if (getcwd(cwd, sizeof(cwd)) == NULL)
	    perror("getcwd() error");
	else
	    printf("...\n");
	char aux[256];
	strcpy(aux, cwd);
	int opt;
	int retornodir;
	
	do{
		printf("\n FILES \n");
        retornodir=ListDirectoryContents(aux);
        if(retornodir==0){
        	strcpy(aux,cwd);
        	retornodir=ListDirectoryContents(aux);
		}
		opt=menu();
        switch(opt){
          case 0:{
              printf("\nFinalizando\n");
              break;
          }
          case 1:{
            char name[40];
            printf("\nDigite o nome para a pasta: ");
            scanf("%s",name);
            int conf=confereNome(r, name, 1);
            if(conf==0){
            	insere(r, INDICE, r->chave, name, 1);
            	criarPasta(aux,name);
            	strcpy(aux,cwd);
			}else{
				printf("\n-->ERRO<--\n");
				printf("Essa pasta ja existe\n");
			}
            break;
          }
          case 2:{
          	char name[40];
            printf("\nDigite o nome para o arquivo: ");
            scanf("%s",name);
            int conf=confereNome(r, name, 2);
            /*if(conf==0){
            	insere(r, INDICE, r->chave, name, 2);
            	//insere(r,INDICE,chavePai,name,1);
            	//criarPasta(name);
			}else{
				printf("\n-->ERRO<--\n");
				printf("Esse arquivo ja existe\n");
			}*/
			FuncaoCriaTexto(aux,name,2);
            break;
          }
          case 3:{
            //remove
            char name[40];
            printf("\nDigite o nome da pasta: ");
            scanf("%s",name);
            flush_in();
            char confirma;
            printf("Deseja realmente apagar a pasta %s? \nDigite [s][n]:",name);
            scanf("%c",&confirma);
            if(tolower(confirma)=='s'){
            	strcat(aux,"\\");
            	strcat(aux,name);
            	apagarPasta(aux);
            	strcpy(aux,cwd);
			}else{
				printf("Processo cancelado.\n");
			}
            break;
          }
          case 4:{
            //remove
            char name[40];
            printf("\nDigite o nome da pasta: ");
            scanf("%s",name);
            strcat(aux,"\\");
            strcat(aux,name);
            strcat(aux,".txt");
            apagarArquivo(aux);
            strcpy(aux,cwd);
            break;
          }
          case 5:{
          	int opinterno;
          	char name[40];
          	char dest[240];
          	strcpy(dest,cwd);
            printf("\nDigite apenas o nome do arquivo (nao e necessario digitar \".txt\"): ");
            scanf("%s",name);
            strcat(aux,"\\");
            strcat(aux,name);
            strcat(aux,".txt");
            do{
            	printf("\n FILES \n");
            	retornodir=ListDirectoryContents(dest);
		        if(retornodir==0){
		        	strcpy(dest,cwd);
		        	retornodir=ListDirectoryContents(dest);
				}
				printf("\nInforme onde deseja colar o arquivo:\n");
				printf("1. Neste Local\n");
				printf("2. Entrar na pasta:\n");
				scanf("%d",&opinterno);
				switch(opinterno){
					case 1:{
						strcat(dest,"\\");
						strcat(dest,name);
						strcat(dest,".txt");
						copiarArquivo(aux,dest);
						break;
					}
					case 2:{
						char entrar[40];
			            printf("\nDigite o nome da pasta: ");
			            scanf("%s",entrar);
			            strcat(dest,"\\");
			            strcat(dest,entrar);
						break;
					}
				}
			}while(opinterno!=1);
			strcpy(aux,cwd);
			break;
		  }
		  case 6:{
		  	printf("Digite apenas o nome do arquivo (nao e necessario digitar \".txt\"):");
		  	char arq[40];
		  	scanf("%s", arq);
		  	FuncaoEditaTexto(aux,arq,2);
		  	strcpy(aux,cwd);
			break;
		  }
          case 7:{
          	char name[40];
            printf("\nDigite o nome para a pasta: ");
            scanf("%s",name);
            strcat(aux,"\\");
            strcat(aux,name);
			break;
		  }
		  case 8:{
		  	strcpy(aux, cwd);
			break;
		  }
		  case 9:{
		  	printf("Digite apenas o nome do arquivo (nao e necessario digitar \".txt\"):");
		  	char arq[40];
		  	scanf("%s", arq);
		  	//funcao abrir arquivo
		  	FuncaoLeTexto(aux,arq,2);
		  	strcpy(aux,cwd);
		  	flush_in();
		  	printf("\nAperte a tecla [ENTER] para continuar:\n");
		  	getchar();
		  	printf("\n");
			break;
		  }
		  case 10:{
		  	printf("Digite apenas o nome do arquivo (nao e necessario digitar \".txt\"):");
		  	char arq[40];
		  	scanf("%s", arq);
		  	FuncaoApagaTexto(aux,arq,2);
		  	strcpy(aux,cwd);
			break;
		  }
          default:{
          	printf("Comando invalido\n\n");
			break;
		  } 
        }
    }while(opt);
	
	return 0;
}
