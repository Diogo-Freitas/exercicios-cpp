/* Multiplicar dois numeros usando a soma */
#include<stdio.h>
#include<conio.h>
int main(void)
{
    int n1,n2,i,mult=0;
    printf("Entra com dois numero: ");
    scanf("%d %d",&n1,&n2);
    i=n1;
    while(i>0){
          mult+=n2;
          i--;
          }
    printf("O resultado e: %d",mult);
    getch();
    return 0;
}
