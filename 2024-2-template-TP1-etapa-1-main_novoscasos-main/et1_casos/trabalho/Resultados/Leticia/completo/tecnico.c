#include "tecnico.h"
struct Tecnico {
    Ator *a;
    char *areaAtuacao;
    int disponibilidade;
    float salario;
    int tempoTrabalhado;
};

/**
 * @brief Aloca uma estrutura Tecnico na memória e inicializa os parâmetro necessários
 * @param a especificaçoes Tecnico
 * @param areaAtuacao area de atuacao do Tecnico
 * @param salario salario do Tecnico(em float)
 * @param disponibilidade quantidade de tempo que o tecnico vai trabalhar
 * @return  Uma estrutura Tecnico inicializada.
 */
Tecnico *criaTecnico(Ator* a, char *areaAtuacao, int disponibilidade, float salario){
    Tecnico *s = (Tecnico *)malloc(sizeof(Tecnico));
    s->a = a;
    s->areaAtuacao = (char *)malloc(sizeof(char) * (strlen(areaAtuacao) + 1));
    strcpy(s->areaAtuacao, areaAtuacao);
    s->disponibilidade = disponibilidade;
    s->salario = salario;
    s->tempoTrabalhado = 0;
    return s;
}

/**
 * @brief Lê da entrada padrão TIPO Tecnico
 * @return  Um Tipo Tecnico
 */
Tecnico *lerTecnico(){
    Ator *a = lerAtor();
    char areaAtuacao[MAX_TAM_AREA_ATUACAO];
    int disponibilidade;
    float salario;
    scanf(" %[^\n]", areaAtuacao);
    scanf(" %d", &disponibilidade);
    scanf(" %f", &salario);
    return criaTecnico(a, areaAtuacao, disponibilidade, salario);
}

/**
 * @param s  struct Tecnico
 * @return  retorna cpf do Tecnico
 */
char* getCPF_T(Tecnico *s){
    return getCpf(s->a);
}

/**
 * @param s  struct Tecnico
 * @return  retorna disponibilidade do Tecnico
 */
int getDisponibilidade(Tecnico *s){
    return s->disponibilidade;
}

/**
 * @param s  struct Tecnico
 * @brief Modifica a disponibilidade do Tecnico e aumenta tempo trabalhado
 */
void modificaDisponibilidade(Tecnico *s, int horas){
    s->disponibilidade -= horas;
    s->tempoTrabalhado += horas;
}


/**
 * @param s  struct Tecnico
 * @return  retorna salario do Tecnico
 */
float getSalario(Tecnico *s){
    return s->salario;
}

/**
 * @param s  struct Tecnico
 * @return  retorna area do Tecnico
 */
char* getAreaAtuacao(Tecnico *s){
    return s->areaAtuacao;
}

/**
 * @brief  Desaloca tipo Tecnico da memória
 * @param s   tipo Tecnico
 */
void desalocaTecnico(void *s){
    Tecnico *t = (Tecnico *)s;
    desalocaAtor(t->a);
    free(t->areaAtuacao);
    free(t);
}

/**
 * @brief  Imprime tipo Tecnico
 * @param dado   do tipo Tecnico
 */
void imprimeTecnico(void *dado){
    Tecnico *t = (Tecnico *)dado;
    imprimeAtor(t->a);
    printf("- Area de Atuacao: %s\n", t->areaAtuacao);
    printf("- Salario: %.2f\n", t->salario);
    printf("- Disponibilidade: %dh\n", t->disponibilidade);
    printf("- Tempo Trabalhado: %dh\n", t->tempoTrabalhado);
}

int getTempoTrabalhado(Tecnico *s){
    return s->tempoTrabalhado;
}

int getIdadeTecnico(Tecnico *s){
    return getIdadeAtor(s->a);
}

/**
 * @brief  Retorna nome do tipo Tecnico
 * @param dado   do tipo Tecnico
 */
char* getNomeTecnico(Tecnico *s){
    return getNome(s->a);
}