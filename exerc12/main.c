#include <stdio.h>
#include <stdlib.h>
#include "listaCircular.h"

#define MAX_SENHAS 5

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void menu(Descritor *lista);

int main(int argc, char *argv[]) {
	
	Descritor *lista;
	
	criarLista(&lista,MAX_SENHAS);
	
	menu(lista);	

	
	
	return 0;
}

void menu(Descritor *lista){
	
	int opcao = 0;
	int senha = 0;
	
	do{
		fflush(stdin);
		printf("\t\t----MENU----\n\n");
		printf("1 - Pegar Senha\n");
		printf("2 - Chamar Senha\n");
		printf("0 - Sair\n");
		scanf("%d", &opcao);
		
		switch(opcao){
			case 1:
				pegaSenha(lista);
			break;
			case 2:
				chamaSenha(lista);
			break;
			case 0:
			exit(0);
		}
		getch();system("cls");
	}while(opcao!=0);
	
	
}
