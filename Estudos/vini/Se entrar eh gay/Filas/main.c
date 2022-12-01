#include <stdio.h>
#include <stdlib.h>

//FIFO
typedef struct no{
    int valor;
    struct no *proximo; //No para prox item
}No;

void inserir(No **fila, int num); //funcao de insercao
No* remover(No **fila); //remocao
void imprimir(No *fila); //impressao
void limpar_tela(); //limpar a tela

int main()
{
    int tt,i=0;
    No *r, *fila = NULL; //Declacao do ponteiro No, Remover e Fila

    int opc,valor; //OPC = opc do usuario, valor = valor do usuario, tam = tamanho da lista



    do{
        limpar_tela();
        printf("\n-------------\n1 - Inserir\n2 - Remover\n3 - Imprimir\n0 - Sair\n-------------\n----> ");
        scanf("%d",&opc);

        switch(opc){
        case 1:
            //tam++; //Incrementa tamanho da lista
            printf("Digite um valor: ");
            scanf("%d",&valor); //valor do usuario
            inserir(&fila,valor); //Valor do usuario como parametro para insercao no No
            printf("\nItem inserido: %d\n",valor);
            system("pause"); //Pausar o terminal para uma melhor visualizacao
            break;

        case 2:
            //tam--; //Remocao tamanho caso seja removido algo
            r = remover(&fila); //r recebe remocao da lista

            if(r){
                printf("Removido: %d\n",r->valor); //Printar valor removido
            }
                free(r); //Liberar memoria
            system("pause"); //Pausar o terminal
            break;

        case 3:
            imprimir(fila); //impressao da Fila
            //printf("Tamanho: %d\n\n",tam); //impressao do tamanho da lista

            while(fila){ //While para printar a fila toda
            i++;
        tt += fila->valor; //FAZER SOMA DA LISTA ---------------------------------------------------

        //printf("%d\n",fila->valor); //Printar
        fila = fila->proximo; //Printar Proximo No
    }
            printf("\nTamanho: %d",i); //FAZER TAM DA LISTA ---------------------------------------------------
            printf("\nsoma %d",tt); //FAZER SOMA DA LISTA ---------------------------------------------------
            printf("\nmedia %d\n",tt/i); //FAZER MEDIA DA LISTA ---------------------------------------------------

            system("pause"); //Pausar o terminal
            break;

        default:
            if(opc != 0){
                printf("Opc invalida\n"); //impressao caso opcao errada
                system("pause"); //Pausar terminal
            }
        }
    }while(opc != 0); //0 para sair do While

    return 0;
}

void inserir(No **fila, int num){ //num eh o valor do usario

    No *aux,*novo = malloc(sizeof(No)); //alocar memoria para o ponteiro
    if(novo){ //if para criar um no caso nao tenha
        novo->valor = num; //receber valor do usuario
        novo->proximo = NULL; //Caso seja o primeiro No, apontar NULL para o proximo
        if(*fila == NULL) //Se o No atual for Null, receber valor do usuario para criar uma fila
            *fila = novo;
        else{ //Caso ja exista um No, criar proxima posicao
            aux = *fila;
            while(aux->proximo)
                aux = aux->proximo; //Variavel aux serve para criar o proximo
            aux->proximo = novo;
        }

    }
    else
        printf("Erro ao alocar\n"); //erro caso n consiga alocar memoria


}

No* remover(No **fila){
    No *remover = NULL; //Ponteiro remover tendo NULL

    if(*fila){ //Remover
        remover = *fila;
        *fila = remover->proximo;
    }
    else
        printf("Fila Vazia\n"); //Caso n exista nenhum dado

    return remover; //Retornar remocao
}

void imprimir(No *fila){
    int soma_1,soma_2,tt;
    if(fila == NULL)
        printf("Vazio...\n"); //Caso nao tenha nenhum valor
    else{
    printf("\n\n----- Inicio Fila ----\n\n");
    while(fila){ //While para printar a fila toda

        printf("%d\n",fila->valor); //Printar
        fila = fila->proximo; //Printar Proximo No
    }
    printf("\n---- Fim Fila ----\n\n");
    }
}


void limpar_tela(){
    system("cls"); //Funcao para limpar a tela
}
