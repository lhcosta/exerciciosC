#ifndef _validacoes
#define _validacoes

#define ERRO_INT printf("ERRO! Digite apenas numeros\n");
#define ERRO_FLOAT printf("ERRO! Digite apenas numeros e ponto para casas decimais\n");
#define ERRO_QTD_NUM printf("ERRO! Quantidade Invalida!\n");

/*Prótotipos da Funções*/

void leValidaInt(int *num, int valorMin, int valorMax, char texto[20]);
void leValidaFloat(float *num, float valorMin, float valorMax, char texto[20]);
void leValidaNome(char texto[20], char *nome);

#endif
