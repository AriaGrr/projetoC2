#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <locale.h>
#include "funcoes.h"

// Função que imprime o menu principal
void menu(){
wprintf(L"Menu principal\n");
wprintf(L"1 - Cadastrar cliente\n");
wprintf(L"2 - Apagar cliente\n");
wprintf(L"3 - Listar clientes\n");
wprintf(L"4 - Débito\n");
wprintf(L"5 - Depósito\n");
wprintf(L"6 - Extrato\n");
wprintf(L"7- Transferência entre contas\n");
wprintf(L"0 - Sair\n");
wprintf(L"Digite a opção desejada: ");
}

int cadastrarCliente(Clientes *t){
        printf("Cadastrar cliente:\n");

        // Limpando o buffer do teclado antes de ler a categoria
        while (getchar() != '\n');

    char nome[100];
    printf("Digite o nome do cliente: ");
    scanf("%s", nome);

    char cpf[15];
    printf("Digite o cpf do cliente (14 dígitos): ");
    scanf("%s", cpf);

    // Verifica se já existe uma conta com o mesmo cpf
    for (int i = 0; i < qtd; i++) {
        if (strcmp(cpf, Clientes[i].cpf) == 0) {
            printf("Já existe uma conta com esse CNPJ!\n");
            return;
        }
    }

    char senha[100];
    printf("Digite a senha do cliente: ");
    scanf("%s", senha);

    char tipo[10];
    printf("Escolha o tipo de conta: ");
    printf("1 - Comum\n");
    printf("2 - Plus\n");
    scanf("%s", tipo);

    if (strcmp(tipo, "1") == 0) {
        strcpy(tipo, "comum");
    } else if (strcmp(tipo, "2") == 0) {
        strcpy(tipo, "plus");
    } else {
        printf("Tipo de conta inválido!\n");
        return;
    }

    // Adiciona a conta ao array de Clientes
    strcpy(Clientes[qtd].nome, nome);
    strcpy(Clientes[qtd].cnpj, cpf);
    strcpy(Clientes[qtd].senha, senha);
    Clientes[qtd].saldo = 0;
    strcpy(Clientes[qtd].tipo, tipo);

    qtd++;

        return 0;
    }

int apagarCliente(){

    }

int listarClientes(){

    }

int debito(){

    }

int deposito(){

    }

int extrato(){

    }

int transferencia(){
        
    }

int tipoConta(char tipo){
    int taxa, negativo;
    if (tipo == "comum"){
        taxa = 5;
        negativo = 1000;
    }
    else if (tipo == "plus"){
        taxa = 3;
        negativo = 5000;
    }
    return taxa, negativo;
}

// Salva a lista de tarefas em um arquivo
// fwrite
int salvar(Clientes t, char nome[]) {
    FILE *arquivo;
    arquivo = fopen(nome, "wb");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    for (int i = 0; i < t.qtd; i++) {
        fwrite(&t.contas[i], sizeof(Conta), 1, arquivo);
    }

    fclose(arquivo);
    return 0;
}

// Carrega os clientes de um arquivo
// fread
int carregar(Clientes *t, char nome[]) {
    FILE *arquivo;
    arquivo = fopen(nome, "rb");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    t->qtd = 0; // Inicialize o contador de contas carregadas

    while (fread(&t->contas[t->qtd], sizeof(Conta), 1, arquivo) == 1) {
        t->qtd++;
    }

    fclose(arquivo);
    return 0;
}
