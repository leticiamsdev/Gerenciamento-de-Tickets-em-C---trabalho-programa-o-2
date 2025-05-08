#include "usuario.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Usuario{
    Ator *a;
    char* setor;
    int qtdTickets;
};

/**
 * @brief Aloca uma estrutura Usuario na memória e inicializa os parâmetro necessários
 * @param a especificaçoes usuario
 * @param setor setor do trabalho do Usuario
 * @param qtdTickets quantidade de tickets abertos pelo Usuario
 * @return  Uma estrutura Usuario inicializada.
 */
Usuario *criaUsuario(Ator* a, char *setor){
    Usuario *u = (Usuario *)malloc(sizeof(Usuario));
    u->a = a;
    u->setor = (char *)malloc(sizeof(char) * (strlen(setor) + 1));
    strcpy(u->setor, setor);
    u->qtdTickets = 0;
    return u;
}

/**
 * @brief Lê da entrada padrão um  ticket do TIPO Usuario
 * @return  Um chamado do Tipo Usuario
 */
Usuario *lerUsuario(){
    Ator *a = lerAtor();
    char setor[MAX_TAM_SETOR_TRABALHO];
    scanf(" %[^\n]", setor);
    return criaUsuario(a, setor);
}

/**
 * @param s  Ticket do tipo Usuario
 * @return  retorna cpf do Usuario
 */
char* getCPF_U(Usuario *s){
    return getCpf(s->a);
}
/**
 * @brief  Desaloca tipo Usuario da memória
 * @param s  desaloca tipo Usuario
 */
void desalocaUsuario(void *s){
    Usuario *u = (Usuario *)s;
    desalocaAtor(u->a);
    free(u->setor);
    free(u);
}

/**
 * @brief  Imprime do tipo Usuario
 * @param dado   tipo Usuario
 */
void imprimeUsuario(void *dado){
    Usuario *u = (Usuario *)dado;
    imprimeAtor(u->a);
    printf("- Setor: %s\n", u->setor);
    printf("- Tickets solicitados: %d\n", u->qtdTickets);
}

void AumentaQtdTicketsUsuario(Usuario *u){
    u->qtdTickets++;
}

int getQtdTickets(Usuario *u){
    return u->qtdTickets;
}

char* getSetor(Usuario *u){
    return u->setor;
}

int getIdadeUsuario(Usuario *u){
    return getIdadeAtor(u->a);
}

char* getNomeUsuario(Usuario *u){
    return getNome(u->a);
}


