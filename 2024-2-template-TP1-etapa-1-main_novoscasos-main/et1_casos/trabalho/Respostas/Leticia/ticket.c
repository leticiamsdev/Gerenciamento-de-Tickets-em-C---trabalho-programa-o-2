#include "ticket.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * Estrutura de um Ticket contendo os parametros comuns entre todos os tipos de Tickets e um tipo genérico.
 */
struct Ticket{
    void* dado;
    char* cpfSol;
    char status;
    char* id;
    func_ptr_desaloca desaloca;
    func_ptr_notifica notifica;
    func_ptr_tempoEstimado getTempo;
    func_ptr_tipo getTipo;
};


/**
 * @brief Aloca uma estrutura Ticket na memória e inicializa os parâmetro necessários
 * @param cpfSol CPF de quem está solicitando a abertura do ticket
 * @param dado   Um ticket genérico  (considerando que existe mais de um tipo de ticket)
 * @param getTempo  Função de callback que retorna o tempo para aquele ticket ser resolvido
 * @param getTipo   Função de callback que retorna o tipo do ticket ser resolvido
 * @param notifica  Função de callback de notificação  (impressãode um ticket
 * @param desaloca  Função de callback que irá desalocar  um ticket da memória
 * @return  Uma estrutura Ticket inicializada.
 */
Ticket *criaTicket(char *cpfSol, void *dado, func_ptr_tempoEstimado getTempo,
                   func_ptr_tipo getTipo, func_ptr_notifica notifica, func_ptr_desaloca desaloca){
    Ticket *t = (Ticket *)malloc(sizeof(Ticket));
    t->cpfSol = (char *)malloc((strlen(cpfSol)+1)*sizeof(char));
    strcpy(t->cpfSol, cpfSol);
    t->dado = dado;//memcpy, nao sei se ta certo
    t->status = 'A';
    t->id = NULL;
    t->desaloca = desaloca;
    t->notifica = notifica;
    t->getTempo = getTempo;
    t->getTipo = getTipo;
    return t;
                   }

/**
 * @brief Atribui um ID a um ticket
 * @param d Ticket inicializado
 * @param id ID a ser atribuido ao ticket
 */
void setIDTicket(Ticket *d, char *id){
    d->id = (char *)malloc((strlen(id)+1)*sizeof(char));
    strcpy(d->id, id);
}

/**
 * @brief Finaliza um ticket
 * @param t Ticket inicializado
 */
void finalizaTicket(Ticket *t){
    t->status = 'F';
}

/**
 * @brief Recupera o CPF de quem solicitou a abertura do ticket
 * @param t Ticket inicializado
 * @return CPF de quem solicitou a abertura do ticket
 */
char *getCPFSolicitanteTicket(Ticket *t){
    return t->cpfSol;
}

/**
 * @brief Recupera o tempo estimado para resolver um ticket
 * @param t Ticket inicializado
 * @return tempo estimado para resolver um ticket
 */
int getTempoEstimadoTicket(Ticket *t){
    return t->getTempo(t->dado);
}

/**
 * @brief Recupera o tipo de um ticket
 * @param t Ticket inicializado
 * @return tipo do Ticket
 */
char getTipoTicket(Ticket *t){
    return t->getTipo();
}

/**
 * @brief Recupera o status de um ticket
 * @param t Ticket inicializado
 * @return status do Ticket
 */
char getStatusTicket(Ticket *t){
    return t->status;
}

/**
 * @brief  Desaloca um ticket da memória
 * @param doc estrutura do tipo Ticket que deve ser liberada da memória
 */
void desalocaTicket(Ticket *doc){
    doc->desaloca(doc->dado);
    free(doc->cpfSol);
    // free(doc->status);
    free(doc->id);
    free(doc);
}

/**
 * @brief  Notifica (imprime) um ticket
 * @param doc Ticket a ser notificado
 */
void notificaTicket(Ticket *doc){
    printf("---------TICKET-----------\n");
    printf("- ID: %s\n", doc->id);
    printf("- Usuario solicitante: %s\n", doc->cpfSol);
    doc->notifica(doc->dado);
    if(doc->status == 'A'){
        printf("- Status: Aberto\n");
    }else{
        printf("- Status: Finalizado\n");
    }
    printf("-------------------------\n\n");
}