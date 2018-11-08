/*Síntese - Lucas Henrique
Objetivo: criar um funcao hash de acordo com as palavras de uma estrutura
Entrada: estrutura com as palavras
Saída: quantidade de cadastros até que ocorra uma colisão
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_WORD 15
#define TAM_VETOR 15
#define QTD_WORDS 10

//Structs
typedef struct{
	char wordPortuguese[TAM_WORD];
	char wordEnglish[TAM_WORD];
}Dicionario;

typedef struct {
	Dicionario words;
	int ocupado;
}ArrayDicionario;

int funcaoHash(Dicionario *words);
void readFile(Dicionario *words);

int main(){
	
	int i = 0;
	int index = 0;
	int qtdRegistros = 0;
	ArrayDicionario words[TAM_VETOR];
	Dicionario auxWord;
	
	while(i < QTD_WORDS){
		readFile(&auxWord);
		index = funcaoHash(&auxWord);
		printf("%d\n", index);getch();
		if(words[index].ocupado!=1){
			words[index].words = auxWord;
			words[index].ocupado = 1; 
			qtdRegistros++;
		}else{
			break;
		}
		i++;
	}
	
	printf("Tamanho do Vetor %d - Quantidade de Registros -> %d\n", TAM_VETOR,qtdRegistros);getch();
	
	return 0;
}

/*Objetivo: gerar um indice hash de acordo com as palavras de cada estrutura
Parâmetros: estrutura dicionarios
Retorno: indice
*/

int funcaoHash(Dicionario *words){
	
	int indice = 0;
	int i = 0;
	
	for(i=0;i<strlen(words->wordEnglish);i++){
		indice += (int) words->wordEnglish[i];
	} 
	
	for(i=0;i<strlen(words->wordPortuguese);i++){
		indice += (int) words->wordPortuguese[i];
	}
	
	if(indice % 2 == 0){
		indice += 17;
	}else if(indice % 10 == 0){
		indice /= 3;
	}else{
		indice /= 2;
	}
	
	return indice % TAM_VETOR;
}

/*Objetivo: ler arquivo para teste
Parâmetros: estrutura de dicionario
Retorno: nenhum
*/

void readFile(Dicionario *words){
	
	FILE *f;
	static int posicaoFile = 0;
	
	f = fopen("palavrasTeste.dat","rb");
	
	fseek(f, posicaoFile * sizeof(Dicionario),SEEK_SET);
	
	if(f == NULL){
		printf("Problema no arquivo\n");getch();
		exit(0);
	}

	fread(words,sizeof(Dicionario),1,f);
	posicaoFile++;
	
	fclose(f);
	
}
