#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

int main(){
    int cod;
    char arquivo[] = "clientes";
    Clientes t;

    cod = carregar(&t, arquivo);
    if (cod == 1) {
        t.qtd = 0;
    }

    int opcao;

    do{    
        menu();
        scanf("%d", &opcao);
        printf("%d\n", opcao);
    if(opcao == 0){
        printf("Saindo...\n");
    }
    else if (opcao == 1){
        cadastrarCliente(&listas, &contas);
        system("clear");
    }
    else if (opcao == 2){
        apagarCliente(&t);
        system("clear");
    }
    else if (opcao == 3){
        system("clear");
        listarClientes(t); 
        printf("Pressione Enter para voltar ao menu...");
        getchar(); // Captura o Enter
        getchar(); // Aguarda o próximo Enter

        system("clear");
    }
    else if (opcao == 4){
        debito(&t);
        system("clear");
    }
    else if (opcao == 5){
        deposito(&t);
        system("clear");
    }
    else if (opcao == 6){
        system("clear");
        extrato(t);
        printf("Pressione Enter para voltar ao menu...");
        getchar(); // Captura o Enter
        getchar(); // Aguarda o próximo Enter

        system("clear");
    }
    else if (opcao == 7){
        transferencia(&t);
        system("clear");
    }
     else {
            wprintf(L"Opção não existe!\n");
        }
    } while (opcao != 0);

    cod = salvar(t, arquivo);
    if (cod != 0){
        printf("Erro ao salvar!\n");
    }
    return 0;
}
