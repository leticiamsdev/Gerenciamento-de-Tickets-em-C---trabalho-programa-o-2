
#ifndef _USUARIO_H
#define _USUARIO_H

#include "atores.h"

#define MAX_TAM_SETOR_TRABALHO 15

/**
 * Estrutura de um  Usuario contendo os parametros especificos de um tipo Usuario
 */
typedef struct Usuario Usuario;

/**
 * @brief Aloca uma estrutura Usuario na memória e inicializa os parâmetro necessários
 * @param a especificaçoes usuario
 * @param setor setor do trabalho do Usuario
 * @param qtdTickets quantidade de tickets abertos pelo Usuario
 * @return  Uma estrutura Usuario inicializada.
 */
Usuario *criaUsuario(Ator* a, char *setor);

/**
 * @brief Lê da entrada padrão TIPO Usuario
 * @return  Um Tipo Usuario
 */
Usuario *lerUsuario();

/**
 * @param s  struct Usuario
 * @return  retorna cpf do Usuario
 */
char* getCPF_U(Usuario *s);
/**
 * @brief  Desaloca tipo Usuario da memória
 * @param s   tipo Usuario
 */
void desalocaUsuario(void *s);

/**
 * @brief  Imprime tipo Usuario
 * @param dado   do tipo Usuario
 */
void imprimeUsuario(void *dado);

/**
 * @brief  aumenta quantidade de tickets inseridas do tipo Usuario
 * @param dado   do tipo Usuario
 */
void AumentaQtdTicketsUsuario(Usuario *u);

/**
 * @brief  retorna quantidade de tickets inseridas do tipo Usuario
 * @param dado   do tipo Usuario
 */
int getQtdTickets(Usuario *u);

/**
 * @brief  retorna um ponteiro do setor do tipo Usuario
 * @param dado   do tipo Usuario
 */
char* getSetor(Usuario *u);

/**
 * @brief  retorna a idade do tipo Usuario
 * @param dado   do tipo Usuario
 */
int getIdadeUsuario(Usuario *u);

/**
 * @brief retorna um ponteiro de nome do tipo Usuario
 * @param dado   do tipo Usuario
 */
char* getNomeUsuario(Usuario *u);

#endif