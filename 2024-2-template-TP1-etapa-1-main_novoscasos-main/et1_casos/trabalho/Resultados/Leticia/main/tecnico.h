#ifndef _TECNICO_H
#define _TECNICO_H

#include "atores.h"

#define MAX_TAM_AREA_ATUACAO 10


/**
 * Estrutura de um  Tecnico contendo os parametros especificos de um tipo Tecnico
 */
typedef struct Tecnico Tecnico;

/**
 * @brief Aloca uma estrutura Tecnico na memória e inicializa os parâmetro necessários
 * @param a especificaçoes Tecnico
 * @param areaAtuacao area de atuacao do Tecnico
 * @param salario salario do Tecnico(em float)
 * @param disponibilidade quantidade de tempo que o tecnico vai trabalhar
 * @return  Uma estrutura Tecnico inicializada.
 */
Tecnico *criaTecnico(Ator* a, char *areaAtuacao, int disponibilidade, float salario);

/**
 * @brief Lê da entrada padrão TIPO Tecnico
 * @return  Um Tipo Tecnico
 */
Tecnico *lerTecnico();

/**
 * @param s  struct Tecnico
 * @return  retorna cpf do Tecnico
 */
char* getCPF_T(Tecnico *s);

/**
 * @param s  struct Tecnico
 * @return  retorna disponibilidade do Tecnico
 */
int getDisponibilidade(Tecnico *s);

/**
 * @param s  struct Tecnico
 * @return  retorna tempoTrabalhado do Tecnico
 */
int getTempoTrabalhado(Tecnico *s);

/**
 * @param s  struct Tecnico
 * @brief Modifica a disponibilidade do Tecnico
 */
void modificaDisponibilidade(Tecnico *s, int horas);


/**
 * @param s  struct Tecnico
 * @return  retorna salario do Tecnico
 */
float getSalario(Tecnico *s);

/**
 * @param s  struct Tecnico
 * @return  retorna area do Tecnico
 */
char* getAreaAtuacao(Tecnico *s);

/**
 * @brief  Desaloca tipo Tecnico da memória
 * @param s   tipo Tecnico
 */
void desalocaTecnico(void *s);

/**
 * @brief  Imprime tipo Tecnico
 * @param dado   do tipo Tecnico
 */
void imprimeTecnico(void *dado);

/**
 * @brief  Retorna idade do tipo Tecnico
 * @param dado   do tipo Tecnico
 */
int getIdadeTecnico(Tecnico *s);

/**
 * @brief  Retorna nome do tipo Tecnico
 * @param dado   do tipo Tecnico
 */
char* getNomeTecnico(Tecnico *s);



#endif