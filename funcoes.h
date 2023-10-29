#include <stdio.h>
#include <stdbool.h>

// Struct com os extratos de cada conta
// Gera um arquivo com o histórico de todas as operações realizadas na conta
typedef struct {
  char text[150];
} Operacao;

// Struct com os dados de cada conta
typedef struct {
  char nome[100];
  char cpf[12];
  char senha[7];
  int tipo;
  double saldo;
  Operacao extrato[100];
  int qtdext;
} Conta;

// Struct com os dados de cada cliente
typedef struct {
  Conta contas[10]; // Menos contas para poder testar no replit
  size_t qtd;
} Clientes;

void menu();

bool validarCPF(char cpf[]);

void clearBuffer();

int cadastrarCliente(Clientes *t);

int apagarCliente(Clientes *t);

int listarClientes(Clientes t);

int debito(Clientes *t);

int deposito(Clientes *t);

int transferencia(Clientes *t);

int extrato(Clientes t, char arqextrato[]);

int tipoConta(char tipo);

// fwrite
int salvar(Clientes t, char nome[]);
// fread
int carregar(Clientes *t, char nome[]);

