#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "outros.h"
struct Outros{
    char *descricao;
    char *local;
    int dificuldade;
};

/**
 * @brief Aloca uma estrutura Outros na memória e inicializa os parâmetro necessários
 * @param descricao descricao do Outros
 * @param local local do Outros
 * @param dificuldade dificuldade do Outros == tempos estimado para solucionar
 * @return  Uma estrutura Outros inicializada.
 */
Outros *criaOutros(char *descricao, char *local, int dificuldade){
    Outros *o = (Outros *)malloc(sizeof(Outros));
    o->descricao = (char *)malloc((strlen(descricao)+1)*sizeof(char));
    strcpy(o->descricao, descricao);
    o->local = (char *)malloc((strlen(local)+1)*sizeof(char));
    strcpy(o->local, local);
    o->dificuldade = dificuldade;
    return o;
}

/**
 * @brief Lê da entrada padrão um  ticket do TIPO Outros
 * @return  Um chamado do Tipo Outros
 */
Outros *lerOutros(){
    char descricao[MAX_TAM_NOME_DESCRICAO];
    char local[MAX_TAM_LOCAL];
    int dificuldade;
    scanf(" %[^\n]", descricao);
    scanf(" %[^\n]", local);
    scanf(" %d ", &dificuldade);
    return criaOutros(descricao, local, dificuldade);
}

/**
 * @brief  Retorna o tempo estimado para resolver um ticket do tipo Outros.
 * @param dado  Ticket do tipo Outros
 * @return  Tempo estimado para resolver um ticket do tipo Outros
 */
int getTempoEstimadoOutros(void *dado){
    Outros *o = (Outros *)dado;
    return o->dificuldade;
}

/**
 * @brief  Retorna o tipo do ticket
 * @return  'O' para Outros
 */
char getTipoOutros(){
    return 'O';
}

/**
 * @brief  Desaloca um ticket do tipo Outros da memória
 * @param s  Ticket do tipo Outros
 */
void desalocaOutros(void *s){
    Outros *out = (Outros *)s;
    free(out->descricao);
    free(out->local);
    free(out);
}

/**
 * @brief  Imprime um ticket do tipo Outros
 * @param dado  Ticket do tipo Outros
 */
void notificaOutros(void *dado){
    Outros *o = (Outros *)dado;
    printf("- Tipo: Outros\n");
    printf("- Descricao: %s\n", o->descricao);
    printf("- Local: %s\n", o->local);
    printf("- Nivel de Dificuldade: %d\n", o->dificuldade);
    printf("- Tempo Estimado: %dh\n", o->dificuldade);
}
