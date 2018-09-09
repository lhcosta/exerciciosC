#ifndef _alunos
#define _alunos

#define MAX_NOME 30

struct aluno{
	char nome[MAX_NOME];
	int matricula;
	float n1,n2;
};


/*Protótipos de Funções*/
void cadastraAluno(char nameFile[]);
void apresentaAlunos(char nameFile[]);

#endif
