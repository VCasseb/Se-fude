#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {

    char nome[25];
    float nota;
    int turma;
} aluno;



int main()
{

    aluno Aluno[5];

    strcpy(Aluno[0].nome, "pinto");
    strcpy(Aluno[1].nome, "eae mano");

    printf("\n%s",Aluno[0].nome);
    printf("\n%s",Aluno[1].nome);


    return 0;
}
