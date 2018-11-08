#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "listaEncadeada.h"

struct elemento{
	Aluno aluno;
	struct elemento *prox;
};

typedef struct elemento Elemento;

Lista** criar_lista(){
	
	Lista **li = (Lista**)malloc(sizeof(Lista));
	
	if(li != NULL){
		*li = NULL;
	}

	return li;
}

int incluir_elemento_lista(Lista **l, Aluno *aluno){
	
	if(l == NULL) return 0;
	
	Elemento *auxAluno = (Elemento*)malloc(sizeof(Elemento));
	Elemento *anterior;
	Elemento *atual = *l;	
	
	if(auxAluno == NULL) return 0;
	auxAluno->aluno = *aluno;
	
	//Inserindo no inicio caso não tenha nenhum valor
	if(*l == NULL){
		auxAluno->prox = *l;
		*l = auxAluno;
		return 1;
	}
	
	while(atual != NULL && (stricmp(auxAluno->aluno.nome,atual->aluno.nome)>0)){
		anterior = atual;
		atual = atual->prox;
	}
	
	if(atual == *l){
		auxAluno->prox = *l;
		*l = auxAluno;
	}else{
		auxAluno->prox = anterior->prox;
		anterior->prox = auxAluno;
	}
	
	
	return 1;
}

int imprimir_lista(Lista **l){
	
	Elemento *aux = *l;
	
	if(!(lista_vazia(l))){
		while(aux != NULL){
			printf("Nome -> %s -- Matricula -> %s\n", aux->aluno.nome,aux->aluno.matricula);
			aux = aux->prox;
		}
		return 1;
	}
	
 	return 0;
}

int lista_vazia(Lista **l){
	
	if(l == NULL || *l == NULL){	
		return 1;
	} 
	
	return 0;
	
}

int consulta_lista(Lista **l, char *matriculaAluno){
	
	if(lista_vazia(l)) return 0;
	
	Elemento *aux = *l;
	
	while(aux != NULL){
		if(strstr(aux->aluno.matricula,matriculaAluno) != NULL){
			printf("Nome -> %s -- Matricula -> %s\n", aux->aluno.nome,aux->aluno.matricula);
			return 1;
		}
		aux = aux->prox;
	}

	return 0;
	
}

int remover_elemento_lista(Lista **l, char *matriculaAluno){
	
	if(lista_vazia(l)) return 0;
	
	Elemento *atual = *l;
	Elemento *ant;
	

	while(atual->prox != NULL && stricmp(atual->aluno.matricula,matriculaAluno)!=0){
		ant = atual;
		atual = atual->prox;
	}
	
	if(stricmp(atual->aluno.matricula,matriculaAluno)==0){
		if(atual == *l){
			*l = atual->prox;
		}else{
			ant->prox = atual->prox;
		}
		free(atual);
		return 1;
	}else{
		return 0;
	}
	
}

