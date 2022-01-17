//PROGRAMA: Calcular a diagonal principas e da diagonal secundaria
//NOME: Diogo Pepper
//DATA: 01/10/2009

#include<stdlib.h>
#include<stdio.h>
#include<conio.h>

int main(void)
{
    int mat[3][3],cont=1,i,j,somap=0,somas=0;
    system("title Calculo diagona principas e secundaria");
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
           printf("Entre com numero: ");
           scanf("%d",&mat[i][j]);
        }
    }
    
    for(i=0;i<3;i++){
        somap+=mat[i][i];
    }
    for(i=0,j=2;i<3;i++,j--){
        somas+=mat[i][j];
    }
    printf("Soma diagonal principal: %d\n",somap);
    printf("Soma diagonal secundaria: %d",somas);
    getch();
    return 0;
}
        
