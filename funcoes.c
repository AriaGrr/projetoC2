#include "funcoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Retorna o estado da tarefa
char* estado(int e){
  char* estado;
  if(e == 1){
    estado = "Completo";
  } else if (e == 2){
    estado = "Em andamento";
  } else  if (e == 3){
    estado = "Não iniciado";
  } else {
    printf("Erro!");
  }
  return estado;
}

// Cria uma nova tarefa e adiciona na lista
int criarTarefa(ListaDeTarefas *lt){
    if (lt->qtd < 100) {
        printf("Criar tarefa:\n");

        // Limpando o buffer do teclado antes de ler a categoria
        while (getchar() != '\n');

        printf("Digite a categoria (até 100 caracteres): ");
        fgets(lt->tarefas[lt->qtd].categoria, sizeof(lt->tarefas[lt->qtd].categoria), stdin);

        // Limpando o buffer do teclado antes de ler a descrição
        while (getchar() != '\n');

        printf("Digite a descrição (até 300 caracteres): ");
        fgets(lt->tarefas[lt->qtd].descricao, sizeof(lt->tarefas[lt->qtd].descricao), stdin);


        printf("Digite a prioridade (de 1 a 10): ");
        scanf("%d", &lt->tarefas[lt->qtd].prioridade);
      
        printf("Escolha o estado da tarefa:\n");    
        printf("1 - Completo\n");  
        printf("2 - Em andamento\n");
        printf("3 - Não iniciado\n");
      scanf("%d", &lt->tarefas[lt->qtd].estado);

        lt->qtd++;
        return 0;
    } else {
        printf("Lista de tarefas está cheia.\n");
        return 1;
    }

}


// Deleta uma tarefa da lista
int deletarTarefa(ListaDeTarefas *lt) {
    if (lt->qtd > 0) {
        printf("Deletar tarefa:\n");
        int pos;

        printf("Digite a posição da tarefa (1 a 100): ");
        scanf("%d", &pos);
        pos--;

        if (pos >= 0 && pos < lt->qtd) {
            for (int i = pos; i < lt->qtd - 1; i++) {
                lt->tarefas[i] = lt->tarefas[i + 1];
            }

            lt->qtd--;
            return 0;
        } else {
            printf("Posição invalida.\n");
            return 1;
        }
    } else {
        printf("Lista de tarefas vazia.\n");
        return 1;
    }
}

// Mostra a lista de tarefas e retorna 0 se a lista não estiver vazia
int listarTarefas(ListaDeTarefas lt) {
    printf("Lista de tarefas\n");
    printf("Quantidade de tarefas: %d\n", lt.qtd);
    printf("\n");

    if (lt.qtd == 0) {
        printf("A lista de tarefas está vazia.\n");
        return 1; 
    }

    for (int i = 0; i < lt.qtd; i++) {
        printf("Tarefa %d\n", i + 1);
        printf("Categoria: %s", lt.tarefas[i].categoria);
        printf("Descrição: %s", lt.tarefas[i].descricao);
        printf("Prioridade: %d\n", lt.tarefas[i].prioridade);
        printf("\n");
    }

    return 0; 
}

// Altera um campo de uma tarefa escolhida
int alterarTarefa(ListaDeTarefas *lt){
  printf("Alterar Tarefa");
  printf("1 - Exibir escolhas");
  printf("2 - Já sei a posição da tarefa");
  printf("0 - Voltar");
  int opcao;
  scanf("%d", &opcao);
  if(opcao == 1){
    system("clear");
    listarTarefas(*lt);
  }
    printf("Qual tarefa você deseja alterar?");
    int posicao;
    scanf("%d", &posicao);
    if(posicao > lt->qtd || posicao < 0){
      printf("Posição inválida!");
      return 0;
    } else {
      system("clear");
      printf("Qual campo você deseja alterar?");
      printf("1 - Descrição");
      printf("2 - Categoria");
      printf("3 - Prioridade");
      printf("4 - Estado");
      printf("0 - Voltar");
      int opcao2;
      scanf("%d", &opcao2);
      if(opcao2 == 1){
        system ("clear");
        printf("Descrição: ");
        char descricao[300];
        scanf("%s", descricao);
        strcpy(lt->tarefas[posicao-1].descricao, descricao);
        printf("Descrição alterada com sucesso!");
        return 0; 
    } else if(opcao2 == 2){
        system ("clear");
        printf("Categoria: ");
        char categoria[100];
        scanf("%s", categoria);
        strcpy(lt->tarefas[posicao-1].categoria, categoria);
    } else if(opcao2 == 3){
        system ("clear");
        printf("Prioridade: ");
        int prioridade;
        scanf("%d", &prioridade);
        lt->tarefas[posicao-1].prioridade = prioridade;
    
    } else if(opcao2 == 4){
        system ("clear");
        printf("Escolha o novo estado da tarefa:\n");    
        printf("1 - Completo\n");  
        printf("2 - Em andamento\n");
        printf("3 - Não iniciado\n");
        int estado;
        scanf("%d", &estado);
        lt->tarefas[posicao-1].estado = estado;
      } else if(opcao2 == 0){
        system ("clear");
        return 0;
      } else {
        system ("clear");
        printf("Opção inválida!");
        return 0;
      }
    }
        return 0;
}


