#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <ctype.h>
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

bool validarSenha(char senha[])
{
    int i;

    // Verifica se a senha tem 6 dígitos.
    if (strlen(senha) != 6)
        return false;

    //   // Verifica se cada caractere da senha é um dígito.
    //   for (i = 0; i < strlen(senha); i++) {
    //     if (!isdigit(senha[i]))
    //       return false;
    //   }
    if (strspn(senha, "1234567890") != strlen(senha))
    {
        return false;
    }
    return true;
}
// Função das validações de CPF
bool validarCPF(char cpf[]){
  int i;
  // Verifica se o CPF tem 11 dígitos.
  if (strlen(cpf) != 11)
    return false;

  // Verifica se cada caractere do CPF é um dígito.
  for (i = 0; i < strlen(cpf); i++) {
    if (!isdigit(cpf[i]))
      return false;
  }

  return true;
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
int cadastrarCliente(Clientes *t){
    if (t->qtd < 1000) {
        printf("Cadastrar cliente:\n");

        char cpf[12]; // Incluindo espaço para o caractere nulo '\0'
        printf("Digite o CPF do cliente: ");
        scanf("%s", cpf);
        clearBuffer();

        // // Validar que o CPF informado tem 11 dígitos
        // while (strlen(cpf) != 11) {
        //     printf("CPF inválido. Informe um CPF com 11 dígitos: ");
        //     scanf("%s", cpf);
        //     clearBuffer();
        // }
        while (!validarCPF(cpf)) {
            printf("CPF inválido. Informe um CPF com 11 dígitos númericos: ");
            scanf("%s", cpf);
            clearBuffer();
        }

        // Verificar se cpf já está cadastrado
        for (int i = 0; i < t->qtd; i++) {
            if (strcmp(t->contas[i].cpf, cpf) == 0) {
                printf("CPF já cadastrado.\n");
                return 1;
            }
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

        // Verifica se o saldo contém apenas números

        // Verifica se o saldo é maior ou igual a zero
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

// Apaga um cliente da lista de contas
int apagarCliente(Clientes *t)
{
    printf("Apagar cliente:\n");
    // while (lerTecla() != 1) {
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
    // }
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
                printf("Tipo: %d\n", t.contas[i].tipo);
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
                printf("Tipo: %d\n", t.contas[i].tipo);
                printf("Saldo: %.2lf\n", t.contas[i].saldo);
                printf("\n");
            }
        }
    }
    // lógica para listar os clientes
    // for (int i = 0; i < t.qtd; i++) {
    //     printf("Nome: %s\n", t.contas[i].nome);
    //     printf("CPF: %s\n", t.contas[i].cpf);
    //     printf("Tipo: %d\n", t.contas[i].tipo);
    //     printf("Saldo: %.2f\n", t.contas[i].saldo);
    //     printf("\n");
    // }
    return 0;
}

// int debito(Clientes *t) {
//     char cpf[12];
//     printf("Débito:\n");
//     printf("Digite o CPF do cliente: ");
//     scanf("%s", cpf);
//     clearBuffer();

//     // Validar que o CPF tem 11 dígitos numéricos
//     while (strlen(cpf) != 11 || !validarCPF(cpf)) {
//         printf("CPF inválido. Informe um CPF com 11 dígitos numéricos: ");
//         scanf("%s", cpf);
//         clearBuffer();
//     }

//     char senha[7];
//     printf("Digite a senha do cliente: ");
//     scanf("%s", senha);
//     clearBuffer();

//     int index = -1;
//     for (int i = 0; i < t->qtd; i++) {
//         if (strcmp(t->contas[i].cpf, cpf) == 0) {
//             index = i;
//             break;
//         }
//     }

//     if (index == -1) {
//         printf("Conta não encontrada.\n");
//         return 1;
//     }

//     if (strcmp(t->contas[index].senha, senha) != 0) {
//         printf("Senha incorreta.\n");
//         return 1;
//     }

//     float valor;
//     printf("Digite o valor do débito: ");
//     scanf("%f", &valor);
//     clearBuffer();

//     if (t->contas[index].saldo < valor) {
//         printf("Saldo insuficiente.\n");
//         return 1;
//     }

//     t->contas[index].saldo -= valor;
//     printf("Débito realizado com sucesso. Novo saldo: %.2lf\n", t->contas[index].saldo);
//     return 0;
// }
int debito(Clientes *t)
{
    printf("Débito:\n");
    // while (lerTecla() != 1) {
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
            taxa, negativo = tipoConta(t->contas[i].tipo);
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
                printf("Débito realizado com sucesso!\n");
                printf("Novo saldo: %.2lf\n", t->contas[i].saldo);
                // Salvar no extrato
                t->contas[i].extrato[t->qtd]->valor = valor;
                t->contas[i].extrato[t->qtd]->taxa = porcentagem;
                strcpy(t->contas[i].extrato[t->qtd]->descricao, "Débito");
                //
            }
        }
    }
    //
    // }
    return 0;
}

