//Síntese - Lucas Henrique - UC17201125	
//Objetivo - realizar o cadastro e a listagem de alunos
//Entrada - dados referente a cada aluno 
//Saída - listagem de todos os alunos cadastrados

#include <stdio.h>
#include <stdlib.h>
#include "validacoes.h"
#include "arquivos.h"
#include "alunos.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void menu(char nameFile[]);

int main(int argc, char *argv[]) {
	
	char nameFile[] = {"alunos.dat"};
	
	if(!existe_file(nameFile)){
		cria_file(nameFile);	
	}
	
	menu(nameFile);
	
	return 0;
}

void menu(char nameFile[]){
	
	int opcao;
	
	do{	
		printf("\tMENU\n\n");
		printf("1.CADASTRAR ALUNO\n");
		printf("2.LISTAR ALUNOS\n");
		printf("3.SAIR\n");
		printf("->");
		scanf("%d", &opcao);system("cls");
		
		switch(opcao){
			case 1:
				cadastraAluno(nameFile);system("cls");
				break;
			case 2:
				apresentaAlunos(nameFile);getch();system("cls");
				break;
			case 3:
				exit(0);
			default:
				printf("Opcao Invalida! Digite Novamente\n");getch();system("cls");
		}
	}while(opcao != 3);
	
}
