#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <ctype.h>
#include "funcoes.h"

// Função que imprime o menu principal
void menu()
{
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
// Salva os clientes em um arquivo
// fwrite
int salvar(Clientes t, char nome[])
{
    FILE *arquivo;
    arquivo = fopen(nome, "wb");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    // Lógica para salvar as contas no arquivo
    for (int i = 0; i < t.qtd; i++)
    {
        fwrite(&t.contas[i], sizeof(Conta), 1, arquivo);
    }
    //

    fclose(arquivo);
    return 0;
}

// Carrega os clientes de um arquivo
// fread
int carregar(Clientes *t, char nome[])
{
    FILE *arquivo = fopen(nome, "rb");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    t->qtd = 0;

    while (fread(&t->contas[t->qtd], sizeof(Conta), 1, arquivo) == 1)
    {
        t->qtd++;
    }

    fclose(arquivo);
    return 0;
}
void clearBuffer()
{
    char c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}
// Validar a senha digitada
bool validarSenha(char senha[])
{
    int i;

    // Verifica se a senha tem 6 dígitos.
    if (strlen(senha) != 6)
        return false;

    if (strspn(senha, "1234567890") != strlen(senha))
    {
        return false;
    }
    return true;
}
// Função das validações de CPF
bool validarCPF(char cpf[])
{
    int i;
    // Verifica se o CPF tem 11 dígitos.
    if (strlen(cpf) != 11)
        return false;

    // Verifica se cada caractere do CPF é um dígito.
    for (i = 0; i < strlen(cpf); i++)
    {
        if (!isdigit(cpf[i]))
            return false;
    }

    return true;
}

// Função que retorna a taxa de transação e o valor negativo de cada tipo de conta
int tipoConta(char tipo)
{
    // int taxa, negativo;
    int negativo;
    if (tipo == 1)
    {
        // taxa = 5;
        negativo = -1000;
    }
    else if (tipo == 2)
    {
        // taxa = 3;
        negativo = -5000;
    }
    return negativo;
}

// Função para cadastrar cada cliente
int cadastrarCliente(Clientes *t)
{
    if (t->qtd < 1000)
    {
        printf("Cadastrar cliente:\n");

        char cpf[12]; // Incluindo espaço para o caractere nulo '\0'
        printf("Digite o CPF do cliente: ");
        scanf("%s", cpf);
        clearBuffer();

        while (!validarCPF(cpf))
        {
            printf("CPF inválido. Informe um CPF com 11 dígitos númericos: ");
            scanf("%s", cpf);
            clearBuffer();
        }

        // Verificar se cpf já está cadastrado
        for (int i = 0; i < t->qtd; i++)
        {
            if (strcmp(t->contas[i].cpf, cpf) == 0)
            {
                printf("CPF já cadastrado.\n");
                return 1;
            }
        }

        char senha[7]; // Incluindo espaço para o caractere nulo '\0'
        printf("Digite a senha do cliente: ");
        scanf("%s", senha);
        clearBuffer();

        // Validar que a senha informada tem 6 dígitos
        while (strlen(senha) != 6)
        {
            printf("Senha inválida. Informe uma senha com seis dígitos numéricos: ");
            scanf("%s", senha);
            clearBuffer();
        }

        char nome[100];
        printf("Digite o nome do cliente: ");
        scanf("%s", nome);
        clearBuffer();

        // Verifica se o nome contém apenas letras
        while (strspn(nome, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") != strlen(nome))
        {
            printf("Nome inválido. O nome deve conter apenas letras: ");
            scanf("%s", nome);
            clearBuffer();
        }
        int tipo;
        printf("Escolha o tipo de conta (1 - Comum, 2 - Plus): ");
        scanf("%d", &tipo);
        clearBuffer();

        while (tipo != 1 && tipo != 2)
        {
            printf("Tipo de conta inválido. Escolha 1 para conta comum ou 2 para conta plus: ");
            scanf("%d", &tipo);
            clearBuffer();
        }

        float saldo;
        printf("Digite o saldo inicial: ");
        scanf("%f", &saldo);
        clearBuffer();

        // Verifica se o saldo contém apenas números

        // Verifica se o saldo é maior ou igual a zero
        while (saldo < 0)
        {
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
        t->contas[t->qtd].qtdext = 0;
        t->qtd++;
        // //Salva a criação da conta no extrato
        // sprintf(t->contas[t->qtd].extrato[t->contas[t->qtd].qtdext].text, "Déposito na criação de %.2lf", saldo);
    }
    else
    {
        printf("Não é possível cadastrar mais clientes.\n");
    }

    return 0;
}

// Apaga um cliente da lista de contas
int apagarCliente(Clientes *t)
{
    printf("Apagar cliente:\n");
    char cpf[12]; // Incluindo espaço para o caractere nulo '\0'
    printf("Digite o CPF do cliente: ");
    clearBuffer();
    scanf("%s", cpf);
    clearBuffer();

    while (strlen(cpf) != 11)
    {
        printf("CPF inválido. Informe um CPF com 11 dígitos: ");
        scanf("%s", cpf);
        clearBuffer();
    }

    // Verificar se cpf está cadastrado
    for (int i = 0; i < t->qtd; i++)
    {
        if (strcmp(t->contas[i].cpf, cpf) == 0)
        {
            char opcao;
            printf("Você tem certeza que deseja apagar o cliente? (s/n): ");
            scanf(" %c", &opcao);
            clearBuffer();

            if (opcao == 's' || opcao == 'S')
            {
                //  Lógica para apagar o cliente
                t->contas[i] = t->contas[t->qtd - 1];
                t->qtd--;
                //
                printf("Cliente apagado com sucesso!\n");
            }
            else
            {
                printf("Operação cancelada.\n");
            }
        }
        else
        {
            printf("CPF não encontrado.\n");
            return 1;
        }
    }
    return 0;
}

// Lista todos os clientes cadastrados divididos por tipo de conta
int listarClientes(Clientes t)
{
    printf("Lista de clientes:\n");
    printf("Total de clientes cadastrados: %ld\n", t.qtd);
    printf("\n");

    if (t.qtd == 0)
    {
        printf("Não há clientes cadastrados.\n");
    }
    else
    {
        printf("Clientes com conta comum:\n");
        for (int i = 0; i < t.qtd; i++)
        {
            if (t.contas[i].tipo == 1)
            {
                printf("Nome: %s\n", t.contas[i].nome);
                printf("CPF: %s\n", t.contas[i].cpf);
                printf("Saldo: %.2lf\n", t.contas[i].saldo);
                printf("\n");
            }
        }
        printf("Clientes com conta plus:\n");
        for (int i = 0; i < t.qtd; i++)
        {
            if (t.contas[i].tipo == 2)
            {
                printf("Nome: %s\n", t.contas[i].nome);
                printf("CPF: %s\n", t.contas[i].cpf);
                printf("Saldo: %.2lf\n", t.contas[i].saldo);
                printf("\n");
            }
        }
    }
    return 0;
}

// Função para o débito
int debito(Clientes *t)
{
    printf("Débito:\n");
    char cpf[12]; // Incluindo espaço para o caractere nulo '\0'
    printf("Digite o CPF do cliente: ");
    scanf("%s", cpf);
    clearBuffer();

    while (!validarCPF(cpf))
    {
        printf("CPF inválido. Informe um CPF com 11 dígitos númericos: ");
        scanf("%s", cpf);
        clearBuffer();
    }

    char senha[7]; // Incluindo espaço para o caractere nulo '\0'
    printf("Digite a senha do cliente: ");
    scanf("%s", senha);
    clearBuffer();

    // Validar a senha
    while (!validarSenha(senha))
    {
        printf("Senha inválida. Informe uma senha com 6 dígitos númericos: ");
        scanf("%s", senha);
        clearBuffer();
    }

    float valor, porcentagem, saldo;
    int taxa, negativo;
    printf("Digite o valor do débito: ");
    scanf("%f", &valor);
    clearBuffer();

    while (valor < 0)
    {
        printf("Valor inválido. Informe um valor maior que zero: ");
        scanf("%f", &valor);
        clearBuffer();
    }

    // Lógica para realizar o débito
    for (int i = 0; i < t->qtd; i++)
    {
        if (strcmp(t->contas[i].cpf, cpf) == 0)
        {
            negativo = tipoConta(t->contas[i].tipo);
            if (negativo == -5000)
            {
                taxa = 5;
            }
            else
            {
                taxa = 3;
            }
            porcentagem = (valor * taxa) / 100;
            saldo = t->contas[i].saldo - valor - porcentagem;
            if (saldo < negativo)
            {
                printf("Saldo insuficiente.\n");
                return 1;
            }
            else
            {
                t->contas[i].saldo -= valor + porcentagem;
                sprintf(t->contas[i].extrato[t->contas[i].qtdext].text,
                        "Débito feito no valor de: %.2lf | Taxa: %.2lf | Saldo: %.lf",
                        valor, porcentagem, t->contas[i].saldo); // salva extrato
                t->contas[i].qtdext++;
                printf("Débito realizado com sucesso!\n");
                printf("Novo saldo: %.2lf\n", t->contas[i].saldo);
            }
        }
    }
    return 0;
}

// Função do déposito
int deposito(Clientes *t)
{
    printf("Depósito:\n");

    char cpf[12]; // Incluindo espaço para o caractere nulo '\0'
    printf("Digite o CPF do cliente: ");
    scanf("%s", cpf);
    clearBuffer();

    while (!validarCPF(cpf))
    {
        printf("CPF inválido. Informe um CPF com 11 dígitos númericos: ");
        scanf("%s", cpf);
        clearBuffer();
    }

    float valor;
    printf("Digite o valor do depósito: ");
    scanf("%f", &valor);
    clearBuffer();

    while (valor < 0)
    {
        printf("Valor inválido. Informe um valor maior que zero: ");
        scanf("%f", &valor);
        clearBuffer();
    }
    // Lógica para realizar o depósito
    for (int i = 0; i < t->qtd; i++)
    {
        if (strcmp(t->contas[i].cpf, cpf) == 0)
        {
            t->contas[i].saldo += valor;
            printf("Depósito realizado com sucesso!\n");
            printf("Novo saldo: %.2lf\n", t->contas[i].saldo);
            sprintf(t->contas[i].extrato[t->contas[i].qtdext].text, "Déposito feito no valor de %.2lf | Saldo: %.2lf", valor, t->contas[i].saldo); // salva extrato
            t->contas[i].qtdext++;
        }
    }
    //

    return 0;
}
// Função para transferencias
int transferencia(Clientes *t)
{

    printf("Transferência:\n");

    char cpfOrigem[12];  // Incluindo espaço para o caractere nulo '\0'
    char senha[7];       // Incluindo espaço para o caractere nulo '\0'
    char cpfDestino[12]; // Incluindo espaço para o caractere nulo '\0'
    float valor, porcentagem, saldo;
    int taxa, negativo;

    printf("Digite o CPF da conta de origem: ");
    scanf("%s", cpfOrigem);
    clearBuffer();

    while (!validarCPF(cpfOrigem))
    {
        printf("CPF inválido. Informe um CPF com 11 dígitos númericos: ");
        scanf("%s", cpfOrigem);
        clearBuffer();
    }
    // Verificar se cpf está cadastrado
    for (int i = 0; i < t->qtd; i++)
    {
        if (strcmp(t->contas[i].cpf, cpfOrigem) == 0)
        {

            printf("Digite a senha da conta de origem: ");
            scanf("%s", senha);
            clearBuffer();

            // Validar a senha
            while (!validarSenha(senha))
            {
                printf("Senha inválida. Informe uma senha com 6 dígitos númericos: ");
                scanf("%s", senha);
                clearBuffer();
            }
        }
        if (strcmp(t->contas[i].senha, senha) == 0)
        {
            printf("Digite o CPF da conta de destino: ");
            scanf("%s", cpfDestino);
            clearBuffer();

            while (!validarCPF(cpfDestino))
            {
                printf("CPF inválido. Informe um CPF com 11 dígitos númericos: ");
                scanf("%s", cpfDestino);
                clearBuffer();
            }

            for (int i = 0; i < t->qtd; i++)
            {
                if (strcmp(t->contas[i].cpf, cpfDestino) == 0)
                {

                    printf("Digite o valor da transferência: ");
                    scanf("%f", &valor);
                    clearBuffer();

                    while (valor < 0)
                    {
                        printf("Valor inválido. Informe um valor maior que zero: ");
                        scanf("%f", &valor);
                        clearBuffer();
                    }
                    // Lógica para realizar a transferência
                    for (int i = 0; i < t->qtd; i++)
                    {
                        if (strcmp(t->contas[i].cpf, cpfOrigem) == 0)
                        {
                            negativo = tipoConta(t->contas[i].tipo);
                            if (negativo == -5000)
                            {
                                taxa = 5;
                            }
                            else
                            {
                                taxa = 3;
                            }
                            porcentagem = (valor * taxa) / 100;
                            saldo = t->contas[i].saldo - valor - porcentagem;
                            if (saldo < negativo)
                            {
                                printf("Saldo insuficiente.\n");
                                return 1;
                            }
                            else
                            {
                                t->contas[i].saldo -= valor + porcentagem;
                                printf("Transferencia realizada com sucesso!\n");
                                printf("Novo saldo: %.2lf\n", t->contas[i].saldo);
                                sprintf(
                                    t->contas[i]
                                        .extrato[t->contas[i].qtdext]
                                        .text,
                                    "Transferência: %.2lf | Tarifa: %.2f | Saldo: %.2lf ",
                                    valor, porcentagem, t->contas[i].saldo); // Salva extrato
                                t->contas[i].qtdext++;
                                for (int i = 0; i < t->qtd; i++)
                                {
                                    if (strcmp(t->contas[i].cpf, cpfDestino) == 0)
                                    {

                                        t->contas[i].saldo += valor;
                                        sprintf(t->contas[i]
                                                    .extrato[t->contas[i].qtdext]
                                                    .text,
                                                "Transferência feita pelo cpf %s no valor de %.2lf",
                                                cpfOrigem, valor); // salva extrato
                                        t->contas[i].qtdext++;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}

// Função do extrato
int extrato(Clientes t, char arqextrato[])
{
    printf("Extrato:\n");

    char cpf[12];  // Incluindo espaço para o caractere nulo '\0'
    char senha[7]; // Incluindo espaço para o caractere nulo '\0'
    char arquivo[30];
    printf("Digite o CPF do cliente: ");
    scanf("%s", cpf);
    clearBuffer();

    while (!validarCPF(cpf))
    {
        printf("CPF inválido. Informe um CPF com 11 dígitos númericos: ");
        scanf("%s", cpf);
        clearBuffer();
    }

    for (int i = 0; i < t.qtd; i++)
    {
        if (strcmp(t.contas[i].cpf, cpf) == 0)
        {
            printf("Digite a senha do cliente: ");
            scanf("%s", senha);
            clearBuffer();
            // Validar a senha
            while (!validarSenha(senha))
            {
                printf("Senha inválida. Informe uma senha com 6 dígitos númericos: ");
                scanf("%s", senha);
                clearBuffer();
            }

            if (validarCPF(cpf) && validarSenha(senha))
            {
                if (strcmp(t.contas[i].senha, senha) == 0)
                {
                    sprintf(arquivo, "extratoCpf:%s.txt", cpf);
                    FILE *f = fopen(arquivo, "w");

                    if (f == NULL)
                    {
                        printf("Falha ao abrir o arquivo");
                    }

                    // Extratos para o arquivo
                    for (int iext = 0;
                         iext < t.contas[i].qtdext;
                         iext++)
                    {
                        fprintf(f, "%s\n", t.contas[i].extrato[iext].text);
                        //printf("indice %d %s\n", iext,t.contas[i].extrato[iext].text);
                    }
                    fclose(f);
                    printf("Extrato gerado com sucesso!\n");
                    printf("Transações realizadas: %d\n", t.contas[i].qtdext);
                    // Por teste iremos imprimir o extrato na tela também
                    for (int index = 0; index < t.contas[i].qtdext; index++)
                    {
                        printf("%s\n", t.contas[i].extrato[index].text);
                    }
                }
            }
        }
    }
    return 0;
}
/*  */
