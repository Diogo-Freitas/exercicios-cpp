#include<stdio.h>
#include<conio.h>
int main(void)
{
    int x[5],a,i,v;
    printf("DIGITE DEZ NUMEROS: ");
    for(i=0;i<=4;i++){
    scanf("%d",&x[i]);
    }
    for(i=0;i<=4;i++){
    printf("Vetor %d= %d\n",i,x[i]);
    }
    getch();
    return 0;
}
    
