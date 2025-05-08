

#ifndef _OUTROS_H
#define _OUTROS_H


#define MAX_TAM_NOME_DESCRICAO 500
#define MAX_TAM_LOCAL 100




/**
 * Estrutura de um Ticket Outros contendo os parametros especificos de um ticket do tipo Outros
 */
typedef struct Outros Outros;

/**
 * @brief Aloca uma estrutura Outros na memória e inicializa os parâmetro necessários
 * @param descricao descricao do Outros
 * @param local local do Outros
 * @param dificuldade dificuldade do Outros == tempos estimado para solucionar
 * @return  Uma estrutura Outros inicializada.
 */
Outros *criaOutros(char *descricao, char *local, int dificuldade);

/**
 * @brief Lê da entrada padrão um  ticket do TIPO Outros
 * @return  Um chamado do Tipo Outros
 */
Outros *lerOutros();

/**
 * @brief  Retorna o tempo estimado para resolver um ticket do tipo Outros.
 * @param dado  Ticket do tipo Outros
 * @return  Tempo estimado para resolver um ticket do tipo Outros
 */
int getTempoEstimadoOutros(void *dado);

/**
 * @brief  Retorna o tipo do ticket
 * @return  'O' para Outros
 */
char getTipoOutros();

/**
 * @brief  Desaloca um ticket do tipo Outros da memória
 * @param s  Ticket do tipo Outros
 */
void desalocaOutros(void *s);

/**
 * @brief  Imprime um ticket do tipo Outros
 * @param dado  Ticket do tipo Outros
 */
void notificaOutros(void *dado);

#endif