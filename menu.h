/* -------------- declaracao de funcoes -------------- */
void menu_matriz();
void menu_vetor();
void menu();

/* ------------------ funcoes / menu ------------------ */
/* menu de operacoes com matrizes */
void menu_matriz() {
    int op;
    matriz *m1, *m2;

    printf("\t[ MATRIZES ]\n"
           "1. Ler matrizes\n"
           "2. Somar duas matrizes\n"
           "3. Multiplicar duas matrizes\n"
           "4. Calcular a transposta de uma matriz\n"
           "5. Calcular o determinante de uma matriz\n"
           "6. Verificar se a matriz eh simetrica\n"
           "7. Voltar ao menu anterior\n");
    do {
        printf("\nEscolha uma opcao: ");
        scanf(" %d", &op);
        if (op<1 || op>7)
            printf("Opcao invalida.");
        printf("\n");
    } while (op<1 || op>7);

    switch (op) {
        case 1:
            menu_matriz();
            break;
        case 2:
            menu_matriz();
            break;
        case 3:
            menu_matriz();
            break;
        case 4:
            menu_matriz();
            break;
        case 5:
            menu_matriz();
            break;
        case 6:
            menu_matriz();
            break;
        case 7:
            menu();
            break;
    }
}

/* menu de operacoes com vetores */
void menu_vetor() {
    int op, x;
    vetor *v1, *v2;

    printf("\t[ VETORES ]\n"
           "1. Ler vetores\n"
           "2. Somar dois vetores\n"
           "3. Multiplicar um dos vetores por um escalar\n"
           "4. Realizar o produto escalar entre dois vetores\n"
           "5. Voltar ao menu anterior\n");
    do {
        printf("\nEscolha uma opcao: ");
        scanf(" %d", &op);
        if (op<1 || op>5)
            printf("Opcao invalida.");
        printf("\n");
    } while (op<1 || op>5);

    switch (op) {
        case 1:
            receber_vetor();
            menu_vetor();
            break;
        case 2:
            soma_vetor(v1, v2);
            menu_vetor();
            break;
        case 3:
            multiplica_vetor(v1, x);
            menu_vetor();
            break;
        case 4:
            produto_escalar(v1, v2);
            menu_vetor();
            break;
        case 5:
            menu();
            break;
    }
}

/* menu principal */
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
