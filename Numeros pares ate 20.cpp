/* Imprimir todos os numeros pares de 0 a 20 */
#include<stdio.h>
#include<conio.h>
int main(void)
{
    int n=0;
    
    while(n<=20){
          if(n%2==0){
            printf("%d ",n);
            }
            n++;
          }
    getch();
    return 0;
}
