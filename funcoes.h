#include <stdio.h>

void menu();
typedef struct {
  char nome[100];
  char cpf[11];
  char senha[6];
  char tipo [10];
  float saldo;
} Conta;

typedef struct {
  struct Conta *contas;
  size_t qtd;
} Clientes;

int cadastrarCliente();

int apagarCliente();

int listarClientes();

int debito();

int deposito();

int extrato();

int transferencia();

int tipoConta(char tipo);

// fwrite
int salvar(Clientes t, char nome[]);
// fread
int carregar(Clientes *t, char nome[]);

