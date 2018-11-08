#include <stdio.h>
#include <stdlib.h>
#include "listaEncadeada_24-10.h"
#include "arquivo.h"

#define MAX_LISTA 20

int main() {
	
	Lista **li[MAX_LISTA];
	Aluno *alunos;
	int qtdAlunos=0;
	int i = 0;
	
	
	for(i=0;i<MAX_LISTA;i++){
		li[i] = criar_lista();
	}
	
	readFile(&alunos,"alunos.dat","rb",sizeof(Aluno),&qtdAlunos);
	
	for(i=0;i<qtdAlunos;i++){
		printf("%s\n", alunos[i].nome);
	}
	
	
	
	return 0;
}
