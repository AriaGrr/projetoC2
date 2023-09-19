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


    // Verifica se o nome contém apenas letras
    while (strspn(nome, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") != strlen(nome)) {
        printf("Nome inválido. O nome deve conter apenas letras: ");
        scanf("%s", nome);
    }

    char cpf[11];
    printf("Digite o CPF do cliente: ");
    scanf("%s", cpf);

    // Validar que o CPF informado tem 11 dígitos
    while (strlen(cpf) != 11) {
        printf("CPF inválido. Informe um CPF com 11 dígitos: ");
        scanf("%s", cpf);
        while (strspn(cpf, "0123456789") != strlen(cpf)) {
            printf("Cpf invalido. O cpf deve conter apenas números: ");
            scanf("%s", cpf);
        }
    }

    char senha[6];
    printf("Digite a senha do cliente: ");
    scanf("%s", senha);

    while (strlen(senha) != 6) {
        printf("Senha invalida. digite uma senha com seis digitos númericos: ");
        scanf("%s", senha);
            while (strspn(senha, "0123456789") != strlen(senha)) {
        printf("Senha invalida. A senha deve conter apenas números: ");
        scanf("%s", senha);
    }
    }

    char tipo;
    printf("Escolha o tipo de conta: ");
    printf("1 - Comum\n");
    printf("2 - Plus\n");
    scanf("%s", tipo);

    while (tipo != '1' && tipo != '2') {
        printf("Tipo de conta inválido. Escolha 1 para conta comum ou 2 para conta plus: ");
        scanf("%s", tipo);
    }

    if (tipo == '1') {
        tipo = "comum";
    } else {
        tipo = "plus";
    }

    float saldo;
    printf("Digite o saldo inicial: ");
    scanf("%f", &saldo);

    while (saldo > 0) {
        printf("Saldo inválido. Informe um valor maior ou igual a zero: ");
        scanf("%f", &saldo);
        // Converte o saldo para uma string
        char saldo_str[100000000];
        sprintf(saldo_str, "%f", saldo);

        // Verifica se o saldo contém apenas números
        for (int i = 0; i < strlen(saldo_str); i++) {
            if (!isdigit(saldo_str[i])) {
                printf("Saldo inválido. O saldo deve conter apenas números: ");
                scanf("%f", &saldo);
                break;
            }
        }
    }
    return 0;
    }

int apagarCliente(Clientes *t){
    printf("Apagar cliente:\n");
    char cpf[11];
    printf("Digite o CPF do cliente: ");
    scanf("%s", cpf);
    printf("CPF: %s\n", cpf);
    printf("Você tem certeza que deseja apagar o cliente? (s/n): ");
    char opcao;
    scanf("%s", opcao);
    if (opcao == 's') {
        printf("Cliente apagado com sucesso!\n");
    } else {
        printf("Operação cancelada.\n");
    }
    return 0;
    }

// Lista todos os clientes cadastrados dividida por tipo de conta
int listarClientes(Clientes t){
    printf("Lista de clientes:\n");
    printf("1 - Listar clientes comuns\n");
    printf("2 - Listar clientes plus\n");
    printf("3 - Listar todos os clientes\n");
    printf("0 - Voltar ao menu principal\n");
    printf("Digite a opção desejada: ");
    int opcao;
    scanf("%d", &opcao);

    while (opcao != 0 && opcao != 1 && opcao != 2 && opcao != 3) {
        printf("Opção inválida. Digite 1 para listar clientes comuns, 2 para listar clientes plus ou 3 para listar todos os clientes: ");
        scanf("%d", &opcao);

    return 0;
    }

    if (opcao == 1) {
        printf("Clientes comuns:\n");
        for (int i = 0; i < t.qtd; i++) {
            if (t.contas[i].tipo == "comum") {
                printf("Nome: %s\n", t.contas[i].nome);
                printf("CPF: %s\n", t.contas[i].cpf);
                printf("Saldo: %.2f\n", t.contas[i].saldo);
                printf("\n");
            }
        }
    } else if (opcao == 2) {
        printf("Clientes plus:\n");
        for (int i = 0; i < t.qtd; i++) {
            if (t.contas[i].tipo == "plus") {
                printf("Nome: %s\n", t.contas[i].nome);
                printf("CPF: %s\n", t.contas[i].cpf);
                printf("Saldo: %.2f\n", t.contas[i].saldo);
                printf("\n");
            }
        }
    } else if (opcao == 3) {
        printf("Todos os clientes:\n");
        for (int i = 0; i < t.qtd; i++) {
            printf("Nome: %s\n", t.contas[i].nome);
            printf("CPF: %s\n", t.contas[i].cpf);
            printf("Tipo: %s\n", t.contas[i].tipo);
            printf("Saldo: %.2f\n", t.contas[i].saldo);
            printf("\n");
        }
    }
    return 0;
}

int debito(Clientes *t){
    char cpf[11];
    wprintf(L"Débito:\n");
    printf("Digite o CPF do cliente: ");
    scanf("%s", cpf);

    char senha[6];
    printf("Digite a senha do cliente: ");
    scanf("%s", senha);

    return 0;
    }

int deposito(Clientes *t){
    wprintf(L"Déposito:\n");
    char cpf[11];
    printf("Digite o CPF do cliente: ");
    scanf("%s", cpf);

    float valor;
    printf("Digite o valor do déposito: ");
    scanf("%f", valor);

    return 0;
    }

// Extrato - gera um arquivo com o histórico de todas as operações realizadas na conta, com datas e valores, incluindo as tarifas.
int extrato(Clientes *t){
    printf("Extrato:\n");
    char cpf[11];
    printf("Digite o CPF do cliente: ");
    scanf("%s", cpf);

    char senha[6];
    printf("Digite a senha do cliente: ");
    scanf("%s", senha);

    return 0;
    }

//  Transferência - realiza a transferência de uma valor determinado de uma conta (Origem) para outra conta (Destino)
int transferencia(Clientes *t){
    wprintf(L"Transferência:\n");
    char cpf[11];
    printf("Digite o CPF do cliente: ");
    scanf("%s", cpf);

    char senha[6];
    printf("Digite a senha do cliente: ");
    scanf("%s", senha);

    printf("Digite o CPF do destinatário: ");
    scanf("%s", cpf);

    float valor;
    printf("Digite o valor da transferência: ");
    scanf("%f", valor);

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
