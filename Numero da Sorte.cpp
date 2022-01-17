//PROGRAMA: Tentar acertar o número que o computador gerol com dicas
//NOME: Diogo Pepper
//DATA: 30/09/2009

#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<windows.h>
#include<string.h>

int main(void)
{
    int num,cpu,cont=0,i;
    srand(time(NULL));
    cpu=rand()%100;
    cpu++;
    do{
       printf("\t   // Jogo da Sorte  \\\\   \n");
       printf("********************************************");
       printf("\nEntre com um numeros entre 1 %c 100: ",130);
       scanf("%d",&num);
       for(i=0;i<80;i++){
       printf("%c",'\xdb');}
       
       if(num<cpu){
          printf("Digite um numero maior.\n\a");
          getch();
          system("cls");
          cont++;
          }
       else if(num>cpu){
          printf("Digite um numero menor.\n\a");
          getch();
          system("cls");
          cont++;
          }
       else{
          printf("Voce acertou o numero!\n");
          cont++;
          }
       }while(cpu!=num);
       printf("Com %d tentativas",cont);
       getch();
       return 0;
}
