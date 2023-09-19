#include <stdio.h>
typedef struct {
  char nome[100];
  char cpf[11];
  char senha[6];
  char tipo;
  float saldo;
} Conta;

typedef struct {
  struct Conta *contas;
  size_t qtd;
} Clientes;

void menu();

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

