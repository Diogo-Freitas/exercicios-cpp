/*Progrma para saber quatos caracteres tem o seu nome */
#include<stdio.h>
#include<conio.h>
int main(void)
{
    char nome[50];
    int i;
    printf("DIGITE O SUE NOME: ");
    scanf("%s",&nome);
    i=0;
    while(nome[i]!='\0'){
                         i++;
                         }
    printf("SEU NOME TEM %d CARACTERES.",i);
    getch();
    return 0;
}
