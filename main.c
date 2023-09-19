#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "funcoes.h"

#ifdef _WIN32 // Verifica se é Windows
    #define CLEAR_SCREEN "cls"
    #define PAUSE "pause"
#else
    #define CLEAR_SCREEN "clear"
    #define PAUSE "read -p 'Pressione Enter para continuar...' -n1 -s"
#endif


int main(){
    setlocale(LC_ALL, "Portuguese");

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
        cadastrarCliente(&t);
        system(CLEAR_SCREEN);
    }
    else if (opcao == 2){
        apagarCliente(&t);
        system(CLEAR_SCREEN);
    }
    else if (opcao == 3){
        system(CLEAR_SCREEN);
        listarClientes(t); 
        printf("Pressione Enter para voltar ao menu...");
        getchar(); // Captura o Enter
        getchar(); // Aguarda o próximo Enter

        system(CLEAR_SCREEN);
    }
    else if (opcao == 4){
        debito(&t);
        system(CLEAR_SCREEN);
    }
    else if (opcao == 5){
        deposito(&t);
        system(CLEAR_SCREEN);
    }
    else if (opcao == 6){
        system(CLEAR_SCREEN);
        extrato(t);
        printf("Pressione Enter para voltar ao menu...");
        getchar(); // Captura o Enter
        getchar(); // Aguarda o próximo Enter

        system(CLEAR_SCREEN);
    }
    else if (opcao == 7){
        transferencia(&t);
        system(CLEAR_SCREEN);
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
