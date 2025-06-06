#include <iostream>
#include "string.h"
#include <stdlib.h>
#include "cabecalho.h"
#include <cstdlib> // Para srand() e rand()
#include <ctime>   // Para time()
#include "math.h"

#define MAX(X,Y)((X > Y) ? (X) : (Y))
#define MIN(X,Y)((X < Y) ? (X) : (Y))

const int PESO_EXTRA = 1;
const int PESO_OCIOSO = 1;
const int PESO_SOBREPOSICAO = 100;
const int PESO_EXCEDIDO = 100;

int main()
{
    srand(time(0));
    Solucao s, clone;
    ler_dados("csp25.txt");
    escrever_dados("csp25.txt");

    double horas_somadas = 0;

    for(int i = 0; i < num_tarefas; i++){
        horas_somadas += (h_termino_tarefa[i] - h_inicio_tarefa[i]);
    }

    num_motoristas = ceil(horas_somadas / tempo_normal_trabalho);

   // criar_solucao(s);
    //criar_he_gul(s);
    criar_he_ale(s);
    calcular_fo(s);

   // memcpy(&clone, &s, sizeof(s));

    //for(int i = 0; i < 10000000; i++){
     //   gerar_vizinha(clone);
      //  calcular_fo(clone);
      //  if(s.fo > clone.fo) memcpy(&s, &clone, sizeof(clone));
    //}

    escrever_solucao(s);
    return 0;
}

void escrever_dados(char *nome_arq){
    FILE* f;

    if(!strcmp(nome_arq, " "))
        f = stdout;
    else
        f= fopen(nome_arq, "w");

    fprintf(f, "%d %d %d\n", num_tarefas, tempo_normal_trabalho, tempo_maximo_trabalho);

    for(int j = 0; j < num_tarefas; j++){
            fprintf(f, "%d  %d", h_inicio_tarefa[j], h_termino_tarefa[j]);
            fprintf(f, "\n");
    }
    fprintf(f, "\n");

    if(strcmp(nome_arq, " "))
        fclose(f);
}

void ler_dados(char *nome_arq){
    FILE* f = fopen(nome_arq, "r");

    fscanf(f, "%d %d %d", &num_tarefas, &tempo_normal_trabalho, &tempo_maximo_trabalho);

    for(int j = 0; j < num_tarefas; j++)
        fscanf(f, "%d %d", &h_inicio_tarefa[j], &h_termino_tarefa[j]);

    fclose(f);
}
/*
void criar_solucao(Solucao &s){

    int tarefa_por_motorista = 0;
    memset(&s.aux, 0, sizeof(s.aux));

    for(int j = 0; j < num_tarefas; j++){
        tarefa_por_motorista = tarefa_por_motorista % num_motoristas;
        s.matriz_sol[tarefa_por_motorista][s.aux[tarefa_por_motorista]] = j;
        s.aux[tarefa_por_motorista]++;
        tarefa_por_motorista++;
    }

    for(int i = 0; i < num_motoristas; i++){
       for(int j = 0; j < s.aux[i]; j++){
           printf("%d ", s.matriz_sol[i][j]);
       }
       printf("\n");
    }

}*/
void criar_he_gul(Solucao& s){
    int tarefa_por_motorista = 0;
    memset(&s.aux, 0, sizeof(s.aux));

    for(int j = 0; j < num_tarefas; j++){
        tarefa_por_motorista = tarefa_por_motorista % num_motoristas;
        s.matriz_sol[tarefa_por_motorista][s.aux[tarefa_por_motorista]] = j;
        s.aux[tarefa_por_motorista]++;
        tarefa_por_motorista++;
    }

    for(int i = 0; i < num_motoristas; i++){
       for(int j = 0; j < s.aux[i]; j++){
           printf("%d ", s.matriz_sol[i][j]);
       }
       printf("\n");
    }
}

void criar_he_ale(Solucao &s){
    int mot, aux;
    memset(&s.aux, 0, sizeof(s.aux));
    for(int i = 0; i < num_tarefas; i++){
        mot = rand() % num_motoristas;
        s.matriz_sol[mot][s.aux[mot]] = i;
        s.aux[mot]++;
    }

    for(int i = 0; i < num_motoristas; i++){
       for(int j = 0; j < s.aux[i]; j++){
           printf("%d ", s.matriz_sol[i][j]);
       }
       printf("\n");
    }
}

