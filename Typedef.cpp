#include<stdlib.h>
#include<stdio.h>
#include<conio.h>

typedef float real;
typedef int inteiro;
typedef struct{
               int matricula;
               char nome[20];
               float nota;
}aluno;
               
int main(void)
{
    int i;
    aluno al[5];
    
    for(i=0;i<5;i++){
        printf("Entre com a matricula: ");
        scanf("%d",&al[i].matricula);
        fflush(stdin);
        printf("Entre com o nome: ");
        scanf("%s",&al[i].nome);
        printf("Entre com a nota: ");
        scanf("%f",&al[i].nota);
        }
    
    for(i=0;i<5;i++){
        printf("\nMatricula %d",al[i].matricula);
        printf("\nNome %s",al[i].nome);
        printf("\nNota %.2f",al[i].nota);
        }
    getch();
    return 0;
}
