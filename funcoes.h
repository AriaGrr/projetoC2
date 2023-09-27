#include <stdio.h>

// Struct com os extratos de cada conta
// Gera um arquivo com o histórico de todas as operações realizadas na conta, com datas e valores, incluindo as tarifas.
typedef struct {
  double valor;
  double taxa
  char descricao[100];
} Operacao;

// Struct com os dados de cada conta
typedef struct {
  char nome[100];
  char cpf[11];
  char senha[6];
  int tipo;
  float saldo;
  struct operacao *extrato[100];
} Conta;

struct cliente cs[1000];

// cs[0].extrato[0].valor

// // Struct com os dados de cada cliente
// typedef struct {
//   // Ponteiro ou lista
//   Conta contas[1000];
//   // Conta *contas;
//   size_t qtd;
// } Clientes;

void menu();

void clearBuffer();

int cadastrarCliente(Clientes *listas, Conta *contas);

int apagarCliente(Clientes *t);

int listarClientes(Clientes t);

int debito(Clientes *t);

int deposito(Clientes *t);

//Struct com os extratos?
int extrato(Clientes t);

int transferencia(Clientes *t);

int tipoConta(char tipo);

// fwrite
int salvar(Clientes t, char nome[]);
// fread
int carregar(Clientes *t, char nome[]);