void escrever_solucao(Solucao& s){
    printf("\nTEMPO EXTRA: %d \n", s.h_extra);
    printf("TEMPO OCIOSO: %d \n", s.t_ocioso);
    printf("TEMPO SOBREPOSICAO: %d \n", s.t_sobre);
    printf("TEMPO EXCECCAO: %d \n", s.h_exce);
    printf("FO: %d \n", s.fo);
}

/*
void criar_he_gu(Solucao &s){
    memset(&s.aux, 0, sizeof(s.aux));

    double horas_trabalhadas;
    int j = 0;
    for(int i = 0; i < num_tarefas; i++){
      horas_trabalhadas = 0.0;
      for(;j  < num_tarefas && horas_trabalhadas < tempo_normal_trabalho; j++){
        s.matriz_sol[i][j] = j;
        horas_trabalhadas += h_termino_tarefa[j] - h_inicio_tarefa[j];
        printf("MOT: %d TAR: %d\n", i, s.matriz_sol[i][j]);
      }
      printf("\n");
    }
}*/

void calcular_fo(Solucao &s){

    s.h_extra = s.t_ocioso = s.t_sobre = s.h_exce = s.fo = 0;

    for(int i = 0; i < num_motoristas; i++){

       if(s.aux[i] == 0) continue;

       for(int j = 1; j < s.aux[i]; j++){
             s.t_ocioso += MAX(0, (h_inicio_tarefa[s.matriz_sol[i][j]] - h_termino_tarefa[s.matriz_sol[i][j-1]]));
             s.t_sobre += (MAX(0, h_termino_tarefa[s.matriz_sol[i][j-1]] - h_inicio_tarefa[s.matriz_sol[i][j]]));
       }

       s.t_ocioso += MAX(0, tempo_normal_trabalho - (h_termino_tarefa[i] - h_inicio_tarefa[i]));
       s.h_extra += MIN(tempo_maximo_trabalho - tempo_normal_trabalho, MAX(0, (h_termino_tarefa[s.matriz_sol[i][s.aux[i] - 1]] - h_inicio_tarefa[s.matriz_sol[i][0]]) - tempo_normal_trabalho));
       s.h_exce += MAX(0, (h_termino_tarefa[s.matriz_sol[i][s.aux[i] - 1]] - h_inicio_tarefa[s.matriz_sol[i][0]]) - tempo_maximo_trabalho);
    }

    s.fo += (PESO_EXTRA * s.h_extra) + (PESO_OCIOSO * s.t_ocioso) + (PESO_SOBREPOSICAO * s.t_sobre) + (PESO_EXCEDIDO * s.h_exce);
}


void remover_tarefa(Solucao& s, const int& mot, const int&pos){
    for (int i = pos; i < s.aux[mot] - 1; i++)
        s.matriz_sol[mot][i] = s.matriz_sol[mot][i + 1];
    s.aux[mot]--;
}

void inserir_tarefa(Solucao& s, const int& mot, const int&tar){
    int i;
    for (i = s.aux[mot] - 1; i >= 0; i--)
    {
        if (h_inicio_tarefa[s.matriz_sol[mot][i]] > h_inicio_tarefa[tar])
            s.matriz_sol[mot][i + 1] = s.matriz_sol[mot][i];
        else
            break;
    }
    s.matriz_sol[mot][i + 1] = tar;
    s.aux[mot]++;
}

void gerar_vizinha(Solucao &s){
    int mot1, mot2, pos, tar;
    do
        mot1 = rand() % num_motoristas;
    while(s.aux[mot1] == 0);
    pos = rand() % s.aux[mot1];
    tar = s.matriz_sol[mot1][pos];
    do
        mot2 = rand() % num_motoristas;
    while(mot2 == mot1);
    remover_tarefa(s, mot1, pos);
    inserir_tarefa(s, mot2, tar);
    calcular_fo(s);
}
