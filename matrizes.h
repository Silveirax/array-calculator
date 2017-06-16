/* ----------------- variaveis globais ----------------- */
typedef struct matriz {
    int **m, lin, col; // ponteiro para a matriz e numero de linhas e colunas da matriz
    struct matriz *prox; // ponteiro auxiliar da lista encadeada
} matriz;

matriz *inicio_m; // ponteiro para o inicio da lista de matrizes

/* ----------------- funcoes / matriz ----------------- */
/* soma as matrizes m1 e m2 */
void soma_matriz (matriz* m1, matriz* m2) {

    if (m1->lin != m2->lin || m1->col != m2->col)
        printf("Soma impossivel. As matrizes precisam ter o mesmo tamanho.\n");
    else {
        int i, j;
        printf("Matriz soma:\n");
        for (i=0; i<m1->lin; i++) {
            for (j=0; j<m1->col; j++) {
                printf("%d ", m1->m[i][j]+m2->m[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
}

/* printa todas as matrizes adicionadas ate o momento */
void exibir_matrizes () {
    matriz *aux;
    aux = inicio_m;

    if (aux == NULL)
        printf("Nenhuma matriz adicionada na lista.\n\n");
    else {
        int num = 1, i, j;
        while (aux != NULL) {
            printf("Matriz %d - %dx%d:\n", num++, aux->lin, aux->col);
            for (i=0; i<aux->lin; i++) {
                for (j=0; j<aux->col; j++)
                    printf("%d ", aux->m[i][j]);
                printf("\n");
            }
            aux = aux->prox;
            printf("\n");
        }
    }
}

/* adiciona a matriz lida na lista */
void adiciona_matriz (matriz* mat) {

    if (inicio_m == NULL) {
        inicio_m = mat;
        mat->prox = NULL;
    }
    else {
        matriz *aux;
        aux = inicio_m;

        while (aux->prox != NULL)
            aux = aux->prox;

        aux->prox = mat;
        mat->prox = NULL;
    }
}

/* recebe numero de linhas e colunas e elementos da matriz */
void receber_matriz () {
    matriz *aux;
    aux = (matriz*)malloc(sizeof(matriz));
    int i, j;

    printf("Digite o numero de linhas da matriz: ");
    scanf(" %d", &aux->lin);
    printf("Digite o numero de colunas da matriz: ");
    scanf(" %d", &aux->col);

    aux->m = (int**)malloc(aux->lin*sizeof(int));
    for (i=0; i<aux->lin; i++)
        aux->m[i] = (int*)malloc(aux->col*sizeof(int));

    printf("\nDigite os valores das posicoes da matriz:\n");
    for (i=0; i<aux->lin; i++) {
        for (j=0; j<aux->col; j++) {
            printf("m[%d][%d] = ", i, j);
            scanf(" %d", &aux->m[i][j]);
        }
    }
    printf("\n");

    adiciona_matriz(aux);
}
