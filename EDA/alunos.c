#include "alunos.h"
#include "arquivos.h"
#include "validacoes.h"
#include <stdio.h>
#include <malloc.h>

//Objetivo: cadastrar cada aluno
//Parâmetros: nome do arquivo que será armazenado os dados
//Retorno: nenhum

void cadastraAluno(char nameFile[]){
	
	struct aluno aluno;
	
	printf("CADASTRO DOS ALUNOS\n\n");
	leValidaNome("Nome do Aluno: ", aluno.nome);
	leValidaInt(&aluno.matricula,1,1000,"Matricula: ");
	leValidaFloat(&aluno.n1,0,10,"Nota 1: ");	
	leValidaFloat(&aluno.n2,0,10,"Nota 2: ");
	
	writeInFile(&aluno,nameFile);
	
}

//Objetivo: listar todos os alunos cadastrados no arquivo
//Parâmetros: nome do arquivo
//Retorno: nenhum

void apresentaAlunos(char nameFile[]){
	
	struct aluno *alunos;
	int qtdAlunos=0,i=0,j=0;
	
	readFile(&alunos,nameFile,&qtdAlunos);
	
	printf("ALUNOS\n\n");
	printf("NOME       MATRICULA  N1    N2\n\n");
	for(i=0;i<qtdAlunos;i++){
		printf("%-11s %5d    %5.2f %5.2f\n", alunos[i].nome, alunos[i].matricula,alunos[i].n1,alunos[i].n2);
	}
	
	free(alunos);
	
}
