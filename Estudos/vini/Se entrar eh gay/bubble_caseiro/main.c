#include <stdio.h>
#include <stdlib.h>

int main()
{
    int valores[10],i,j,aux,maior=0,menor=0;

    for(i=0; i<10; i++)
    {

        printf("Digite");
        scanf("%d",&valores[i]);
    }

    //BUBBLE SORT
    for(j=0; j<10; j++)
    {
        for(i=0; i<10; i++)
        {
            if(valores[i]>valores[i+1])
            {
                aux = valores[i];
                valores[i]=valores[i+1];
                valores[i+1]=aux;
            }
        }
    }

                menor = valores[0];
                maior = valores[9];

    printf("\nMaior: %d\n", maior);

    printf("\nMenor: %d\n", menor);


    for(i=0; i<10; i++)
    {

        printf("\n%d",valores[i]);

    }

    return 0;
}
