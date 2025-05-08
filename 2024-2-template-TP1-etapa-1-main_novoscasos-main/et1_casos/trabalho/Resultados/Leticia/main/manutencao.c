#include "manutencao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include "usuario.h"

/**
 * Estrutura de um Ticket Manutecao contendo os parametros especificos de um ticket do tipo Manutencao
 */
struct Manutencao{
    char *nome;
    char *estado;
    char *local;
    int tempoEstimado; // Tempo estimado para resolver o ticket 
    //setor do usuario impacta no calculo do tempo estimado
    char *setor;
};

/**
 * @brief Aloca uma estrutura Manutencao na memória e inicializa os parâmetro necessários
 * @param nome Nome do item a ser executado a Manutencao
 * @param estado Estado do item a ser executado a Manutencao(RUIM, REGULAR, BOM)
 * @param local O local exato onde se encontra o item
 * @return  Uma estrutura Manutencao inicializada.
 */
Manutencao *criaManutencao(char *nome, char *estado, char *local, char *setor){

    Manutencao *m = (Manutencao *)malloc(sizeof(Manutencao));
    m->nome = (char *)malloc((strlen(nome)+1)*sizeof(char));
    strcpy(m->nome, nome);
    m->estado = (char *)malloc((strlen(estado)+1)*sizeof(char));
    strcpy(m->estado, estado);
    m->local = (char *)malloc((strlen(local)+1)*sizeof(char));
    strcpy(m->local, local);
if(setor != NULL){  
    m->setor = (char *)malloc((strlen(setor)+1)*sizeof(char));
    strcpy(m->setor, setor);


    

}else{
    printf("setor nulo\n");
    m->setor = NULL;
}

    setTempoEstimadoManutencao(m);
    return m;
}

/**
 * @brief Lê da entrada padrão um  ticket do TIPO Manutencao
 * @return  Um chamado do Tipo Manutencao
 */
Manutencao *lerManutencao(char* setor){
    char nome[MAX_TAM_NOME_MANUTENCAO];
    
    char estado[MAX_TAM_ESTADO];

    char local[MAX_TAM_LOCAL];
    strcpy(nome,"\0");
    strcpy(estado,"\0");
    strcpy(local,"\0");
    scanf("%[^\n]", nome);
    scanf(" %[^\n]", estado);
    scanf(" %[^\n]", local);
    return criaManutencao(nome, estado, local, setor);
}

/**
 * @brief  Calcula o tempo estimado para resolver um ticket do tipo Manutencao.
 * Tempo estimado depende da conservacao do item e setor do usuario que abriu o ticket
 * @param s  Ticket do tipo Manutencao
 */
void setTempoEstimadoManutencao(Manutencao *s){
    if(strcmp(s->estado, "RUIM") == 0){
        if(strcmp(s->setor, "RH") == 0){
            s->tempoEstimado = TEMPO_ESTIMADO_RUIM * TEMPO_ESTIMADO_RH;
        }else if(strcmp(s->setor, "FINANCEIRO") == 0){
            s->tempoEstimado = TEMPO_ESTIMADO_FINANCEIRO * TEMPO_ESTIMADO_RUIM;
        }else if(strcmp(s->setor, "VENDAS") == 0){
            s->tempoEstimado = TEMPO_ESTIMADO_VENDAS * TEMPO_ESTIMADO_RUIM;
        }else if(strcmp(s->setor, "MARKETING") == 0){
            s->tempoEstimado = TEMPO_ESTIMADO_MARKETING * TEMPO_ESTIMADO_RUIM;
        }else if(strcmp(s->setor, "P&D") == 0){
            s->tempoEstimado = TEMPO_ESTIMADO_PED * TEMPO_ESTIMADO_RUIM;
        }
    }else if(strcmp(s->estado, "REGULAR") == 0){
        if(strcmp(s->setor, "RH") == 0){
            s->tempoEstimado = TEMPO_ESTIMADO_RH * TEMPO_ESTIMADO_REGULAR;
        }else if(strcmp(s->setor, "FINANCEIRO") == 0){
            s->tempoEstimado = TEMPO_ESTIMADO_FINANCEIRO * TEMPO_ESTIMADO_REGULAR;
        }else if(strcmp(s->setor, "VENDAS") == 0){
            s->tempoEstimado = TEMPO_ESTIMADO_VENDAS * TEMPO_ESTIMADO_REGULAR;
        }else if(strcmp(s->setor, "MARKETING") == 0){
            s->tempoEstimado = TEMPO_ESTIMADO_MARKETING * TEMPO_ESTIMADO_REGULAR;
        }else if(strcmp(s->setor, "P&D") == 0){
            s->tempoEstimado = TEMPO_ESTIMADO_PED   * TEMPO_ESTIMADO_REGULAR;
        }
    }else if(strcmp(s->estado, "BOM") == 0){
        if(strcmp(s->setor, "RH") == 0){
            s->tempoEstimado = TEMPO_ESTIMADO_RH * TEMPO_ESTIMADO_BOM;
        }else if(strcmp(s->setor, "FINANCEIRO") == 0){
            s->tempoEstimado = TEMPO_ESTIMADO_FINANCEIRO * TEMPO_ESTIMADO_BOM;
        }else if(strcmp(s->setor, "VENDAS") == 0){
            s->tempoEstimado = TEMPO_ESTIMADO_VENDAS * TEMPO_ESTIMADO_BOM;
        }else if(strcmp(s->setor, "MARKETING") == 0){
            s->tempoEstimado = TEMPO_ESTIMADO_MARKETING * TEMPO_ESTIMADO_BOM;
        }else if(strcmp(s->setor, "P&D") == 0){
            s->tempoEstimado = TEMPO_ESTIMADO_PED * TEMPO_ESTIMADO_BOM;
        }
    }
    //talvez isso abaixo der errado
}

/**
 * @brief  Retorna o tempo estimado para resolver um ticket do tipo Manutencao.
 * @param dado  Ticket do tipo Manutencao
 * @return  Tempo estimado para resolver um ticket do tipo Manutencao
 */
int getTempoEstimadoManutencao(void *dado){
    Manutencao *m = (Manutencao *)dado;
    return m->tempoEstimado;
}

/**
 * @brief  Retorna o tipo do ticket
 * @return  'M' para Manutencao
 */
char getTipoManutencao(){
    return 'M';
}

/**
 * @brief  Desaloca um ticket do tipo Manutencao da memória
 * @param s  Ticket do tipo Manutencao
 */
void desalocaManutencao(void *s){
    Manutencao *manut = (Manutencao *)s;
    free(manut->nome);
    free(manut->estado);
    free(manut->local);
    free(manut->setor);
    free(manut);
}

/**
 * @brief  Imprime um ticket do tipo Manutencao
 * @param dado  Ticket do tipo Manutencao
 */
void notificaManutencao(void *dado){
    Manutencao *m = (Manutencao *)dado;
    printf("- Tipo: Manutencao\n");
    printf("- Nome do item: %s\n", m->nome);
    printf("- Estado de conservacao: %s\n", m->estado);
    printf("- Local: %s\n", m->local);
    getTempoEstimadoManutencao(m);
    printf("- Tempo estimado: %dh\n", m->tempoEstimado);
}

