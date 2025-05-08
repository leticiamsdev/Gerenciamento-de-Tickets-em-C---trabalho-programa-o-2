#include "atores.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Estrutura de um Ticket Ator contendo os parametros especificos de um ticket do tipo Ator
 */
struct Ator{
    char *nome;
    char *cpf;
    Data *dtNasc;
    char *telefone;
    char *genero;
};

/**
 * @brief Aloca uma estrutura Ator na memória e inicializa os parâmetro necessários
 * @param nome Nome do Ator
 * @param categoria Categoria do Ator
 * @param impacto Impacto do chamado
 * @param motivo Motivo da abertura do ticket
 * @return  Uma estrutura Ator inicializada.
 */
Ator *criaAtor(char *nome, char *cpf, Data* dtNasc, char *telefone, char *genero){
    Ator *s = (Ator *)malloc(sizeof(Ator));
    s->nome = (char *)malloc((strlen(nome)+1)*sizeof(char));
    strcpy(s->nome, nome);
    s->cpf = (char *)malloc((strlen(cpf)+1)*sizeof(char));
    strcpy(s->cpf, cpf);
    s->dtNasc = dtNasc;
    s->telefone = (char *)malloc((strlen(telefone)+1)*sizeof(char));
    strcpy(s->telefone, telefone);
    s->genero = (char *)malloc((strlen(genero)+1)*sizeof(char));
    strcpy(s->genero, genero);
    return s;
}

/**
 * @brief Lê da entrada padrão um  ticket do TIPO Ator
 * @return  Um chamado do Tipo Ator
 */
Ator *lerAtor(){
    char nome[MAX_TAM_NOME_ATORES];
    char cpf[MAX_TAM_CPF_ATOR];
    char telefone[MAX_TAM_TELEFONE];
    char genero[MAX_TAM_GENERO];
    scanf(" %[^\n]", nome);
    scanf(" %[^\n]", cpf);
    Data *dt = lerData();
    scanf(" %[^\n]", telefone);
    scanf(" %[^\n]", genero);
    return criaAtor(nome, cpf, dt, telefone, genero);
}

/**
 * @param s  Ticket do tipo Ator
 * @return  retorna cpf do Ator
 */
char* getCpf(void *a){
    Ator *s = (Ator *)a;
    return s->cpf;
}

/**
 * @brief  Desaloca um ticket do tipo Ator da memória
 * @param s  Ticket do tipo Ator
 */
void desalocaAtor(void *s){
    Ator *a = (Ator *)s;
    if(a != NULL){
        free(a->nome);
        free(a->cpf);
        desalocaData(a->dtNasc);
        free(a->telefone);
        free(a->genero);
        free(a);
    }
}

/**
 * @brief  Imprime um ticket do tipo Ator
 * @param dado  Ticket do tipo Ator
 */
void imprimeAtor(void *dado){
    Ator *a =  (Ator *)dado;
    printf("- Nome: %s\n", a->nome);
    printf("- CPF: %s\n", a->cpf);
    printf("- Data de Nascimento: ");
    imprimeData(a->dtNasc);
    printf("- Telefone: %s\n", a->telefone);
    printf("- Genero: %s\n", a->genero);
}

int getIdadeAtor(void *a){
    Ator *s = (Ator *)a;
    return calcularDiffAnosData(s->dtNasc);
}

char* getNome(Ator *a){
    return a->nome;
}