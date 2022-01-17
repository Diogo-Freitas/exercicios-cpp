//NOME: Diogo Pepper
//DESCRIÇÃO: Palavras Palíndroma  
//DATA:22/08/09
#include<stdio.h>
#include<conio.h>
#include<string.h>
int main(void)
{
    char str[50];
    int i,j,p=1;
    printf("Digite um nome: : ");
    gets(str);
    j=strlen(str)-1;
    
    for(i=0;i<j;i++,j--){
        if(str[i]!=str[j]){
           p=0;
           break;
           }
        }
        
    if(p==1)
       printf("A palavra %s e um palindromo!\n",str);
    else
       printf("A palavra %s nao e um palíndromo!\n",str);
       
    getch();
    return 0;
}
