

#ifndef _MANTENCAO_H
#define _MANTENCAO_H

#define MAX_TAM_NOME_MANUTENCAO 100
#define MAX_TAM_ESTADO 20
#define MAX_TAM_LOCAL 100

#define TEMPO_ESTIMADO_RUIM 3
#define TEMPO_ESTIMADO_REGULAR 2
#define TEMPO_ESTIMADO_BOM 1
//SETOR DO USUARIO IMPACTA NO CALCULO DO TEMPO ESTIMADO
#define TEMPO_ESTIMADO_RH 2
#define TEMPO_ESTIMADO_FINANCEIRO 3
#define TEMPO_ESTIMADO_VENDAS 1
#define TEMPO_ESTIMADO_MARKETING 1
#define TEMPO_ESTIMADO_PED 1
/**
 * Estrutura de um Ticket Manutecao contendo os parametros especificos de um ticket do tipo Manutencao
 */
typedef struct Manutencao Manutencao;

/**
 * @brief Aloca uma estrutura Manutencao na memória e inicializa os parâmetro necessários
 * @param nome Nome do item a ser executado a Manutencao
 * @param estado Estado do item a ser executado a Manutencao(RUIM, REGULAR, BOM)
 * @param local O local exato onde se encontra o item
 * @return  Uma estrutura Manutencao inicializada.
 */
Manutencao *criaManutencao(char *nome, char *estado, char *local, char *setor);

/**
 * @brief Lê da entrada padrão um  ticket do TIPO Manutencao
 * @return  Um chamado do Tipo Manutencao
 */
Manutencao *lerManutencao(char* setor);

/**
 * @brief  Calcula o tempo estimado para resolver um ticket do tipo Manutencao.
 * Tempo estimado depende da conservacao do item e setor do usuario que abriu o ticket
 * @param s  Ticket do tipo Manutencao
 */
void setTempoEstimadoManutencao(Manutencao *s);

/**
 * @brief  Retorna o tempo estimado para resolver um ticket do tipo Manutencao.
 * @param dado  Ticket do tipo Manutencao
 * @return  Tempo estimado para resolver um ticket do tipo Manutencao
 */
int getTempoEstimadoManutencao(void *dado);

/**
 * @brief  Retorna o tipo do ticket
 * @return  'M' para Manutencao
 */
char getTipoManutencao();

/**
 * @brief  Desaloca um ticket do tipo Manutencao da memória
 * @param s  Ticket do tipo Manutencao
 */
void desalocaManutencao(void *s);

/**
 * @brief  Imprime um ticket do tipo Manutencao
 * @param dado  Ticket do tipo Manutencao
 */
void notificaManutencao(void *dado);

#endif