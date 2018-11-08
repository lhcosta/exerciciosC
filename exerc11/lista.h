#ifndef LISTA_H
#define LISTA_H

/*
 * - lista.h
 *
 *
 * Created by José Adalberto F. Gualeve  on 11/10/18.
 * Copyright 2018 - All rights reserved
*/
#include<stdio.h>
#include<stdlib.h>

typedef struct elemento Elemento;

struct descritor{
	Elemento **inicio;
	Elemento **fim;
	int tamanho;
};

typedef struct descritor Descritor;

void criarLista(Descritor **lista);
int inserirElemento(Descritor *lista, int valor);
void imprimirLista(Descritor *lista);
int listaVazia(Descritor *lista);
int buscarElemento(Descritor *lista, int valor);
void liberarLista(Descritor *lista);

#endif // LISTA_H
