#include "sistema.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Estrutura de Sistema contendo os parametros especificos de um tipo Sistema
 */
struct Sistema {
    Tecnico** tecnicos;
    Fila* fila;
    Usuario** usuarios;
    int qtdTecnicos;
    int qtdUsuarios;

};

/**
 * @brief Aloca uma estrutura Sistema na memória e inicializa os parâmetro necessários
 * @param nome Nome do Sistema
 * @param categoria Categoria do Sistema
 * @param impacto Impacto do chamado
 * @param motivo Motivo da abertura do ticket
 * @return  Uma estrutura Sistema inicializada.
 */
Sistema *criaSistema(){
    Sistema *s = (Sistema*)malloc(sizeof(Sistema));
    s->fila = criaFila();
    s->qtdTecnicos = 0;
    s->qtdUsuarios = 0;
    s->tecnicos = (Tecnico**)malloc(sizeof(Tecnico*));
    s->usuarios = (Usuario**)malloc(sizeof(Usuario*));
    return s;
}

/**
 * @param  s Sistema
 * @param  u Usuario
 */
void InsereUsuarioSistema(Sistema *s, Usuario *u){
    //caso em que ja existe usuriao com o cpf
    for(int i = 0; i < s->qtdUsuarios; i++){
        if(strcmp(getCPF_U(s->usuarios[i]), getCPF_U(u)) == 0){
            desalocaUsuario(u);
            return;
        }
    }
    if(s->qtdUsuarios == 0){
        s->usuarios[0] = u;
        s->qtdUsuarios++;
    }else{
        s->qtdUsuarios++;
        s->usuarios = realloc(s->usuarios, s->qtdUsuarios * sizeof(Usuario*));
        s->usuarios[s->qtdUsuarios-1] = u;
    }
}

/**
 * @param  s Sistema
 * @param  t Tecnico
 */
void InsereTecnicoSistema(Sistema *s, Tecnico *t){
    if(s->qtdTecnicos == 0){
        s->tecnicos[0] = t;
        s->qtdTecnicos++;
    }else{
        s->qtdTecnicos++;
        s->tecnicos = realloc(s->tecnicos, s->qtdTecnicos * sizeof(Tecnico*));
        s->tecnicos[s->qtdTecnicos-1] = t;
    }
}

/**
 * @param  s Sistema
 * @param  t Tecnico
 */
void InsereTicketFilaSistema(Sistema *s, char* cpfSol,void *t, func_ptr_tempoEstimado getTempo, func_ptr_tipo getTipo, func_ptr_notifica notifica, func_ptr_desaloca desaloca){
    insereTicketFila(s->fila, cpfSol, t, getTempo,getTipo, notifica, desaloca);
}

/**
 * @param s   tipo Sistema
 * @return  imprime tickets do Sistema
 */
void notificaFilaSistema(Sistema *s){
    printf("----- FILA DE TICKETS -----\n");
    notificaFila(s->fila);
    printf("---------------------------\n\n");
}

/**
 * @brief  Desaloca um  tipo Sistema da memória
 * @param s   tipo Sistema
 */
void desalocaSistema(Sistema *s){
    for(int i = 0; i < s->qtdTecnicos; i++){
        desalocaTecnico(s->tecnicos[i]);
    }
    for(int i = 0; i < s->qtdUsuarios; i++){
        desalocaUsuario(s->usuarios[i]);
    }
    desalocaFila(s->fila);
    free(s->tecnicos);
    free(s->usuarios);
    free(s);
}

/**
 * @brief  Imprime um  tipo Sistema
 * @param dado   tipo Sistema
 */
