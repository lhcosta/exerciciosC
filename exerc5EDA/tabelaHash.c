/*Síntese - Lucas Henrique
Objetivo: por meio de uma função hash fazer o espalhamento de dados em um array e obter a quantidade de colisões
Entrada: dados extraídos de um arquivo
Saída: quantidade de colisões de dados 
*/

#include <stdio.h>	
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <math.h>

#define MAX_NOME 53
#define MAX_MAT 11
#define TAM_KEY 5
#define TAM_ARRAY 30
#define ERRO_READ_FILE printf("Erro na leitura do arquivo.\n");
#define ERRO_ALOCA_MEM printf("Erro na alocacao de memoria.\n");

typedef struct aluno{
	char matricula[MAX_MAT];
	char nome[MAX_NOME];
}Aluno;

typedef struct hash{
	Aluno aluno;
	int colisao;
}Hash;

/*Protótipos das Funções*/
void readFile(Aluno **alunos, char *nameFile, char *typeFile, int sizeData, int *qtdData);
int funcaoHash(Aluno *aluno, int tamArray, int indice);

int main(){
	
	Aluno *pAlunos = NULL;
	int qtdAlunos = 0;
	int i = 0, j = 0;
	Hash arrayAlunos[TAM_ARRAY];
	int qtdColisoes=0;
	
	setlocale(LC_ALL,"Portuguese");
	
	readFile(&pAlunos,"alunos.dat","rb",sizeof(Aluno),&qtdAlunos);
	
	for(i=0;i<qtdAlunos;i++){
		j = funcaoHash(pAlunos+i,TAM_ARRAY,i);
		//Colocando dados do aluno na chave gerada
		arrayAlunos[j].aluno = pAlunos[i];
		
		//Fazendo a contagem de colisões
		if(arrayAlunos[j].colisao == 1){
			qtdColisoes++;
		}else{
			arrayAlunos[j].colisao = 1;
		}	
	}
	
	free(pAlunos);
	
	printf("Tamanho do Array -> %d - Qtd Colisões -> %d\n", TAM_ARRAY, qtdColisoes);getch();
	
	
	return 0;
}

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

/*Objetivo: função hash para armazenar dados, por meio da matricula gerando um indice
Entrada: dados de um aluno 
Retorno: índice para armazenamento
*/

int funcaoHash(Aluno *aluno, int tamArray, int indice){
	
	int j=0;
	char chave[TAM_KEY+1];
	int auxChave=0;

	for(j=0;j<TAM_KEY;j++){
		chave[j] = aluno->matricula[strlen(aluno->matricula)-j-1];
	}
	
	for(j=0;j<TAM_KEY;j++){
		auxChave += (int)chave[j];
	}

	return auxChave % (tamArray-indice);	
		
}
