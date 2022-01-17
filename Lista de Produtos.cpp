#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct{
        int codigo;
        char nome[50];
        float valor;
}produto;

int main(void)
{
    produto *vet;
    int i,n,maior=0,menor=0;
    printf("Quantos Produtos? ");
    scanf("%d",&n);
    vet=(produto*)malloc(n*sizeof(produto));
    
    for(i=0;i<n;i++){
        printf("Entre com o codigo do produto: ");
        scanf("%d",&vet[i].codigo);
    }
    
    for(i=i;i<n;i++){
        if(vet[maior].valor<vet[i].valor)
           maior=i;
        else if(vet[menor].valor>vet[i].valor)
           menor=i;
    }
    
    printf("O produto mais caro e %s %.2f",vet[maior].nome,vet[maior].valor);
    printf("\nO produto mais barato e: %s %.2f",vet[menor].nome,vet[menor].valor);
    free(vet);
    getch();
    return 0;
}
