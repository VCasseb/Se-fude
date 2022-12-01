#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int valor;
    struct no *proximo;
} No;

typedef struct
{
    No *inicio;
    int tam;
} Lista;

void criar_lista(Lista *lista);
void inserir_ini(Lista *lista,int num);
void somar_lista(Lista lista);
void imprimir(Lista lista);

int main()
{
    int opc,valor;

    Lista lista;
    criar_lista(&lista);

    do
    {
        printf("\n< 1 > --- Inserir_Inicio\n< 2 > --- Imprimir\n< 3 > --- Somar Lista\n< 0 > --- Sair \n");
        scanf("%d",&opc);

        switch(opc)
        {
        case 1:

            printf("Digite o valor ");
            scanf("%d",&valor);
            inserir_ini(&lista,valor);

            break;
        case 2:
            imprimir(lista);
            break;
        case 3:
            somar_lista(lista);
            break;
        default:
            if(opc != 0)
                printf("Opc errada!");
        }
    }
    while(opc != 0);

    return 0;
}

void criar_lista(Lista *lista)
{
    lista->inicio = NULL;
    lista->tam = 0;
}

void inserir_ini(Lista *lista,int num)
{
    No *novo = malloc(sizeof(No));

    if(novo)
    {
        novo->valor = num;
        novo->proximo = lista->inicio;
        lista->inicio = novo;
        lista->tam++;
    }
    else
        printf("Erro ao alocar memoria");
}

void somar_lista(Lista lista)
{

    int soma;

    No *no = lista.inicio;
    printf("\nTamanho: %d\n",lista.tam);
    while(no)
    {
        soma += no->valor;
        no = no->proximo;
    }
    printf("Soma eh: %d\n",soma);
}

void imprimir(Lista lista)
{

    No *no = lista.inicio;
    printf("\nTamanho: %d\n",lista.tam);
    while(no)
    {
        printf("%d\n", no->valor);
        no = no->proximo;
    }
}

