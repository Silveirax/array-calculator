void menu_matriz() {}
void menu_vetor() {
    int op;

    printf("\t[ VETORES ]\n"
           "1. Adicionar vetor\n"
           "2. Exibir lista de vetores adicionados\n"
           "3. Somar dois vetores\n"
           "4. Somar todos os vetores\n"
           "5. Multiplicar um dos vetores por um escalar\n"
           "6. Realizar o produto escalar entre dois vetores\n"
           "7. Voltar ao menu anterior\n"
           "8. Sair do programa\n");
    do {
        printf("\nEscolha uma opcao: ");
        scanf(" %d", &op);
        if (op<1 || op>8)
            printf("Opcao invalida.\n");
        printf("\n");
    } while (op<1 || op>8);

    switch (op) {
        case 1:
            receber_vetor();
            break;
        case 2:
            exibir_vetores();
            break;
        case 3:
            soma_vetor();
            break;
        case 4:
            somageral_vetor();
            break;
        case 5:
            multiplica_vetor();
            break;
        case 6:
            produto_escalar();
            break;
        case 7:
            menu();
            break;
        case 8:
            exit(1);
    }
}

void menu () {
    int op;

    printf("\t[ MENU ]\n"
           "1. Operacoes com vetores\n"
           "2. Operacoes com matrizes\n"
           "3. Sair do programa\n");
    do {
        printf("\nEscolha uma opcao: ");
        scanf(" %d", &op);
        if (op<1 || op>3)
            printf("Opcao invalida.\n");
        printf("\n");
    } while (op<1 || op>3);

    switch (op) {
        case 1:
            menu_vetor();
            break;
        case 2:
            menu_matriz();
            break;
        case 3:
            exit(1);
    }
}
