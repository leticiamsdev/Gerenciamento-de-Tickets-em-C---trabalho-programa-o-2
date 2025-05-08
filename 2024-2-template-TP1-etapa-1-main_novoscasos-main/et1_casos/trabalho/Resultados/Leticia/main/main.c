#include "usuario.h"
#include "fila.h"
#include "tecnico.h"
#include "software.h"
#include "manutencao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "outros.h"
#include "sistema.h"

///posso criar um tad que conecta usuario, fila e tecnico

int main(){
    char escolha = 'W';
    char* acao = malloc(sizeof(char)*50);
    Sistema *s = criaSistema();
    Usuario *u;
    Tecnico *t;
    while(escolha!='F'){
        scanf(" %c", &escolha);
        switch (escolha){
            case 'A':
                //cadastra ticket;
                CadastraTicket(s);
                break;
            case 'U':
                //cadastra usuario
                u = lerUsuario();
                InsereUsuarioSistema(s, u);
                break;
            case 'T':
                //cadastra tecnico
                t = lerTecnico();
                InsereTecnicoSistema(s, t);
                break;
            case 'E':
                scanf(" %[^\n]", acao);
                if(strcmp(acao, "DISTRIBUI")==0){
                    DistribuiTicket(s);
                }else if(strcmp(acao, "NOTIFICA")==0){
                    notificaFilaSistema(s);
                }else if(strcmp(acao, "USUARIOS")==0){
                    imprimeUsuarioSistema(s);
                }else if(strcmp(acao, "TECNICOS")==0){
                    imprimeTecnicosSistema(s);
                }else if(strcmp(acao, "RANKING TECNICOS")==0){
                    imprimeRankingTecnicosSistema(s);
                }else if(strcmp(acao, "RANKING USUARIOS")==0){
                    imprimeRankingUsuariosSistema(s);
                }else if(strcmp(acao, "RELATORIO")==0){
                    relatorioSistema(s);
                }
                break;
            case 'F':
                desalocaSistema(s);
                //desaloca usuarios
                //desaloca tecnicos
                free(acao);
                break;
        }    
    }

    return 0;
}