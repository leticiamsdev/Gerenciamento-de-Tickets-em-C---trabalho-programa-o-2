
#ifndef _ATORES_H
#define _ATORES_H

#include "data.h"

#define MAX_TAM_NOME_ATORES 100
#define MAX_TAM_CPF_ATOR 20
#define MAX_TAM_GENERO 15
#define MAX_TAM_TELEFONE 17


/**
 * Estrutura de Ator contendo os parametros especificos de um tipo Ator
 */
typedef struct Ator Ator;

/**
 * @brief Aloca uma estrutura Ator na memória e inicializa os parâmetro necessários
 * @param nome Nome do Ator
 * @param categoria Categoria do Ator
 * @param impacto Impacto do chamado
 * @param motivo Motivo da abertura do ticket
 * @return  Uma estrutura Ator inicializada.
 */
Ator *criaAtor(char *nome, char *cpf, Data* dt, char *telefone, char *genero);

/**
 * @brief Lê da entrada padrão um   TIPO Ator
 * @return   Tipo Ator
 */
Ator *lerAtor();

/**
 * @param s   tipo Ator
 * @return  retorna cpf do Ator
 */
char* getCpf(void *a);

/**
 * @brief  Desaloca um  tipo Ator da memória
 * @param s   tipo Ator
 */
void desalocaAtor(void *s);

/**
 * @brief  Imprime um  tipo Ator
 * @param dado   tipo Ator
 */
void imprimeAtor(void *dado);
/**
 * @brief  retorna Idade do tipo Ator
 * @param dado   tipo Ator
 */
int getIdadeAtor(void *a);
/**
 * @brief  Retorna um ponteiro do nome do  tipo Ator
 * @param dado   tipo Ator
 */
char* getNome(Ator *a);

#endif