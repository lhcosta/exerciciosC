#ifndef _alunos
#define _alunos

#define MAX_NOME 30

struct aluno{
	char nome[MAX_NOME];
	int matricula;
	float n1,n2;
};


/*Prot�tipos de Fun��es*/
void cadastraAluno(char nameFile[]);
void apresentaAlunos(char nameFile[]);

#endif
