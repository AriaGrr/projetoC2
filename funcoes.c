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
char tipoDeConta; // Corrija o tipo para char
int taxa, negativo;
printf("Escolha o tipo de conta (1 - Comum, 2 - Plus): ");
scanf(" %c", &tipoDeConta);
clearBuffer();
tipoConta(tipoDeConta, &taxa, &negativo);


    // Função para cadastrar cada cliente
    int cadastrarCliente(Clientes *t){
        if (t->qtd < 1000) {
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

            int tipoDeConta;
            printf("Escolha o tipo de conta (1 - Comum, 2 - Plus): ");
            scanf("%d", &tipo);
            clearBuffer();

            while (tipo != 1 && tipo != 2) {
                printf("Tipo de conta inválido. Escolha 1 para conta comum ou 2 para conta plus: ");
                scanf("%d", &tipo);
                clearBuffer();
            }

            // Variáveis para armazenar a taxa e o valor negativo
            int taxa, negativo;
            tipoConta(tipo, &taxa, &negativo);

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
            t->contas[t->qtd].saldo = saldo;
            strcpy(t->contas[t->qtd].nome, nome);
            strcpy(t->contas[t->qtd].cpf, cpf);
            strcpy(t->contas[t->qtd].senha, senha);
            t->contas[t->qtd].tipo = tipo;
            t->qtd++;

            
        } else {
            printf("Não é possível cadastrar mais clientes.\n");
        }

        return 0;
    }
        
    // Adicionar o cliente à lista de contas
    t->contas[t->qtd].saldo = saldo;
    strcpy(t->contas[t->qtd].nome, nome);
    strcpy(t->contas[t->qtd].cpf, cpf);
    strcpy(t->contas[t->qtd].senha, senha);
    t->contas[t->qtd].tipo = tipo;
    t->qtd++;

    } else {
        printf("Não é possível cadastrar mais clientes.\n");
    }

    return 0;
}

// Apaga um cliente da lista de contas
// Fazer por ultimo!
int apagarCliente(Clientes *t) {
   printf("\nAguardando implementação...\n\n");
}


