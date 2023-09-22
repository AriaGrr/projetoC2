#include <stdio.h>

typedef struct {
  char nome[100];
  char cpf[11];
  char senha[6];
  int tipo;
  float saldo;
} Conta;

typedef struct {
  // Ponteiro ou lista
  Conta *contas;
  size_t qtd;
} Clientes;

// Struct com os extratos de cada conta
// Gera um arquivo com o histórico de todas as operações realizadas na conta, com datas e valores, incluindo as tarifas.
typedef struct {
  float valor;
  char descricao[100];
} Operacao;


void menu();

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

