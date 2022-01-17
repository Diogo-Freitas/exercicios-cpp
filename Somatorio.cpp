/*Somatorio */
#include<stdio.h>
#include<conio.h>

int main(void)
{
    int i,n,soma;
    printf("Digite um numero: ");
    scanf("%d",&n);
    i=2;
    while(i<=n){
               soma+=(i*i)*3;
               i++;
               }
    printf("Resultado: %d",soma);
    getch();
    return 0;
}
