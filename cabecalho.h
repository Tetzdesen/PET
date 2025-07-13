#ifndef CABECALHO_H_INCLUDED
#define CABECALHO_H_INCLUDED

#define MAX_TAREFAS 500
#define MAX_MOTORISTAS 500

typedef struct tSolucao{
    int matriz_sol[MAX_MOTORISTAS][MAX_TAREFAS];
    int aux[MAX_MOTORISTAS];
    int h_extra;
    int t_ocioso;
    int t_sobre;
    int h_exce;
    int fo;
} Solucao;

void ler_dados(char *nome_arq);
void escrever_dados(char *nome_arq);
void criar_solucao(Solucao& s);
void escrever_solucao(Solucao& s);
void heu_cons_ale(Solucao& s);
void heu_cons_gul(Solucao& s);
void heu_cons_ale_gul(Solucao& s, const double& percentual);
void heu_BL_rand(Solucao& s, int iter);
void heu_BL_MM(Solucao& s);
void heu_BL_PM(Solucao& s);

void calcular_fo(Solucao& s);
void remover_tarefa(Solucao& s, const int& mot, const int&pos);
void inserir_tarefa(Solucao& s, const int& mot, const int&tar);
void gerar_vizinha(Solucao& s);

int num_tarefas;
int num_motoristas;
int tempo_normal_trabalho;
int tempo_maximo_trabalho;

int h_inicio_tarefa[MAX_TAREFAS];
int h_termino_tarefa[MAX_TAREFAS];
#endif // CABECALHO_H_INCLUDED