// Lista todos os clientes cadastrados divididos por tipo de conta
int listarClientes(Clientes t){
    printf("Lista de clientes:\n");
    printf("Total de clientes cadastrados: %d\n", t.qtd);
    printf("\n");

    if(t.qtd == 0){
        printf("Não há clientes cadastrados.\n");
    }
    else{
        printf("Clientes com conta comum:\n");
        for (int i = 0; i < t.qtd; i++) {
            if (t.contas[i].tipo == 1) {
                printf("Nome: %s\n", t.contas[i].nome);
                printf("CPF: %s\n", t.contas[i].cpf);
                printf("Tipo: %d\n", t.contas[i].tipo);
                printf("Saldo: %.2f\n", t.contas[i].saldo);
                printf("\n");
            }
        }
        printf("Clientes com conta plus:\n");
        for (int i = 0; i < t.qtd; i++) {
            if (t.contas[i].tipo == 2) {
                printf("Nome: %s\n", t.contas[i].nome);
                printf("CPF: %s\n", t.contas[i].cpf);
                printf("Tipo: %d\n", t.contas[i].tipo);
                printf("Saldo: %.2f\n", t.contas[i].saldo);
                printf("\n");
            }
        }
    }
    //  falta a lógica para listar os clientes
    // for (int i = 0; i < t.qtd; i++) {
    //     printf("Nome: %s\n", t.contas[i].nome);
    //     printf("CPF: %s\n", t.contas[i].cpf);
    //     printf("Tipo: %d\n", t.contas[i].tipo);
    //     printf("Saldo: %.2f\n", t.contas[i].saldo);
    //     printf("\n");
    // }    
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

    // Lógica para realizar o débito
    int index = -1; // Variável para armazenar o índice do cliente encontrado

    // Percorremos a lista de clientes para procurar o cliente com o CPF fornecido
    for (int i = 0; i < t->qtd; i++) {
        if (strcmp(t->clientes[i].cpf, cpf) == 0 && strcmp(t->clientes[i].senha, senha) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Cliente não encontrado ou senha incorreta.\n");
        return 0;
    }

    float valorDebito;
    printf("Digite o valor do débito: ");
    scanf("%f", &valorDebito);
    clearBuffer();

    // Verificamos se o cliente possui saldo suficiente para o débito
    if (t->clientes[index].saldo >= valorDebito) {
        t->clientes[index].saldo -= valorDebito;
        printf("Débito realizado com sucesso. Novo saldo: %.2f\n", t->clientes[index].saldo);
    } else {
        printf("Saldo insuficiente para o débito.\n");
    }

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

    // Lógica para realizar o depósito
    int index = -1; // Variável para armazenar o índice do cliente encontrado

    // Percorremos a lista de clientes para procurar o cliente com o CPF fornecido
    for (int i = 0; i < t->numClientes; i++) {
        if (strcmp(t->clientes[i].cpf, cpf) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Cliente não encontrado.\n");
        return 0;
    }

    t->clientes[index].saldo += valor;
    printf("Depósito realizado com sucesso. Novo saldo: %.2f\n", t->clientes[index].saldo);

    return 0;
}

// Extrato - gera um arquivo com o histórico de todas as operações realizadas na conta, com datas e valores, incluindo as tarifas.
int extrato(Clientes t, int index){
    // ...

    // Abre o arquivo para escrita
    FILE *arquivo;
    arquivo = fopen("historico_operacoes.txt", "a"); // "a" para abrir o arquivo em modo de adição

    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo de histórico de operações.\n");
        return 0;
    }

    // Obtém a data e hora atual
    time_t tempoAtual;
    struct tm *infoTempo;
    char dataHora[20]; // String para armazenar a data e hora formatada

    time(&tempoAtual);
    infoTempo = localtime(&tempoAtual);

    // Formata a data e hora no formato "dd/mm/aaaa hh:mm:ss"
    strftime(dataHora, sizeof(dataHora), "%d/%m/%Y %H:%M:%S", infoTempo);

    // Escreve a operação no arquivo de histórico
    fprintf(arquivo, "Data/Hora: %s - Operação: Extrato\n", dataHora);
    fprintf(arquivo, "Nome: %s - CPF: %s - Saldo: %.2f\n\n", t.contas[index].nome, t.contas[index].cpf, t.contas[index].saldo);

    // Fecha o arquivo
    fclose(arquivo);

    // ...

    return 0;
}

// Transferência - realiza a transferência de um valor determinado de uma conta (Origem) para outra conta (Destino)
int transferencia(Clientes *t) {
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

    int indexOrigem = -1;
    int indexDestino = -1;

    // Encontrar o índice da conta de origem pelo CPF e verificar a senha
    for (int i = 0; i < t->qtd; i++) {
        if (strcmp(t->contas[i].cpf, cpfOrigem) == 0 && strcmp(t->contas[i].senha, senha) == 0) {
            indexOrigem = i;
            break;
        }
    }

    // Encontrar o índice da conta de destino pelo CPF
    for (int i = 0; i < t->qtd; i++) {
        if (strcmp(t->contas[i].cpf, cpfDestino) == 0) {
            indexDestino = i;
            break;
        }
    }

    if (indexOrigem == -1) {
        printf("Conta de origem não encontrada ou senha incorreta.\n");
    } else if (indexDestino == -1) {
        printf("Conta de destino não encontrada.\n");
    } else if (t->contas[indexOrigem].saldo < valor) {
        printf("Saldo insuficiente para a transferência.\n");
    } else {
        // Realizar a transferência
        t->contas[indexOrigem].saldo -= valor;
        t->contas[indexDestino].saldo += valor;
        printf("Transferência realizada com sucesso.\n");
    }

    return 0;
}


// Salva os clientes em um arquivo
// fwrite
// Salva os clientes em um arquivo
int salvar(Clientes t, char nome[]) {
    FILE *arquivo;
    arquivo = fopen(nome, "wb"); // Abra o arquivo em modo binário para escrita

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    // Escreva o número de clientes no início do arquivo
    fwrite(&(t.qtd), sizeof(int), 1, arquivo);

    // Escreva cada cliente no arquivo
  for (size_t i = 0; i < (size_t)t.qtd; i++) {
    fwrite(&(t.contas[i]), sizeof(Conta), 1, arquivo);
}


    fclose(arquivo);
    return 0;
}

// Carrega os clientes de um arquivo
// Carrega os clientes de um arquivo
int carregar(Clientes *t, char nome[]) {
    FILE *arquivo;
    arquivo = fopen(nome, "rb"); // Abra o arquivo em modo binário para leitura

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    // Leia o número de clientes do início do arquivo
    fread(&(t->qtd), sizeof(int), 1, arquivo);

    // Leia cada cliente do arquivo
    for (size_t i = 0; i < (size_t)t->qtd; i++) { // Use size_t para o índice
        fread(&(t->contas[i]), sizeof(Conta), 1, arquivo);
    }

    fclose(arquivo);
    return 0;
}
