#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *proximo;
}No;

typedef struct{
    No *inicio;
    int tam;
}Lista;

void criar_lista(Lista *lista){

    lista->inicio = NULL;
    lista->tam = 0;
}

void inserir_ini(Lista *lista,int num){
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        novo->proximo = lista->inicio;
        lista->inicio = novo;
        lista->tam++;
    }
    else
        printf("Erro ao alocar memoria");
}

void inserir_fim(Lista*lista,int num){
    No *aux, *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        novo->proximo = NULL;

        //primeiro?
        if(lista->inicio == NULL)
            lista->inicio = novo;
        else{
            aux = lista->inicio;
            while(aux->proximo)
                aux = aux->proximo;
            aux->proximo=novo;
        }
        lista->tam++;
    }
    else
        printf("Erro ao alocar memoria");
}

void inserir_meio(Lista *lista, int num, int ant){
    No *aux, *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        if(lista->inicio == NULL){
            novo->proximo = NULL;
            lista->inicio = novo;
        }
        else{
             aux = lista->inicio;
             while(aux->valor != ant && aux->proximo)
                aux = aux->proximo;
            novo->proximo = aux->proximo;
            aux->proximo = novo;
        }
        lista->tam++;
    }
    else
        printf("Erro ao alocar memoria");
}

void inserir_ordenado(Lista *lista, int num){
    No *aux, *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        if(lista->inicio == NULL){
            novo->proximo == NULL;
            lista->inicio = novo;
        }
        else if(novo->valor < lista->inicio->valor){
            novo->proximo = lista->inicio;
            lista->inicio = novo;
        }
        else{
            aux = lista->inicio;
            while(aux->proximo && novo->valor > aux->proximo->valor)
                aux = aux->proximo;
                novo->proximo = aux->proximo;
                aux->proximo = novo;

        }
        lista->tam++;
    }
    else
        printf("Erro ao alocar memoria");
}

No *remover(Lista *lista, int num){
    No *aux,*remover = NULL;

    if(lista->inicio){
        if(lista->inicio->valor == num){
            remover = lista->inicio;
            lista->inicio = remover->proximo;
            lista->tam--;
        }
        else{
            aux = lista->inicio;
            while(aux->proximo && aux->proximo->valor != num)
                aux = aux->proximo;
            if(aux->proximo){
                remover = aux->proximo;
                aux->proximo = remover->proximo;
                lista->tam--;
            }
        }
    }


    return remover;
}

No* buscar(Lista *lista, int num){
    No *aux, *no = NULL;

    aux = lista->inicio;
    while(aux && aux->valor != num)
        aux = aux->proximo;
    if(aux)
        no = aux;
    return no;
}

void imprimir(Lista lista){
    No *no = lista.inicio;
    printf("\nLista Tam %d\n",lista.tam);
    while(no){
        printf("%d ", no->valor);
        no = no->proximo;
    }
    printf("\n\n");

}

int main()
{


    int opc,valor,ant;

    //No *lista = NULL;
    Lista lista;

    No *removido;

    criar_lista(&lista);

    do{
        printf("\n0 - Sair\n1 - Inserir_I\n2 - Inserir_F\n3 - Inserir_M\n4 - Inserir_Ordenado\n5 - Excluir\n6 - Imprimir\n7 - Procurar\n");
        scanf("%d",&opc);

        switch(opc){

    case 1:

        printf("Digite o valor ");
        scanf("%d",&valor);
        inserir_ini(&lista,valor);

        break;

    case 2:

        printf("Digite o valor ");
        scanf("%d",&valor);
        inserir_fim(&lista,valor);

        break;

    case 3:

        printf("Digite o valor e a referencia ");
        scanf("%d %d",&valor, &ant);
        inserir_meio(&lista,valor,ant);

        break;

    case 4:
        printf("Digite o valor");
        scanf("%d",&valor);
        inserir_ordenado(&lista, valor);
        break;

    case 5:
        printf("Digite o valor");
        scanf("%d",&valor);
        removido = remover(&lista,valor);
        if(removido){
            printf("Elemento Removido %d",removido->valor);
            free(removido);
        }
        else
            printf("Item n existe");
        break;

    case 6:
        imprimir(lista);
        break;

    case 7:
        printf("Digite o valor");
        scanf("%d",&valor);
        removido = buscar(&lista,valor);
        if(removido)
            printf("Valor encontrado: %d",removido->valor);
        else
            printf("Nao encontrado");
        break;

    default:
        if(opc != 0)
            printf("Opc errada!");

        }

    }while(opc != 0);

    return 0;
}
