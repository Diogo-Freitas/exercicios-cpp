//PROGRAMA: Função para calcular fatorial e números primo
//NOME: Diogo Pepper
//DATA: 08/10/2009

#include<stdlib.h>
#include<stdio.h>
#include<conio.h>

int pri(int n);
double fat(int n);
int main(void)
{
    int n,f;
    system("title Primo e Fatorial");
    system("color 0A");
    printf("Entre com um valor: ");
    scanf("%d",&n);
    pri(n);
    if(pri(n))
       printf("\nO numero %d e primo!\n\n",n);
    else
       printf("\nO numero %d nao e primo!\n\n",n);
    fat(n);
       printf("O Fatorial de %d e %g",n,fat(n));
       getch();
       return 0;
}


int pri(int n)
{
     int i;   
     for(i=2;i<n;i++){
         if(n%i==0)
            return(0);
     }
     if(n>1)
         return(1);
}

     
double fat(int n)
{
     int i;
     double f=1;
     for(i=1;i<=n;i++){
         f*=i;
         }
     return(f);
}
     
