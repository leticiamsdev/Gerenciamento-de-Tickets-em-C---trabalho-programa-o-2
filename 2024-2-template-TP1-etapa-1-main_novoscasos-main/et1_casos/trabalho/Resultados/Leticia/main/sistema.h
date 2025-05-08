
#ifndef _SISTEMA_H
#define _SISTEMA_H

#include "tecnico.h"
#include "fila.h"
#include "usuario.h"
#include "software.h"
#include "manutencao.h"
#include "outros.h"


/**
 * Estrutura de Sistema contendo os parametros especificos de um tipo Sistema
 */
typedef struct Sistema Sistema;

/**
 * @brief Aloca uma estrutura Sistema na memória e inicializa os parâmetro necessários
 * @param nome Nome do Sistema
 * @param categoria Categoria do Sistema
 * @param impacto Impacto do chamado
 * @param motivo Motivo da abertura do ticket
 * @return  Uma estrutura Sistema inicializada.
 */
Sistema *criaSistema();

/**
 * @param  s Sistema
 * @param  u Usuario
 */
void InsereUsuarioSistema(Sistema *s, Usuario *u);

/**
 * @param  s Sistema
 * @param  t Tecnico
 */
void InsereTecnicoSistema(Sistema *s, Tecnico *t);

/**
 * @param  s Sistema
 * @param  t Tecnico
 */
void InsereTicketFilaSistema(Sistema *s, char* cpfSol,void *t, func_ptr_tempoEstimado getTempo, func_ptr_tipo getTipo, func_ptr_notifica notifica, func_ptr_desaloca desaloca);

/**
 * @param s   tipo Sistema
 * @return  imprime tickets do Sistema
 */
void notificaFilaSistema(Sistema *s);

/**
 * @brief  Desaloca um  tipo Sistema da memória
 * @param s   tipo Sistema
 */
void desalocaSistema(Sistema *s);

/**
 * @brief  Imprime um  tipo Sistema
 * @param dado   tipo Sistema
 */
void relatorioSistema(Sistema *s);

/**
 * @brief  Imprime um usuarios do tipo Sistema
 * @param dado   tipo Sistema
 */
void imprimeUsuarioSistema(Sistema *s);

/**
 * @brief  Imprime um tecnicos do tipo Sistema
 * @param dado   tipo Sistema
 */
void imprimeTecnicosSistema(Sistema *s);


/**
 * @brief  Imprime um ranking tecnicos do tipo Sistema
 * @param dado   tipo Sistema
 */
void imprimeRankingTecnicosSistema(Sistema *s);


/**
 * @brief  Imprime um ranking usuarios do tipo Sistema
 * @param dado   tipo Sistema
 */
void imprimeRankingUsuariosSistema(Sistema *s);


/**
 * @brief  cadastra ticket na fila do tipo Sistema
 * @param dado   tipo Sistema
 */
void CadastraTicket(Sistema *s);

/**
 * @brief  distribui ticket aberto na fila para o tecnico do tipo Sistema
 * @param dado   tipo Sistema
 */
void DistribuiTicket(Sistema *s);

#endif