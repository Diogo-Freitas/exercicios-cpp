/* Digitar cinco numeros */
#include<stdio.h>
#include<conio.h>
int main(void)
{
    int i,n,soma;
    i=0;
    soma=0;
    
    while(i<5){
         printf("Entre com um numero: ");
         scanf("%d",&n);
         soma+=n;
         i++;
    }
    
    if(soma%2==0)
       printf("O numero %d e PAR.",soma);
       
    else
       printf("O numero %d nao e par!",soma);
       
    getch():
    return 0;
}
