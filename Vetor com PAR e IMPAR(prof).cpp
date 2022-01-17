#include<stdio.h>
#include<conio.h>
int main(void)
{
    int num[10],par[10],impar[10];
    int i,cp=0,ci=0;
    for(i=0;i<10;i++){
        printf("ENTRE COM O NUMERO %d: ",i+1);
        scanf("%d",&num[i]);
        if(num[i]%2==0){
                        par[cp]=num[i];             
                        cp++;
                        }
        else{
             impar[ci]=num[i];
             ci++;
             }
    }
        printf("NUMERO PARES: ");
        for(i=0;i<cp;i++){
            printf("%d ",par[i]);
        }
        printf("NUMERO IMPAR: ");
        for(i=0;i<ci;i++){
            printf("%d ",par[i]);
        }
        getch();
        return 0;
}
