#include <stdio.h>
#include <stdlib.h>


typedef struct NO
{
    int dado;
    struct NO *prox;
} NO;

typedef struct PILHA
{
    NO *topo;
    int tam;
} PILHA;


void inicializaPilha(PILHA *p)
{
    p->topo = NULL;
}

void empilha (int dado, PILHA *p)
{
    NO *ptr = (NO*) malloc(sizeof(NO));
    if(ptr == NULL)
    {
        printf("Erro de alocacao de no.\n");
    }
    else
    {
        ptr->dado = dado;
        ptr->prox = p->topo;
        p->topo = ptr;
        //p->tam++;
    }
}

int desempilha(PILHA *p)
{
    NO* ptr = p->topo;
    int dado;
    if(ptr == NULL)
    {
        printf("Pilha vazia.\n");
    }
    else
    {
        p->topo = ptr->prox;
        ptr->prox = NULL;
        dado = ptr->dado;
        free(ptr);
        return dado;
    }
}

void imprimePilha(PILHA *p)
{
    NO *ptr = p->topo;
    if(ptr == NULL)
    {
        printf("Pilha vazia.\n");
    }
    else
    {
        while(ptr != NULL)
        {
            printf("%d\n",ptr->dado);
            ptr = ptr->prox;
        }
        printf("\n");
    }
    printf("tam %d",p->tam);
}

void contar(){
    int i;
    i++;
}

int main()
{
    int usuario=0,opc=0;
    char sair[2];

    PILHA *p1 = (PILHA*) malloc(sizeof(PILHA));
    if(p1 == NULL)
    {
        printf("Erro.\n");
        exit(0);
    }
    else
    {
        inicializaPilha(p1);

        do
        {
            printf("< 1 > - Empilhar\n");
            printf("< 2 > - Desempilhar\n");
            printf("< 3 > - Imprimir\n---> ");
            scanf("%d",&opc);

            switch(opc){
            case 1:
            printf("Digite um numero: ");
            scanf("%d",&usuario);
            empilha(usuario,p1);
            printf("\n");
            break;

            case 2:
                desempilha(p1);
            break;

            case 3:
                printf("Imprimindo...\n\n");
                imprimePilha(p1);
            break;
            }

           //printf("Digite <s> para sair: ");
          //  getchar();
           // gets(sair);
        }while(sair != 's');
    }

    return 0;
}
