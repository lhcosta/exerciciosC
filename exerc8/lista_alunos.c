#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_alunos.h"

#define TAM_ARRAY 20

void criar_lista(Lista **l){	
	*l = NULL;
	return;
}

int lista_vazia(Lista *l){
	if(l == NULL){
		return 1;
	}else{
		return 0;
	}
}

void inserir_aluno(Lista *l, Aluno *aluno){
	
	Lista *novoAluno = (Lista*) malloc(sizeof(Lista));

	if(novoAluno!=NULL && l!=NULL){
		novoAluno->prox = l;
		novoAluno->aluno = *aluno;
		l = novoAluno;	
	}
	
	free(novoAluno);
	return;	
}

void cadastrarAluno(Aluno *aluno){		
	
	fflush(stdin);	
	printf("Nome: ");
	scanf("%[^\n]s", &aluno->nome);
	fflush(stdin);
	printf("Matricula: ");
	scanf("%d", &aluno->matricula);
}

void imprimirLista(Lista *l){
	
	Lista *aux;
	int i = 0;
	/*Consertar impressao de listas*/
	printf("ALUNOS\n\n");
	for(i=0;i<TAM_ARRAY;i++){
		aux = &l[i];
		while(aux->colisao){
			printf("%s\n", aux->aluno.nome);
			printf("%d\n", aux->aluno.matricula);
			printf("\n");
			aux = aux->prox;
		}
		
	}
	
	return;
}

int funcaoHash(Aluno *aluno, int tamArray){
	
	int indice = 0;
	int i = 0;
	
	for(i=0;i<strlen(aluno->nome);i++){
		indice += (int) aluno->nome[i];
	} 
	
	if(indice % 2 == 0){
		indice += 17;
	}else if(indice % 10 == 0){
		indice /= 3;
	}else{
		indice /= 2;
	}
	
	return indice % tamArray;
}

void menu(){
	
	int opcao = 0;
	Aluno aluno;
	int indice;
	
	Lista l[TAM_ARRAY];
	int i = 0;
	int colisoes = 0;
	
	for(i=0;i<TAM_ARRAY;i++){
		l[i].colisao = 0;
	}
	
	do{	
		printf("\tMENU\n\n");
		printf("1 - Cadastrar aluno\n");
		printf("2 - Imprimir alunos\n");
		printf("3 - Quantidade de colisoes\n");
		printf("4 - Sair\n");
		scanf("%d", &opcao);system("cls");
		
		switch(opcao){
			case 1:
				cadastrarAluno(&aluno);
				indice = funcaoHash(&aluno,TAM_ARRAY);
				if(l[indice].colisao == 1){
					inserir_aluno(&l[indice],&aluno);
					colisoes++;
				}else{
					inserir_aluno(&l[indice],&aluno);
					l[indice].colisao = 1;
				}	
				break;
			case 2:
				imprimirLista(l);
				break;
			case 3:
				printf("Quantidade de Colisoes -> %d\n", colisoes);getch();system("cls");	
				break;
			case 4:
				exit(0);	
			default:
				printf("Opcao Invalida\nDigite Novamente\n");getch();
		}
	}while(opcao != 4);
	
	return;
}