int listarPrioridade(ListaDeTarefas lt){
  printf("Listar Tarefas por Prioridade");
  printf("Digite a prioridade (de 1 a 10): ");
  int prioridade;
  scanf("%d", &prioridade);
  if(prioridade > 10 || prioridade < 1){
    printf("Prioridade inválida!");
    return 0;
  } else {
    system("clear");
    printf("Tarefas com prioridade %d:\n", prioridade);
     for (int i = 0; i < lt.qtd; i++) {
       if(lt.tarefas[i].prioridade == prioridade){
         printf("Tarefa %d\n", i + 1);
         printf("Categoria: %s", lt.tarefas[i].categoria);
         printf("Descrição: %s", lt.tarefas[i].descricao);
         printf("Estado: %d\n", lt.tarefas[i].estado);
  }
     }
  }
  
  return 0;
}

int listarCategoria(ListaDeTarefas lt){
  return 0;
}

int listarPCTarefa(ListaDeTarefas lt){
  return 0;
}

int listarEstado(ListaDeTarefas lt){
  return 0;
}

// Adicional, não feito.
int exportarTarefas(ListaDeTarefas lt, char exportado[]){
  return 0;
}

int exportarPrioridade(ListaDeTarefas lt, char exportado[]){
  return 0;
}

int exportarCategoria(ListaDeTarefas lt, char exportado[]){
  return 0;
}

int exportarPCTarefa(ListaDeTarefas lt, char exportado[]){
  return 0;
}

// Funções para print de menus
void printMenu(){
    printf("Menu\n");
    printf("1 - Criar tarefa\n");
    printf("2 - Deletar tarefa\n");
    printf("3 - Listar tarefas\n");
    printf("4 - Exportar tarefas\n");
    printf("5 - Alterar tarefa\n");
    printf("0 - Sair\n");
    printf("Digite a opção desejada: ");
}

void menuExportar(){
  printf("Arquivo gerado em TXT\n");
  printf("Escolha a exportação:\n");
  printf("1 - Exportar tudo (opção indisponivel)\n");
  printf("2 - Exportar por prioridade\n");
  printf("3 - Exportar por categoria\n");
  printf("4 - Exportar por prioridade e categoria\n");
}
  
void menuListagem(){
  printf("Escolha a listagem desejada:\n");
  printf("1 - Listar todas as tarefas\n");
  printf("2 - Listar tarefas por prioridade\n");
  printf("3 - Listar tarefas por categoria\n");
  printf("4 - Listar tarefas por estado\n");
  printf("5 - Listar tarefas por prioridade e categoria\n");
}

// Salva a lista de tarefas em um arquivo
// fwrite
int salvarLista(ListaDeTarefas lt, char nome[]) {
    FILE *arquivo;
    arquivo = fopen(nome, "wb");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

        fwrite(&lt.tarefas, sizeof(Tarefa), lt.qtd, arquivo);

    fclose(arquivo);
    return 0;
}

// Carrega a lista de tarefas de um arquivo
// fread
int carregarLista(ListaDeTarefas *lt, char nome[]) {
    FILE *arquivo;
    arquivo = fopen(nome, "rb");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    lt->qtd = 0; // Inicialize o contador de tarefas carregadas

    while (fread(&lt->tarefas[lt->qtd], sizeof(Tarefa), 1, arquivo) == 1) {
        lt->qtd++;
    }

    fclose(arquivo);
    return 0;
}
