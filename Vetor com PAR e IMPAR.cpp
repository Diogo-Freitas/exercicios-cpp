#include<stdio.h>
#include<conio.h>
int main(void)
{
    int num[10],par[10],impar[10],i;
    printf("DIGITE DEZ NUMEROS:\n");
    for(i=0;i<=9;i++){
        scanf("%d",&num[i]);
    }
    for(i=0;i<=9;i++){
        if(num[i]%2==0)
           par[i];
    }
    for(i=0;i<=9;i++){
        if(num[i]%2==1)
           impar[i];
    }
    printf("PAR: ");
    for(i=0;i<=9;i++){
        printf("%d ",par[i]);
    }
    printf("\nIMPAR: ");
    for(i=0;i<=9;i++){
        printf("%d ",impar[i]);
    }
    getch();
    return 0;
}
