//PROGRAMA: Receber o nome e a nota de 10 alunos; Calcular a nota final das 4 notas; Quem foi aprovado; Quem teve a maior nota.
//NOME: Diogo Pepper
//DATA: 07/10/2009

#include<stdlib.h>
#include<stdio.h>
#include<conio.h>

int main(void)
{
    int i,j;
    float nota[10][5]={0};
    char nome[10][50];
    system("title Notas de uma turma");
    system("color 0a");
    for(i=0;i<10;i++){
        printf("Entre com o nome do aluno %d: ",i+1);
        scanf("%s",&nome[i]);
        }
    for(i=0;i<10;i++){
        system("cls");
        for(j=0;j<4;j++){
        fflush(stdin);
        printf("Digite a nota %d de %s: ",j+1,nome[i]);
        scanf("%f",&nota[i][j]);
        nota[i][4]+=nota[i][j];
        }
    }
    for(i=0;i<10;i++){
        printf("\t\t\t|| Notas ||\n\n");
        printf("\n%s: %.2f",nome[i],nota[i][4]);
        if(nota[i]>=70)
           printf(" Aprovado.\n");
        else
           printf(" Reprovado.\n");
    }
    for(j=0;j<10;j++){
        for(i=0;i<=9;i++){
            aux=nota[i+1][4];
            nota[i+1][4]=nota[i][4];
            nota[i][4]=aux;
        }
    }
    printf("\n\n%s teve a maior nota da turma!")
    getch();
    return 0;
}
