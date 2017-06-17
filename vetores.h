/* ----------------- variaveis globais ----------------- */
typedef struct vetor {
    int *v, elem; // ponteiro para o vetor e numero de elementos do vetor
    struct vetor *prox; // ponteiro auxiliar da lista encadeada
} vetor;

vetor *inicio_v; // ponteiro para o inicio da lista de vetores


/* -------------- declaracao de funcoes -------------- */
int qtd_vetor();
void somageral_vetor (int x);
void produto_escalar (vetor *v1, vetor *v2);
void multiplica_vetor (vetor *v1, int x);
void soma_vetor (vetor *v1, vetor *v2);
void exibir_vetores ();
void adiciona_vetor (vetor* vet);
void receber_vetor ();


/* ------------------ funcoes / vetor ------------------ */

/* retorna o numero de vetores ja adicionados a lista */
int qtd_vetor () {
    vetor *aux;
    aux = inicio_v;
    int qtd = 0;

    while (aux != NULL) {
        qtd++;
        aux = aux->prox;
    }

    return qtd;
}

/* soma todos os vetores de tamanho x */
void somageral_vetor (int x) {
    vetor *aux;
    aux = inicio_v;
    int soma, i, indicador = 0;

    while (aux != NULL) {
        if (aux->elem == x) {
            indicador = 1;
            break;
        }
        aux = aux->prox;
    }

    if (indicador == 1) {
        printf("Vetor da soma geral: ");
        for (i=0; i<x; i++) {
            soma = 0;
            aux = inicio_v;
            while (aux != NULL) {
                if (aux->elem == x)
                    soma += aux->v[i];
                aux = aux->prox;
            }
            printf("%d ", soma);
        }
        printf("\n");
    }
    else
        printf("Nao existem vetores de tamanho %d na lista.\n\n", x);
}

/* calcula o produto escalar entre os vetores v1 e v2 */
void produto_escalar (vetor *v1, vetor *v2) {
    int soma = 0;

    if (v1->elem != v2->elem)
        printf("Produto escalar impossivel. Vetores de tamanhos diferentes.\n");
    else {
        int i;
        for (i=0; i<v1->elem; i++)
            soma += v1->v[i]*v2->v[i];
        printf("Produto escalar: %d\n", soma);
    }
}

/* multiplica o vetor v1 pelo escalar x */
void multiplica_vetor (vetor *v1, int x) {
    int i;

    printf("Vetor multiplicado pelo escalar %d: ", x);
    for (i=0; i<v1->elem; i++)
        printf("%d ", x*v1->v[i]);
    printf("\n");
}

/* soma os vetores v1 e v2 e apresenta na tela */
void soma_vetor (vetor *v1, vetor *v2) {
    int i;

    printf("Vetor soma: ");
    if (v1->elem > v2->elem) {
        for (i=0; i<v2->elem; i++)
            printf("%d ", v1->v[i]+v2->v[i]);
        for (i=v2->elem; i<v1->elem; i++)
            printf("%d ", v1->v[i]);
    }
    else {
        for (i=0; i<v1->elem; i++)
            printf("%d ", v1->v[i]+v2->v[i]);
        for (i=v1->elem; i<v2->elem; i++)
            printf("%d ", v2->v[i]);
    }
    printf("\n");
}

/* printa todos os vetores adicionados ate o momento */
void exibir_vetores () {
    vetor *aux;
    aux = inicio_v;

    if (aux == NULL)
        printf("Nenhum vetor adicionado na lista.\n\n");
    else {
        int num = 1, i;
        while (aux != NULL) {
            printf("Vetor %d: ", num++);
            for (i=0; i<aux->elem; i++)
                printf("%d ", aux->v[i]);
            printf("\n");
            aux = aux->prox;
        }
        printf("\n");
    }
}

/* adiciona o vetor lido na lista */
void adiciona_vetor (vetor* vet) {

    if (inicio_v == NULL) {
        inicio_v = vet;
        vet->prox = NULL;
    }
    else {
        vetor *aux;
        aux = inicio_v;

        while (aux->prox != NULL)
            aux = aux->prox;

        aux->prox = vet;
        vet->prox = NULL;
    }
}

/* recebe o tamanho e elementos do vetor */
void receber_vetor () {
    vetor *aux;
    aux = (vetor*)malloc(sizeof(vetor));
    int i;

    printf(">> Adicionar vetor\n"
           "Digite o numero de elementos do vetor: ");
    scanf(" %d", &aux->elem);

    aux->v = (int*)malloc(aux->elem*sizeof(int));
    printf("\nDigite os valores das posicoes do vetor:\n\n");
    for (i=0; i<aux->elem; i++) {
        printf("v[%d] = ", i);
        scanf(" %d", &aux->v[i]);
    }
    printf("\nVetor adicionado a lista com sucesso!\n\n");

    adiciona_vetor(aux);
}