int deposito(Clientes *t) {
    char cpf[12];
    printf("Depósito:\n");
    printf("Digite o CPF do cliente: ");
    scanf("%s", cpf);
    clearBuffer();

    int index = -1;
    for (int i = 0; i < t->qtd; i++) {
        if (strcmp(t->contas[i].cpf, cpf) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Conta não encontrada.\n");
        return 1;
    }

    float valor;
    printf("Digite o valor do depósito: ");
    scanf("%f", &valor);
    clearBuffer();

    if (valor <= 0) {
        printf("Valor de depósito inválido.\n");
        return 1;
    }

    // t->contas[index].saldo += valor;
    // printf("Depósito realizado com sucesso. Novo saldo: %.2lf\n", t->contas[index].saldo);
    // return 0;

  // Lógica para realizar o depósito
  for (int i = 0; i < t->qtd; i++)
  {
      if (strcmp(t->contas[i].cpf, cpf) == 0)
      {
          t->contas[i].saldo += valor;
          printf("Depósito realizado com sucesso!\n");
          printf("Novo saldo: %.2lf\n", t->contas[i].saldo);
          // Salvar no extrato
          t->contas[i].extrato[t->qtd]->valor = valor;
          t->contas[i].extrato[t->qtd]->taxa = 0;
          strcpy(t->contas[i].extrato[t->qtd]->descricao, "Déposito");
      }
  }
  //
  // }
  return 0;
}


// Extrato - gera um arquivo com o histórico de todas as operações realizadas na conta, com datas e valores, incluindo as tarifas.
// int extrato(Clientes t) {
//     char cpf[12];
//     char senha[7];
//     printf("Extrato:\n");
//     printf("Digite o CPF do cliente: ");
//     scanf("%s", cpf);
//     clearBuffer();

//     int index = -1;
//     for (int i = 0; i < t.qtd; i++) {
//         if (strcmp(t.contas[i].cpf, cpf) == 0) {
//             index = i;
//             break;
//         }
//     }

//     if (index == -1) {
//         printf("Conta não encontrada.\n");
//         return 1;
//     }

//     printf("Digite a senha do cliente: ");
//     scanf("%s", senha);
//     clearBuffer();

//     if (strcmp(t.contas[index].senha, senha) != 0) {
//         printf("Senha incorreta.\n");
//         return 1;
//     }

//     // Lógica para gerar o extrato em um arquivo de texto (arquivo.txt, por exemplo)
//     FILE *extratoFile = fopen("extrato.txt", "w");
//     fprintf(extratoFile, "Extrato da conta de %s\n", t.contas[index].nome);
//     // Aqui, você pode adicionar mais informações ao extrato, como datas e operações.
//     fprintf(extratoFile, "Saldo atual: %.2lf\n", t.contas[index].saldo);
//     fclose(extratoFile);

//     printf("Extrato gerado com sucesso.\n");
//     return 0;
// }
int extrato(Clientes t)
{
    printf("Extrato:\n");

        char cpf[12]; // Incluindo espaço para o caractere nulo '\0'
        char senha[7]; // Incluindo espaço para o caractere nulo '\0'
        printf("Digite o CPF do cliente: ");
        scanf("%s", cpf);
        clearBuffer();

            while (!validarCPF(cpf)) {

                break;

                printf("CPF inválido. Informe um CPF com 11 dígitos númericos: ");
                scanf("%s", cpf);
                clearBuffer();
            }

        for (int i = 0; i < t.qtd; i++) {
            if (strcmp(t.contas[i].cpf, cpf) == 0) {

        printf("Digite a senha do cliente: ");
        scanf("%s", senha);
        clearBuffer();

            // Validar a senha
            while (!validarSenha(senha)) {
                printf("Senha inválida. Informe uma senha com 6 dígitos númericos: ");
                scanf("%s", senha);
                clearBuffer();
            }

        for (int i = 0; i < t.qtd; i++) {
            if (strcmp(t.contas[i].senha, senha) == 0) {
                // Lógica para gerar o extrato em txt, anotando todas as transações da conta requerida
            // Abre o arquivo TXT
            FILE *arquivo = fopen("extrato.txt", "w");

            // Verifica se o arquivo foi aberto com sucesso
            if (arquivo == NULL) {
                printf("Erro ao abrir o arquivo.\n");
                return 1;
            }
            // Escreve o cabeçalho do arquivo
            fprintf(arquivo, "Descrição | Valor | Taxa \n");

            int qtd = t.qtd;
            // Aloca memória para um vetor de 2 operações
            Operacao *extrato = malloc(qtd * sizeof(Operacao));

            // Escreve as transações do extrato
            for (int i = 0; i < qtd; i++) {
                fprintf(arquivo, "%s | %.2lf | %.2lf \n", extrato[i].descricao, extrato[i].valor, extrato[i].taxa);
              printf("%s | %.2lf | %.2lf \n" , extrato[i].descricao, extrato[i].valor, extrato[i].taxa);
            }

            // Fecha o arquivo
            fclose(arquivo);

            free (extrato);
                printf("Extrato gerado com sucesso!\n");
                printf("Saldo: %.2lf\n", t.contas[i].saldo);

            } 
        }
            } 
        }

     // TODO: Implementar a lógica para gerar o extrato em txt

  return 0;
}



int transferencia(Clientes *t)
{
    printf("Transferência:\n");

    // while (lerTecla() != 1) {
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
        else
        {
            printf("CPF não encontrado.\n");
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
                            taxa, negativo = tipoConta(t->contas[i].tipo);
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
                                printf("Transferencia realizado com sucesso!\n");
                                printf("Novo saldo: %.2lf\n", t->contas[i].saldo);
                                // Salvar no extrato
                                t->contas[i].extrato[t->qtd]->valor = valor;
                                t->contas[i].extrato[t->qtd]->taxa = porcentagem;
                                strcpy(t->contas[i].extrato[t->qtd]->descricao, "Transferencia");
                                //
                            }
                        }
                    }

                    for (int i = 0; i < t->qtd; i++)
                    {
                        if (strcmp(t->contas[i].cpf, cpfDestino) == 0)
                        {

                            t->contas[i].saldo += valor;
                            printf("Transferencia realizada com sucesso!\n");
                            printf("Novo saldo: %.2lf\n", t->contas[i].saldo);
                            // Salvar no extrato
                            t->contas[i].extrato[t->qtd]->valor = valor;
                            strcpy(t->contas[i].extrato[t->qtd]->descricao, "Transferencia");
                            //
                        }
                        else
                        {
                            printf("Senha incorreta.\n");
                        }
                    }
                }
            }
        }
    }
// }
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

    // Lógica para salvar as contas no arquivo
    for (int i = 0; i < t.qtd; i++) {
        fwrite(&t.contas[i], sizeof(Conta), 1, arquivo);
    }
    //

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

    t->qtd = 0;

    while (fread(&t->contas[t->qtd], sizeof(Conta), 1, arquivo) == 1) {
        t->qtd++;
    }

    fclose(arquivo);
    return 0;
}
