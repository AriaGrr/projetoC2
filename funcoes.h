#include <stdio.h>

typedef struct {
  char nome[100];
  char cpf[11];
  char senha[6];
  int tipo;
  float saldo;
} Conta;

typedef struct {
  Conta *contas;
  size_t qtd;
} Clientes;

typedef struct {

} Extrato;

void menu();

int cadastrarCliente(Clientes *lista, Conta *contas);

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

