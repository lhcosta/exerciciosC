/*
 * - lista.c
 *
 *
 * Created by José Adalberto F. Gualeve  on 11/10/18.
 * Copyright 2018 - All rights reserved
*/
#include<stdio.h>
#include<stdlib.h>
#include"lista.h"

typedef struct elemento{
	struct elemento *prox;
	int dado;
	struct elemento *ant;
}Elemento;

void criarLista(Descritor **lista)
{	
	*lista = (Descritor*)malloc(sizeof(Descritor));
	
	if(*lista!=NULL){
		(*lista)->inicio = (Elemento**)malloc(sizeof(Elemento));
		(*lista)->fim = (Elemento**)malloc(sizeof(Elemento));
		(*lista)->tamanho = 0;
	}
	
	*(*lista)->inicio = NULL;
	*(*lista)->fim = NULL;
	
	return;
}

int inserirElemento(Descritor *lista, int valor)
{	
	Elemento *novo = (Elemento *) malloc(sizeof(Elemento));

    if(novo!=NULL){
    	novo->dado = valor;
	}

	if(listaVazia(lista)){
		novo->prox = NULL;
		novo->ant = NULL;
		*lista->inicio = novo;
		*lista->fim = novo;

		return 1;
	}

	if(novo->dado < (*lista->inicio)->dado){
		novo->prox = (*lista->inicio);
		novo->ant = NULL;
		(*lista->inicio)->ant = novo;
		(*lista->inicio) = novo;
		return 1;
	}else if(novo->dado > (*lista->fim)->dado){
		(*lista->fim)->prox = novo;
		novo->ant = (*lista->fim);
		novo->prox = NULL;
		(*lista->fim) = novo;
		return 1;
	}
	
	Elemento *aux = *lista->inicio;

	while(novo->dado > aux->dado){
		aux = aux->prox;
	}
	
	novo->ant = aux->ant;
	aux->ant->prox = novo;
	aux->ant = novo;
	novo->prox = aux;
	
    return 1;
   	
}

void imprimirLista(Descritor *lista)
{
    Elemento *p;
    p = *lista->inicio;
    
    if(listaVazia(lista)){
    	printf("Lista Vazia\n");
    	return;
	}
    
    printf("\t\tLISTAGEM\n\n");
    while( p != NULL ) {
        printf("%d -> ", p->dado);
        p = p->prox;
    }
    printf("FIM\n");
    return;
}

int listaVazia(Descritor *lista)
{
    if (*lista->inicio == NULL && *lista->fim == NULL) {
        return 1;
    }
    return 0;
}

int buscarElemento(Descritor *lista, int valor)
{
	
	if(listaVazia(lista)){
		return 0;
	}
	
	Elemento *inicio = (*lista->inicio);
	Elemento *final = (*lista->fim);

	if(inicio->dado == valor){
		return 1;
	}else if(final->dado == valor){
		return 1;
	}
	
	inicio = inicio->prox;
	
	while(inicio->dado != valor && inicio != final){
		inicio = inicio->prox;
	}
	
	if(inicio->dado == valor){
		return 1;
	}
	
	return 0;
	
}

void liberarLista(Descritor *lista){
	
	if(listaVazia(lista)){
		return;
	}

	Elemento *aux = *lista->inicio;
	Elemento *final = *lista->fim;
	
	while(aux != final){
		Elemento *no = aux;
		aux = aux->prox;
		free(no);
	}
	
	free(aux);

	*lista->inicio = NULL;
	*lista->fim = NULL;
	
	return;
}
