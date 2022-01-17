//PROGEAMA: Preencher uma matriz 3x3 Transposta
//NOME: Diogo Pepper
//DATA: 01/10/2009

#include<stdlib.h>
#include<stdio.h>
#include<conio.h>

int main(void)
{
    int mat[3][3],cont=1,i,j;
    system("title Matriz 3x3");
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            printf("Entre com um numero: ");
            scanf("%d",&mat[i][j]);   
        }
    }   
        for(j=0;j<3;j++){
            for(i=0;i<3;i++){
                printf("%d\t",mat[i][j]);
            }
        printf("\n\n\n");
    }
    getch();
    return 0;
}
