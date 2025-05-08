
#ifndef _DATA_H
#define _DATA_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>



/**
 * Struct que deve ser definido em data.c
 */

typedef struct Data Data;

/*
 * Função que lê uma data no formato dd/mm/aaaa
 * e retorna a Data lida
 */
Data*  lerData();

/*
 * Função que imprime uma data no formato dd/mm/aaaa
 * Com \n no final.
 */
void imprimeData(Data * d);

/*
 *   Função que compara se as duas datas são exatamente iguais
 *   Retorna 1 se verdadeiro e 0 caso contrário
 */
int comparaData(Data * d1, Data *d2);

/*
 *  Função que calcula a diferença de anos entre duas datas da mesma
 *  forma que calculamos aniversários.
 *  Retorna a diferença de anos entre as duas datas data fim 18/02/2025
 */
int calcularDiffAnosData(Data * inicio);

/*
 * Função que libera um struct Data da memória
 */
void desalocaData(Data * d);

#endif