//PROGRAMA: Digitar 10 números em uma variavel e ordenalos
//NOME: Diogo Pepper
//DATA: 29/09/09

#include<stdlib.h>
#include<stdio.h>
#include<conio.h>

int main(void)
{
   int var[10],i,aux,n,cont,j;
    
    for(i=0;i<10;i++){
        printf("Entre com o numeros %d/10: ",i+1);
        scanf("%d",&var[i]);
    }
       for(j=0;j<10;j++){
            for(i=0;i<9;i++){
                if(var[i]>var[i+1]){
                   aux=var[i+1];
                   var[i+1]=var[i];
                   var[i]=aux;
                   }
            }
       }
        
    printf("A ordem dos n%cmeros %c: ",136,130);
    for(i=0;i<10;i++){
        printf("%d ",var[i]);
        }
        
    getch();
    return 0;
}
