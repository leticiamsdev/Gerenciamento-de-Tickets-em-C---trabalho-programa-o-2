#include "software.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * Estrutura de um Ticket Software contendo os parametros especificos de um ticket do tipo SOFTWARE
 */
struct Software{
    char *nome;
    char *categoria; //bug, duvida, outros
    int impacto;//3, 2, 1 == alto, medio, baixo
    char *motivo;//motivo da abertura do ticket
    int tempoEstimado; // Tempo estimado para resolver o ticket
};

/**
 * @brief Aloca uma estrutura Software na memória e inicializa os parâmetro necessários
 * @param nome Nome do software
 * @param categoria Categoria do software
 * @param impacto Impacto do chamado
 * @param motivo Motivo da abertura do ticket
 * @return  Uma estrutura Software inicializada.
 */
Software *criaSoftware(char *nome, char *categoria, int impacto, char *motivo){
    if(nome== NULL || categoria==NULL || motivo==NULL){
        printf("erroleitura\n");
    }
    Software *s = (Software *)malloc(sizeof(Software));
    s->nome = (char *)malloc((strlen(nome)+1)*sizeof(char));
    strcpy(s->nome, nome);
    s->categoria = (char *)malloc((strlen(categoria)+1)*sizeof(char));
    strcpy(s->categoria, categoria);
    s->impacto = impacto;
    s->motivo = (char *)malloc((strlen(motivo)+1)*sizeof(char));
    strcpy(s->motivo, motivo);
    s->tempoEstimado = 0;//cuidado com isso;
    return s;
}

/**
 * @brief Lê da entrada padrão um  ticket do TIPO software
 * @return  Um chamado do Tipo Software
 */
Software *lerSoftware(){
    char nome[MAX_TAM_NOME_SOFTWARE] = {0};
    char categoria[MAX_TAM_CAT]= {0};
    int impacto;
    char motivo[MAX_TAM_MOTIVO]= {0};
    strcpy(nome,"\0");
    strcpy(categoria,"\0");
    strcpy(motivo,"\0");
    scanf("%[^\n]", nome);

    scanf(" %[^\n]", categoria);
    scanf("%d", &impacto);
    scanf(" %[^\n]", motivo);
    // printf("%s %s %s %d", nome, categoria, motivo, impacto);
    return criaSoftware(nome, categoria, impacto, motivo);
}

/**
 * @brief  Calcula o tempo estimado para resolver um ticket do tipo Software.
 * Tempo estimado depende da categoria e impacto
 * @param s  Ticket do tipo Software
 */
void setTempoEstimadoSoftware(Software *s){
    if(strcmp(s->categoria, "BUG") == 0){
        s->tempoEstimado = TEMPO_ESTIMADO_BUG + s->impacto;
    }else if(strcmp(s->categoria, "DUVIDA") == 0){
        s->tempoEstimado = TEMPO_ESTIMADO_DUVIDA + s->impacto;
    }else if(strcmp(s->categoria, "OUTROS") == 0){
        s->tempoEstimado = TEMPO_ESTIMADO_OUTROS + s->impacto;
    }
}

/**
 * @brief  Retorna o tempo estimado para resolver um ticket do tipo Software.
 * @param dado  Ticket do tipo Software
 * @return  Tempo estimado para resolver um ticket do tipo Software
 */
int getTempoEstimadoSoftware(void *dado){
    Software *s = (Software *)dado;
    return s->tempoEstimado;
}

/**
 * @brief  Retorna o tipo do ticket
 * @return  'S' para Software
 */
char getTipoSoftware(){
    return 'S';
}

/**
 * @brief  Desaloca um ticket do tipo Software da memória
 * @param s  Ticket do tipo Software
 */
void desalocaSoftware(void *s){
    Software *soft = (Software *)s;
    free(soft->nome);
    free(soft->categoria);
    free(soft->motivo);
    free(soft);
}

/**
 * @brief  Imprime um ticket do tipo Software
 * @param dado  Ticket do tipo Software
 */
void notificaSoftware(void *dado){
    Software *s = (Software *)dado;
    printf("- Tipo: Software\n");
    printf("- Nome do software: %s\n", s->nome);
    printf("- Categoria: %s\n", s->categoria);
    printf("- Nível do impacto: %d\n", s->impacto);
    printf("- Motivo: %s\n", s->motivo);
    setTempoEstimadoSoftware(s);
    printf("- Tempo estimado: %dh\n", s->tempoEstimado);
}
