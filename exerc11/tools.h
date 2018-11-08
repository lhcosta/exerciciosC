/*
 * - comuns.h
 * - header de funções comuns usadas em vários códigos
 * 
 * Created by José Adalberto F. Gualeve  on 09/08/18.
 * Copyright 2018 - All rights reserved 
*/
#ifndef TOOLS_H
#define TOOLS_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int menu(int nopcoes, char *opcoes[]);
void ajustaEOL(char texto[], int tamanho);
void listar(int vet[], int tam);

#endif