void relatorioSistema(Sistema *s){
    printf("----- RELATORIO GERAL -----\n");
    printf("- Qtd tickets: %d\n", getQtdTicketsNaFila(s->fila));
    printf("- Qtd tickets (A): %d\n", getQtdTicketsPorStatusNaFila(s->fila, 'A'));
    printf("- Qtd tickets (F): %d\n", getQtdTicketsPorStatusNaFila(s->fila, 'F'));
    printf("- Qtd usuarios: %d\n", s->qtdUsuarios);
    //calcula media idade dos usuarios
    int mediaIdade = 0;
    for(int i = 0; i < s->qtdUsuarios; i++){
        mediaIdade += getIdadeUsuario(s->usuarios[i]);
    }
    mediaIdade = mediaIdade/s->qtdUsuarios;
    printf("- Md idade usuarios: %d\n", mediaIdade);
    printf("- Qtd tecnicos: %d\n", s->qtdTecnicos);
    //calcula idade nmedia dos tecnicos
    mediaIdade = 0;
    for(int i = 0; i < s->qtdTecnicos; i++){
        mediaIdade += getIdadeTecnico(s->tecnicos[i]);
    }
    mediaIdade = mediaIdade/s->qtdTecnicos;
    printf("- Md idade tecnicos: %d\n", mediaIdade);
    //media trabalho tecnicos
    int mediaTrabalho = 0;
    for(int i = 0; i < s->qtdTecnicos; i++){
        mediaTrabalho += getTempoTrabalhado(s->tecnicos[i]);
    }
    mediaTrabalho = mediaTrabalho/s->qtdTecnicos;
    printf("- Md trabalho tecnicos: %d\n", mediaTrabalho);
    printf("---------------------------\n\n");
}

/**
 * @brief  Imprime um usuarios do tipo Sistema
 * @param dado   tipo Sistema
 */
void imprimeUsuarioSistema(Sistema *s){
    printf("----- BANCO DE USUARIOS -----\n");
    for(int i = 0; i < s->qtdUsuarios; i++){
        printf("--------------------\n");
        imprimeUsuario(s->usuarios[i]);
    }
    printf("----------------------------\n\n");
}

/**
 * @brief  Imprime um tecnicos do tipo Sistema
 * @param dado   tipo Sistema
 */
void imprimeTecnicosSistema(Sistema *s){
    printf("----- BANCO DE TECNICOS -----\n");
    for(int i = 0; i < s->qtdTecnicos; i++){
        printf("--------------------\n");
        imprimeTecnico(s->tecnicos[i]);
    }
    printf("----------------------------\n\n");
}


/**
 * @brief  Imprime um ranking tecnicos(/ordena tecnicos No caso dos técnicos, elesdevem ser exibidos de acordo com a quantidade de tempo trabalhado., decrescente) do tipo Sistema
 * @param dado   tipo Sistema
 */
void imprimeRankingTecnicosSistema(Sistema *s){
    //ordena tecnicos
        //talvez de errado, pois ta sobrepondo a informaçao anterior
    for(int i = 0; i < s->qtdTecnicos; i++){
        for(int j = i+1; j < s->qtdTecnicos; j++){
            if(getTempoTrabalhado(s->tecnicos[i]) < getTempoTrabalhado(s->tecnicos[j])){
                Tecnico *aux = s->tecnicos[i];
                s->tecnicos[i] = s->tecnicos[j];
                s->tecnicos[j] = aux;
            }else if(getTempoTrabalhado(s->tecnicos[i]) == getTempoTrabalhado(s->tecnicos[j])){
                if(strcmp(getNomeTecnico(s->tecnicos[i]), getNomeTecnico(s->tecnicos[j]))==-1){
                Tecnico *aux = s->tecnicos[i];
                s->tecnicos[i] = s->tecnicos[j];
                s->tecnicos[j] = aux;
                }
            }
        }
    }
    printf("----- RANKING DE TECNICOS -----\n");
    for(int i = 0; i < s->qtdTecnicos; i++){
        printf("--------------------\n");
        imprimeTecnico(s->tecnicos[i]);
    }
    printf("-------------------------------\n\n");

}


/**
 * @brief  Imprime um ranking usuarios do tipo Sistema
 * @param dado   tipo Sistema
 */
void imprimeRankingUsuariosSistema(Sistema *s){
    //ordena usuarios
    //talvez de errado, pois ta sobrepondo a informaçao anterior
    for(int i = 0; i < s->qtdUsuarios; i++){
        for(int j = i+1; j < s->qtdUsuarios; j++){
            if(getQtdTickets(s->usuarios[i]) < getQtdTickets(s->usuarios[j])){
                Usuario *aux = s->usuarios[i];
                s->usuarios[i] = s->usuarios[j];
                s->usuarios[j] = aux;
            }else if(getQtdTickets(s->usuarios[i]) == getQtdTickets(s->usuarios[j])){
                if(strcmp(getNomeUsuario(s->usuarios[i]), getNomeUsuario(s->usuarios[j]))==1){
                    Usuario *aux = s->usuarios[j];
                    s->usuarios[j] = s->usuarios[i];
                    s->usuarios[i] = aux;
                }
            }
        }
    }
    printf("----- RANKING DE USUARIOS -----\n");
    for(int i = 0; i < s->qtdUsuarios; i++){
        printf("--------------------\n");
        imprimeUsuario(s->usuarios[i]);
    }
    printf("-------------------------------\n");
}


