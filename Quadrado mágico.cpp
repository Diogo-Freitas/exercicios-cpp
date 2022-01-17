//PROGRAMA: Quadrado mágico
//NOME: Diogo Pepper
//DATA: 07/10/2009

#include<stdlib.h>
#include<stdio.h>
#include<conio.h>

int main(void)
{
    int mat[4][4],i,j,ds=0;
    
    for(i=0;i<3;i++){
        mat[i][3]=0;
        mat[3][i]=0;
        for(j=0;j<3;j++){
            mat[i][3]+=mat[i][j];
            mat[3][i]+=mat[j][i];
        }
    }
    mat[3][3]=0;
    
    for(i=0,j=2;i<3;i++,j--){
        mat[3][3]+=mat[i][i];
        ds+=mat[i][j];
    }
    
    if(ds==mat[0][3] && ds==mat[1][3] && ds==mat[2][3] && ds==mat[3][3] && ds==mat[3][0] && ds==mat[3][1] && ds==mat[3][2]){
       printf("A matriz %c um quadrado magico!",130);
       }
       getch();
       return 0;
}
