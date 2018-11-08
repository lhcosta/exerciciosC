#include <stdlib.h>
#include <stdio.h>
#include "listaEncadeada_24-10.h"

struct elemento{
	Aluno aluno;
	struct elemento *prox;
};

typedef struct elemento Elemento;

Lista** criar_lista(){
	
	Lista **li = (Lista**)malloc(sizeof(Lista));
	
	if(li != NULL){
		li = NULL;
	}

	return li;
}


