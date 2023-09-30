#include <stdio.h>
#include <stdbool.h>

// Struct com os extratos de cada conta
// Gera um arquivo com o histórico de todas as operações realizadas na conta, com datas e valores, incluindo as tarifas.
typedef struct {
  double valor;
  double taxa;
  char descricao[100];
} Operacao;

// Struct com os dados de cada conta
typedef struct {
  char nome[100];
  char cpf[11];
  char senha[6];
  int tipo;
  double saldo;
  Operacao extrato[100];
} Conta;

// cs[0].extrato[0].valor

// Struct com os dados de cada cliente
typedef struct {
  // Ponteiro ou lista
  // Conta contas[1000];
  //  Conta *contas;

  // Lista de contas
  Conta contas[1000];
  size_t qtd;
} Clientes;

void menu();

bool validarCPF(char cpf[]);

bool validarSenha(char senha[]);

int lerTecla();

void clearBuffer();

int cadastrarCliente(Clientes *t);

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

