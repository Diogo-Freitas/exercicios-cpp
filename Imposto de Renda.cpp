/*Progrma para calcular o Imposto de renda que a pessoa deve pagar à receita federal*/
#include<stdio.h>
#include<conio.h>
int main(void)
{
    float salario[12],renda=0,inss=0,receita=0,imposto=0;
    int i;
    for(i=0;i<13;i++){
                      printf("DIGITE O %d SALARIO: ",i+1);
                      scanf("%f",&salario[i]);
                      renda+=salario[i];
                      }
    printf("\nRENDA ANUL: R$%.2f",renda);
    printf("\nQUANTO FOI PAGO AO INSS: ");
    scanf("%f",&inss);
    receita=renda-inss;
    if(receita<12000)
            printf("\nINSENTO DO IMPOSTO DE RENDA");
    else if(receita>=12000 && receita<=15000){
            printf("\n10%% DE IMPOSTO DE RENDA\n");
            imposto=(receita/10);
            printf("\nTOTAL IMPOSTA A PAGAR R$%.2f",imposto);}
    else if(receita>15000 && receita<=20000){
            printf("\n15%% DE IMPOSTO DE RENDA\n");
            imposto=(receita/15);
            printf("\nTOTAL IMPOSTO A PAGAR R$%.2f",imposto);}
    else{
             printf("\n27%% DE IMPOSTO DE RENDA\n");
             imposto=(receita/27.5);
             printf("\nTOTAL DE IMPOSTO A PAGAR: %.2f",imposto);}
    getch();
    return 0;
}
