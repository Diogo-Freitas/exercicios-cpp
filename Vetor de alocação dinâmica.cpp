// PROGRAMA: Armazenar uma determinada quantidade números num vetor dinamico e imprimir na tela.
// NOME: Diogo Pepper
// DATA: 22/10/2009

#include<stdlib.h>
#include<stdio.h>
#include<conio.h>

int main(void)
{
    int i,n;
    float *v;
    printf("Digite quantos numeros deseja armazenar: ");
    scanf("%d",&n);
    
    v=(float*)malloc(n*sizeof(float));
    if(v==NULL){
       printf("Memoria insuficiente.");
       return 1;}
    
    for(i=0;i<n;i++){
        printf("Entre com o numero %d/%d: ",i+1,n);
        scanf("%f",&v[i]);
    }
    
    for(i=0;i<n;i++){
        printf("Vetor %d: %.0f\n",i,v[i]);
        }
    free(v);
    getch();
    return 0;
}
