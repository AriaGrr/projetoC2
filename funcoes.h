#include <stdio.h>

typedef struct {
    int prioridade;
    int estado;
    char categoria[100];
    char descricao[300];
} Tarefa;

typedef struct {
    Tarefa tarefas[100];
    int qtd;
} ListaDeTarefas;

char* estado(int e);

//Funções principais
int criarTarefa(ListaDeTarefas *lt);
int deletarTarefa(ListaDeTarefas *lt);
int alterarTarefa(ListaDeTarefas *lt);

// Funções para exportar
int exportarTarefas(ListaDeTarefas lt,     char exportado[]); // Adicional, não feito.
int exportarPrioridade(ListaDeTarefas lt, char exportado[]);
int exportarCategoria(ListaDeTarefas lt, char exportado[]);
int exportarPCTarefa(ListaDeTarefas lt, char exportado[]);

//Funções de listagem
int listarTarefas(ListaDeTarefas lt);
int listarPrioridade(ListaDeTarefas lt);
int listarCategoria(ListaDeTarefas lt);
int listarPCTarefa(ListaDeTarefas lt);
int listarEstado(ListaDeTarefas lt);


void menuExportar();
void menuListagem();
void printMenu();
// fwrite
int salvarLista(ListaDeTarefas lt, char nome[]);
// fread
int carregarLista(ListaDeTarefas *lt, char nome[]);

