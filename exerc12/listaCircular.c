#include <stdio.h>
#include <stdlib.h>
#include "listaCircular.h"

struct elemento{
	int senha;
	struct elemento *prox;
};

void criarLista(Descritor **lista, int qtdElementos)
{	
	int i = 0;
	Elemento *aux = (Elemento*) malloc(sizeof(Elemento));
	
	*lista = (Descritor*)malloc(sizeof(Descritor));

	if(lista != NULL){
		(*lista)->inicio = (Elemento**)malloc(sizeof(Elemento));
		(*lista)->final = (Elemento**)malloc(sizeof(Elemento));
		(*lista)->qtd = 0;
		(*lista)->geraSenha = 0;
	}
	
	*(*lista)->inicio = aux;
	*(*lista)->final = aux;

	for(i=1;i<qtdElementos;i++){
		Elemento *elemento = (Elemento*) malloc(sizeof(Elemento));
		
		if(elemento!=NULL){
			elemento->prox = *(*lista)->inicio;
			*(*lista)->inicio = elemento;
			*(*lista)->final = elemento;
		}
	}
	
	//Ultimo elemento apontando pro primeiro da lista 
	aux->prox = *(*lista)->inicio;
	
	return;
	
}

void pegaSenha(Descritor *lista)
{

	if((*lista->inicio) == (*lista->final) && lista->qtd!=0){
		printf("Lista Cheia! Retorne mais tarde\n");
		return;
	}
	
	(*lista->final)->senha = ++(lista->geraSenha);
	printf("Senha Gerada -> %d\n", (*lista->final)->senha);
	(*lista->final) = (*lista->final)->prox;
	(lista->qtd)++;
	
	
	return;
}

void chamaSenha(Descritor *lista)
{

	if((*lista->inicio) == (*lista->final) && lista->qtd==0){
		printf("Lista Vazia! Nenhum elemento para ser chamado!\n");
		return;
	}
	
	printf("Senha Chamada -> %d\n", (*lista->inicio)->senha);
		
	(*lista->inicio) = (*lista->inicio)->prox;
	(lista->qtd)--;
	
}
