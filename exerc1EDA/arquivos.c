#include "arquivos.h"
#include <stdio.h> 
#include <stdlib.h>

//Objetivo: método para verificar a existência de arquivo
//Parâmetros: nome do arquivo
//Retorno: true(1) ou false(0)

int existe_file(char nameFile[]){
	
	FILE *f;
	
	f = fopen(nameFile,"rb");
	
	if(f != NULL){
		fclose(f);
		return 1;
	}
	
	fclose(f);
	return 0;

}

//Objetivo: criar arquivo
//Parâmetros: nome do arquivo
//Retorno: nenhum

void cria_file(char nameFile[]){
	
	FILE *f;
	
	f = fopen(nameFile,"wb");
	
	if(f == NULL){
		ERRO_FILE
	}
	
	fclose(f);
}

//Objetivo: escrever dados no arquivo desejado
//Parâmetros: dados a serem gravados, nome do arquivo
//Retorno: nenhum

void writeInFile(struct aluno *dadosAluno, char nameFile[]){
	
	FILE *f;
	
	f = fopen(nameFile,"ab");
	
	if(f == NULL){
		ERRO_FILE
	}
		
	if(fwrite(dadosAluno,sizeof(struct aluno),1,f)!=1){
		ERRO_FILE
	}	
	
	fclose(f);
	
}

//Objetivo: ler dados do arquivo
//Parâmetros: ponteiro de ponteiro para variável que vai armazenar os dados, nome do arquivo e ponteiro para quantidade de alunos
//Retorno: nenhum

void readFile(struct aluno **dadosAlunos, char nameFile[], int *qtdAlunos){
	
	FILE *f;
	struct aluno aux;
	int j=0;
	
	f = fopen(nameFile,"rb");
	
	if(f == NULL){
		ERRO_FILE
	}
	
	/*Contagem da quantidade de alunos no arquivo*/
	
	while(!feof(f)){
		if(fread(&aux,sizeof(struct aluno),1,f) == 1){
			*qtdAlunos += 1;		
		}
	}
	
	/*Retornado pro início do arquivo*/
	rewind(f);
	
	/*Alocando memória*/
	
	*dadosAlunos = (struct aluno*) malloc(sizeof(struct aluno) * (*qtdAlunos));
	
	if(*dadosAlunos == NULL){
		printf("ERRO! Na alocacao de memoria.\n");
		return;
	}
	
	if(fread(*dadosAlunos,sizeof(struct aluno),*qtdAlunos,f) != *qtdAlunos){
		printf("ERRO!Na leitura do arquivo;\n");exit(1);
	}
	
	fclose(f);
		
}