/**
 * @brief  cadastra ticket na fila do tipo Sistema
 * @param dado   tipo Sistema
 */
void CadastraTicket(Sistema *s){
    char cpf[15];
    scanf(" %[^\n]", cpf);

    int flag = 0;
    char* setor = malloc(MAX_TAM_SETOR_TRABALHO*sizeof(char));
    strcpy(setor,"\0");
    for(int i=0; i<s->qtdUsuarios; i++){
        if(strcmp(getCPF_U(s->usuarios[i]), cpf) == 0){
            AumentaQtdTicketsUsuario(s->usuarios[i]);
            strcpy(setor, getSetor(s->usuarios[i]));

            int tamset = strlen(setor);
            setor[tamset] = '\0';

            flag = 1;
            break;
        }
    }

    char tipo[15];
    scanf(" %[^\n]\n", tipo);
    
    if(strcmp(tipo, "SOFTWARE") == 0){
        Software *sw = lerSoftware();
        if(flag==1){
        setTempoEstimadoSoftware(sw);
            InsereTicketFilaSistema(s, cpf, sw, getTempoEstimadoSoftware, getTipoSoftware, notificaSoftware, desalocaSoftware);

    }else{
            desalocaSoftware(sw);
        }
    }else if(strcmp(tipo, "MANUTENCAO") == 0){

        Manutencao *m = lerManutencao(setor);
        
        if(flag==1){
        InsereTicketFilaSistema(s, cpf, m, getTempoEstimadoManutencao, getTipoManutencao, notificaManutencao, desalocaManutencao);

        }else{
            desalocaManutencao(m);
        }
    }else if(strcmp(tipo, "OUTROS") == 0){
        Outros *o = lerOutros();
        if(flag==1){
        InsereTicketFilaSistema(s, cpf, o, getTempoEstimadoOutros, getTipoOutros, notificaOutros, desalocaOutros);
        }else{
           
            desalocaOutros(o);
        }
    }
    free(setor);
}

void DistribuiTicket(Sistema *s) {
    int flag = -1; // Variável para controlar o próximo técnico no Round Robin

    // Percorre todos os tickets na fila
    for (int j = 0; j < getQtdTicketsNaFila(s->fila); j++) {
        Ticket *t = getTicketNaFila(s->fila, j);

        // Verifica se o ticket está aberto
        if (getStatusTicket(t) == 'A') {
            // Inicia a distribuição Round Robin
            if (flag == s->qtdTecnicos || flag == -1) {
                flag = 0;
            }

            // Percorre os técnicos começando pelo próximo no Round Robin
            for (int i = 0; i < s->qtdTecnicos; i++) {
                int tecnicoIndex = (flag + i) % s->qtdTecnicos; // Calcula o índice do técnico no Round Robin

                // Verifica se o técnico é de TI e o ticket é do tipo SOFTWARE
                if (getTipoTicket(t) == 'S' && strcmp(getAreaAtuacao(s->tecnicos[tecnicoIndex]), "TI") == 0) {
                    if (getDisponibilidade(s->tecnicos[tecnicoIndex]) >= getTempoEstimadoTicket(t)) {
                        modificaDisponibilidade(s->tecnicos[tecnicoIndex], getTempoEstimadoTicket(t));
                        finalizaTicket(t);
                        flag = tecnicoIndex + 1; // Atualiza o próximo técnico no Round Robin
                        break;
                    }
                }
                // Verifica se o técnico é GERAL e o ticket não é do tipo SOFTWARE
                else if (getTipoTicket(t) != 'S' && strcmp(getAreaAtuacao(s->tecnicos[tecnicoIndex]), "GERAL") == 0 ) {
                    if (getDisponibilidade(s->tecnicos[tecnicoIndex]) >= getTempoEstimadoTicket(t)) {
                        modificaDisponibilidade(s->tecnicos[tecnicoIndex], getTempoEstimadoTicket(t));
                        finalizaTicket(t);
                        flag = tecnicoIndex + 1; // Atualiza o próximo técnico no Round Robin
                        break;
                    }
                }
            }
        }
    }
}