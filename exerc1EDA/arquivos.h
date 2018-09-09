#ifndef _arquivos
#define _arquivos

#include "alunos.h"

#define ERRO_FILE printf("ERRO! Na criacao ou escrita do arquivo!\n");

/*Protótipos de Funções*/

int existe_file(char nameFile[]);
void cria_file(char nameFile[]);	
void writeInFile(struct aluno *dadosAluno, char nameFile[]);
void readFile(struct aluno **dadosAluno, char nameFile[], int *qtdAlunos);


#endif
