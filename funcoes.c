#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "funcoes.h"

// Função que imprime o menu principal
void menu(){
    printf("Menu principal\n");
    printf("1 - Cadastrar cliente\n");
    printf("2 - Apagar cliente\n");
    printf("3 - Listar clientes\n");
    printf("4 - Débito\n");
    printf("5 - Depósito\n");
    printf("6 - Extrato\n");
    printf("7 - Transferência entre contas\n");
    printf("0 - Sair\n");
    printf("Digite a opção desejada: ");
}

void clearBuffer() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF) 
        ;
}

// Função que retorna a taxa de transação e o valor negativo de cada tipo de conta
int tipoConta(char tipo){
    int taxa, negativo;
    if (tipo == 1){
        taxa = 5;
        negativo = 1000;
    }
    else if (tipo == 2){
        taxa = 3;
        negativo = 5000;
    }
    return taxa, negativo;
}

// Função para cadastrar cada cliente
int cadastrarCliente(Clientes *listas, Conta *contas){
    printf("Cadastrar cliente:\n");

    char nome[100];
    printf("Digite o nome do cliente: ");
    scanf("%s", nome);
    clearBuffer();

    // Verifica se o nome contém apenas letras
    while (strspn(nome, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") != strlen(nome)) {
        printf("Nome inválido. O nome deve conter apenas letras: ");
        scanf("%s", nome);
        clearBuffer();
    }

    char cpf[12]; // Incluindo espaço para o caractere nulo '\0'
    printf("Digite o CPF do cliente: ");
    scanf("%s", cpf);
    clearBuffer();

    // Validar que o CPF informado tem 11 dígitos
    while (strlen(cpf) != 11) {
        printf("CPF inválido. Informe um CPF com 11 dígitos: ");
        scanf("%s", cpf);
        clearBuffer();
    }

    char senha[7]; // Incluindo espaço para o caractere nulo '\0'
    printf("Digite a senha do cliente: ");
    scanf("%s", senha);
    clearBuffer();

    // Validar que a senha informada tem 6 dígitos
    while (strlen(senha) != 6) {
        printf("Senha inválida. Informe uma senha com seis dígitos numéricos: ");
        scanf("%s", senha);
        clearBuffer();
    }

    int tipo;
    printf("Escolha o tipo de conta (1 - Comum, 2 - Plus): ");
    scanf("%d", &tipo);
    clearBuffer();

    while (tipo != 1 && tipo != 2) {
        printf("Tipo de conta inválido. Escolha 1 para conta comum ou 2 para conta plus: ");
        scanf("%d", &tipo);
        clearBuffer();
    }

    float saldo;
    printf("Digite o saldo inicial: ");
    scanf("%f", &saldo);
    clearBuffer();

    while (saldo < 0) {
        printf("Saldo inválido. Informe um valor maior ou igual a zero: ");
        scanf("%f", &saldo);
        clearBuffer();
    }

    // Adicionar o cliente à lista de contas

    return 0;
}

// Apaga um cliente da lista de contas
// Fazer por ultimo!
int apagarCliente(Clientes *t){
    printf("Apagar cliente:\n");
    char cpf[12]; // Incluindo espaço para o caractere nulo '\0'
    printf("Digite o CPF do cliente: ");
    scanf("%s", cpf);
    clearBuffer();
    
    char opcao;
    printf("Você tem certeza que deseja apagar o cliente? (s/n): ");
    scanf(" %c", &opcao);
    clearBuffer();

    if (opcao == 's' || opcao == 'S') {
        //  falta a lógica para apagar o cliente
        printf("Cliente apagado com sucesso!\n");
    } else {
        printf("Operação cancelada.\n");
    }
    return 0;
}

// Lista todos os clientes cadastrados divididos por tipo de conta
int listarClientes(Clientes t){
    printf("Lista de clientes:\n");
    //  falta a lógica para listar os clientes
    return 0;
}

int debito(Clientes *t){
    char cpf[12]; // Incluindo espaço para o caractere nulo '\0'
    printf("Débito:\n");
    printf("Digite o CPF do cliente: ");
    scanf("%s", cpf);
    clearBuffer();

    char senha[7]; // Incluindo espaço para o caractere nulo '\0'
    printf("Digite a senha do cliente: ");
    scanf("%s", senha);
    clearBuffer();

    //  falta a lógica para realizar o débito

    return 0;
}

// Deposito - realiza o depósito de um valor determinado em uma conta
int deposito(Clientes *t){
    char cpf[12]; // Incluindo espaço para o caractere nulo '\0'
    printf("Depósito:\n");
    printf("Digite o CPF do cliente: ");
    scanf("%s", cpf);
    clearBuffer();

    float valor;
    printf("Digite o valor do depósito: ");
    scanf("%f", &valor);
    clearBuffer();

    //  falta a para realizar o depósito

    return 0;
}

// Extrato - gera um arquivo com o histórico de todas as operações realizadas na conta, com datas e valores, incluindo as tarifas.
int extrato(Clientes t){
    char cpf[12]; // Incluindo espaço para o caractere nulo '\0'
    char senha[7]; // Incluindo espaço para o caractere nulo '\0'
    
    printf("Extrato:\n");
    printf("Digite o CPF do cliente: ");
    scanf("%s", cpf);
    clearBuffer();

    printf("Digite a senha do cliente: ");
    scanf("%s", senha);
    clearBuffer();

    // TODO: Implementar a lógica para gerar o extrato

    return 0;
}

// Transferência - realiza a transferência de um valor determinado de uma conta (Origem) para outra conta (Destino)
int transferencia(Clientes *t){
    char cpfOrigem[12]; // Incluindo espaço para o caractere nulo '\0'
    char senha[7]; // Incluindo espaço para o caractere nulo '\0'
    char cpfDestino[12]; // Incluindo espaço para o caractere nulo '\0'
    float valor;

    printf("Transferência:\n");
    printf("Digite o CPF da conta de origem: ");
    scanf("%s", cpfOrigem);
    clearBuffer();

    printf("Digite a senha da conta de origem: ");
    scanf("%s", senha);
    clearBuffer();

    printf("Digite o CPF da conta de destino: ");
    scanf("%s", cpfDestino);
    clearBuffer();

    printf("Digite o valor da transferência: ");
    scanf("%f", &valor);
    clearBuffer();

    // falta a lógica para realizar a transferência

    return 0;
}

// Salva os clientes em um arquivo
// fwrite
int salvar(Clientes t, char nome[]) {
    FILE *arquivo;
    arquivo = fopen(nome, "wb");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    // TODO: Implementar a lógica para salvar as contas no arquivo

    fclose(arquivo);
    return 0;
}

  // Carrega os clientes de um arquivo
// fread
int carregar(Clientes *contas, char nome[]) {
    FILE *arquivo;
    arquivo = fopen(nome, "rb");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    // Declara a variável t
    Clientes *t = contas;
    
    // Lê a quantidade de contas do arquivo
    fread(&t->qtd, sizeof(size_t), 1, arquivo);

    // Aloca memória para o array de contas
    t->contas = (Conta *)malloc(t->qtd * sizeof(Conta));

    if (t->contas == NULL) {
        printf("Erro ao alocar memória.\n");
        fclose(arquivo);
        return 1;
    }

    // Lê as contas do arquivo
    fread(t->contas, sizeof(Conta), t->qtd, arquivo);

    fclose(arquivo);
    return 0;
}
