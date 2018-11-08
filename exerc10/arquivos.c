#include <stdio.h>
#include <stdlib.h>
#include "arquivos.h"

#define ERRO_READ_FILE printf("Erro na leitura do arquivo.\n");
#define ERRO_ALOCA_MEM printf("Erro na alocacao de memoria.\n");

/*Ojetivo: ler qualquer tipo de dados em um arquivo
Parâmetros: ponteiro dos dados, nome do arquivo, tipo do arquivo, tamanho do dado e contador para dados
Retorno: nenhum
*/

void readFile(Aluno **alunos, char *nameFile, char *typeFile, int sizeData, int *qtdData){
	
	FILE *f = NULL;
	int i = 0;
	Aluno aux_alunos;
	
	f = fopen(nameFile,typeFile);
	
	if(f == NULL){
		ERRO_READ_FILE
		return;
	}

	/*Fazendo a contagem da quantidade de dados*/
	while(!feof(f)){
		*qtdData += fread(&aux_alunos,sizeData,1,f);
	}
	
	//Retornando ao inicio do arquivo
	rewind(f);
	
	//Alocando memoria
	*alunos = (Aluno*) calloc(*qtdData,sizeData);
	
	if(*alunos == NULL){
		ERRO_ALOCA_MEM
		return;
	}
	
	//Copiando os dados para o ponteiro
	if(fread(*alunos,sizeData,*qtdData,f) != *qtdData){
		ERRO_READ_FILE
	}

	fclose(f);
	
	return;
}

