int transferencia(Clientes *t) {
    char cpfOrigem[12]; // Incluindo espaço para o caractere nulo '\0'
    char senha[7]; // Incluindo espaço para o caractere nulo '\0'
    char cpfDestino[12]; // Incluindo espaço para o caractere nulo '\0'
    float valor;

    printf("Transferência:\n");
    printf("Digite o CPF da conta de origem: ");
    scanf("%s", cpfOrigem);
    clearBuffer();

    printf("Digite a senha da conta de origem: ");
    scanf("%s", senha);
    clearBuffer();

    printf("Digite o CPF da conta de destino: ");
    scanf("%s", cpfDestino);
    clearBuffer();

    printf("Digite o valor da transferência: ");
    scanf("%f", &valor);
    clearBuffer();

    int indexOrigem = -1;
    int indexDestino = -1;

    // Encontrar o índice da conta de origem pelo CPF e verificar a senha
    for (int i = 0; i < t->qtd; i++) {
        if (strcmp(t->contas[i].cpf, cpfOrigem) == 0 && strcmp(t->contas[i].senha, senha) == 0) {
            indexOrigem = i;
            break;
        }
    }

    // Encontrar o índice da conta de destino pelo CPF
    for (int i = 0; i < t->qtd; i++) {
        if (strcmp(t->contas[i].cpf, cpfDestino) == 0) {
            indexDestino = i;
            break;
        }
    }

    if (indexOrigem == -1) {
        printf("Conta de origem não encontrada ou senha incorreta.\n");
    } else if (indexDestino == -1) {
        printf("Conta de destino não encontrada.\n");
    } else if (t->contas[indexOrigem].saldo < valor) {
        printf("Saldo insuficiente para a transferência.\n");
    } else {
        // Realizar a transferência
        t->contas[indexOrigem].saldo -= valor;
        t->contas[indexDestino].saldo += valor;
        printf("Transferência realizada com sucesso.\n");
    }

    return 0;
}
