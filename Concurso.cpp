//SOFTWARE PARA EFETURAR O CADASTRO DE CANDIDATOS E FUTURA CORRE��O DAS PROVAS DOS CONCUROS.
//TRABALHO DE ALGORITMO E ESTRUTURA DE DADOS II.
//UNIVERSIDADE ESTADUAL DE MONTES CLAROS
//NOME: DIOGO FREITAS 

#include <sys/time.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#define TRUE  1
#define FALSE 0
#define max 10
#define G  5       /* QUANTIDADE DE QUESTOES DO GABARITO */
#define M  10098         /* TAMANHO DA TABELAHASH */
#define n  50          /* QUANTIDADE DE CARACTERES */

/* ================  ESTRUTURA HASH ================= */
typedef char TipoChaveHash[n];

typedef unsigned int  TipoPesos[n];

typedef struct TipoItem {
        TipoChaveHash Chave;
        char Nome[50];
        char Concurso[50];
        char Gabarito[G];
        int Pontos;
} TipoItem;

typedef unsigned int Indice;

typedef struct CelulaHash* Aponta;

typedef struct CelulaHash {
  TipoItem Item;
  Aponta Prox;
} CelulaHash;

typedef struct TipoListaHash {
  CelulaHash *Primeiro, *Ultimo;
} TipoListaHash;

typedef TipoListaHash TipoDicionario[M];

/* ========== ESTRUTURA DA ARVORE SBB ============= */
typedef int TipoChave;

typedef struct Registro{
        TipoChave Chave;
        char Nome[50];
        char Concurso[50];
        char Gabarito[G];
        int Pontos;
}Registro;

typedef enum{
        Vertical, Horizontal
}Inclinacao;

typedef struct No* Apont;

typedef struct No{
        Registro Reg;
        Apont Esq, Dir;
        Inclinacao BitE, BitD;
}No;

/* ========== ESTRUTURA DO CONCURSO ================ */
typedef struct{
    char Promotor[50];
    char Concurso[50];
    int Vagas;
    char Data[11];
    char Gabarito[G];
    int Status;
}Cotec;

typedef struct{
    int Inscricao;
    char Nome[50];
    char Concurso[50];
    char Gabarito[G];
    int Pontos;
}Candidato;

typedef struct celula *Apontador;

typedef struct celula{
    Candidato Item;
    Apontador Prox;
    Apontador Ant;
    int Indice;
}Celula;

typedef struct{
    Apontador Primeiro;
    Apontador Ultimo;
}TipoLista;

typedef struct{
    Apontador Inicio;
    Apontador Fim;
}TipoFila;

/* =============================================================================================== */
int Gera_Nota(char *Candidato ,char *oficial);
void Copia_Lista_Fila(TipoLista Lista, TipoFila *Fila);
void SalvaFila(TipoFila Fila,int vagas);
/* ======================== FUNCOES DE ORDENACAO ================================================= */
void Particao(int esq, int dir, int *i, int *j, TipoLista *Lista);
void Ordena(int esq, int dir, TipoLista *Lista);
void Quicksort(TipoLista *Lista,int ind_ultimo);
/* =============================================================================================== */
/* ======================== FUNCOES DE LISTA ===================================================== */
void IniciarLista(TipoLista *Lista);
int TesteListaVazia(TipoLista Lista);
void Insere(TipoLista *Lista, Candidato X,int pos_def_main, char *oficial);
void Imprime(TipoLista Lista);
/* =============================================================================================== */
/* ======================== FUNCOES DE FILA ====================================================== */
void ImprimeFila(TipoFila Fila,int vagas);
void TirarDaFila(TipoFila *Fila, Candidato *X, TipoLista *lista);
void InsereFila(Candidato X, TipoFila *Fila);
int FilaVazia(TipoFila Fila);
void IniciarFila(TipoFila *Fila);
/* ============================ ARVORE SBB ====================================================== */
void EE(Apont *Ap);
void ED(Apont *Ap);
void DE(Apont *Ap);
void DD(Apont *Ap);
void IInsereSBB(Registro x, Apont *Ap, Inclinacao *IAp, short *Fim);
void InsereSBB(Registro x, Apont *Ap);
void Cria_Vetor_Numero(int *v);
void Inicializa(Apont *Dicionario);
void EsqCurto(Apont *Ap, short *Fim);
void DirCurto(Apont *Ap, short *Fim);
void Antecessor(Apont q, Apont *r, short *Fim);
void Pesquisa(Registro *x, Apont *p);
void PesquisaNome(Registro *x, Apont *p);
/* =========================== ESTRUTURA HASH =================================================== */
void FLVazia(TipoListaHash *Lista);
short Vazia(TipoListaHash Lista);
void Ins(TipoItem x, TipoListaHash *Lista);
void Inicializa(TipoDicionario T);
void InsereHashHash(TipoItem x, TipoPesos p, TipoDicionario T);
void Imp(TipoListaHash Lista);
void Imprime(TipoDicionario Tabela);
void LerPalavra(char *p, int Tam);
void GeraPesos(TipoPesos p);
Indice h(TipoChaveHash Chave, TipoPesos p);
Aponta Pesquisa(TipoChaveHash Ch, TipoPesos p, TipoDicionario T);
Aponta PesquisaNomeHash(TipoChaveHash Ch, TipoPesos p, TipoDicionario T);
TipoDicionario Tabela;
TipoItem Elemento;
TipoPesos p;
Aponta T;
FILE *arq;
/* =============================================================================================== */

int main(void)
{
    FILE *arq;
    int op,opb,i,j,pos=0,pts=0,vagas,num,sbb;
    char temp[50],tmp[50];
    int* v;

    clock_t end,start;

    /* ESTRUTURA DO PROGRAMA */
    Cotec Reg;
    Candidato Ins;
    /* ===== LISTA ========= */
    TipoLista Lista;
    IniciarLista(&Lista);
    /* ===== FILA ========== */
    TipoFila Fila;
    IniciarFila(&Fila);
    /* ===== HASH ========== */
    TipoItem Hash;
    Inicializa(Tabela);

    Registro x;
    GeraPesos(p);
    Reg.Status=0;
    Ins.Inscricao=0;
    Apont  Dicionario;
    Inicializa(&Dicionario);

    v = (int*) malloc(pos * sizeof(int));
    system("title Sistema de Gerenciamento de Concurso");

    /*========== Carregar Concurso =============== */
    arq=fopen("Concurso.txt","r");
    fgets(Reg.Promotor, sizeof(Reg.Promotor), arq);
    fgets(Reg.Concurso, sizeof(Reg.Concurso), arq);
    fgets(temp, sizeof(temp), arq);
    Reg.Vagas=atoi(temp);
    fgets(Reg.Data, sizeof(Reg.Data), arq);
    fclose(arq);
    /* ======== Carregar Gabarito ================= */
    arq=fopen("Gabarito.txt","r");
    for(i=0;i<G;i++)
         Reg.Gabarito[i]=fgetc(arq);
    fclose(arq);
    /* ======== Carregar Candidatos ===============*/
     arq=fopen("Candidatos.txt","r");
     i=0;
     while(fscanf(arq,"%s",temp)!=EOF){
          if(i%5==0){
               x.Chave=Ins.Inscricao=atoi(temp);
               strcpy (Hash.Chave,temp);}
          else if(i%5==1){
               strcpy (Ins.Nome,temp);
               strcpy (x.Nome,temp);
               strcpy (Hash.Nome,temp);}
          else if(i%5==2){
               strcpy (Ins.Concurso,temp);
               strcpy (x.Concurso,temp);
               strcpy (Hash.Concurso,temp);}
          else if(i%5==3){
               strcpy (Ins.Gabarito,temp);
               strcpy (x.Gabarito,temp);
               strcpy (Hash.Gabarito,temp);}
          else if(i%5==4)
               Hash.Pontos=x.Pontos=Ins.Pontos=atoi(temp);
          if(i%5==4){
               Insere(&Lista,Ins,pos,Reg.Gabarito);
               InsereSBB(x, &Dicionario);
               InsereHashHash(Hash, p, Tabela);
               pos++;
          }
          i++;
     }
     fclose(arq);

/* ======================== MENU PRINCIPAL DO PROGRAMA ========================================= */

    do{
             system("cls");
             printf("-------------------------------------------------------------\n");
             printf("|           Sistema de Gerenciamento de Concurso             |\n");
             printf("-------------------------------------------------------------\n\n");
             printf("\n 1 - Cadastrar Concurso\n");
             printf("\n 2 - Visualizar Concurso\n");
             printf("\n 3 - Modificar Gabarito\n");
             printf("\n 4 - Visualizar Gabarito\n");
             printf("\n 5 - Cadastrar Candidato\n");
             printf("\n 6 - Candidatos Cadastrados\n");
             printf("\n 7 - Gerar Lista de Aprovados\n");
             printf("\n 8 - Metodo de Pesquisa\n");
             printf("\n 9 - Sair\n\n");
             printf("\n Opcao: ");
             scanf("%d",&op);

        switch(op){
            case 1:
                    system("cls");
                    printf("-------------------------------------------------------------\n");
                    printf("|               Novo Cadastro de Concurso                     |\n");
                    printf("-------------------------------------------------------------\n");
                    /* PEGA OS DADOS DO NOVO CONCURSO E ARMAZENA */
                    arq=fopen("Concurso.txt","w");
                    printf("\nNome do Promotor: ");fflush(stdin);
                    gets(Reg.Promotor);
                    printf("\nNome do Concurso: ");fflush(stdin);
                    gets(Reg.Concurso);
                    printf("\nNumero de Vagas : ");fflush(stdin);
                    scanf("%d", &Reg.Vagas);
                    printf("\nData(dd/mm/aaaa): " );fflush(stdin);
                    gets(Reg.Data);
                    fprintf(arq,"%s\n%s\n%d\n%s",Reg.Promotor,Reg.Concurso,Reg.Vagas,Reg.Data);
                    fclose(arq);
                    /* PEGA OS DADOS DO GABARITO DO CONVURSO E ARMAZENA */
                    arq=fopen("Gabarito.txt","w");
                    printf("\n\n|--Gabarito--| \n\n");
                    for(i=0;i<G;i++){
                        fflush(stdin);
                        printf(" Questao %d: ",i+1);
                        scanf("%c",&Reg.Gabarito[i]);
                        fputc(Reg.Gabarito[i],arq);
                    }
                    fclose(arq);

                    printf("\n|------------| \n\n");
                    printf("\n\t\tNovo Gabarito Registrado!");
                    getch();

                    break;

            case 2:
                    system("cls");
                    printf("-------------------------------------------------------------\n");
                    printf("|                      Visualizacao                         |\n");
                    printf("-------------------------------------------------------------\n");
                    /* PEGA OS DADOS DO CONCURSO ARMAZENADOS NO ARQUIVO E CARREGA */
                    arq=fopen("Concurso.txt","r");
                    fgets(Reg.Promotor, sizeof(Reg.Promotor), arq);
                    printf("\n\nNome do Promotor: %s\n", Reg.Promotor);
                    fgets(Reg.Concurso, sizeof(Reg.Concurso), arq);
                    printf("\nNome do Concurso: %s\n", Reg.Concurso);
                    fgets(temp, sizeof(temp), arq);
                    Reg.Vagas=atoi(temp);
                    printf("\nNumero de Vagas: %d\n", Reg.Vagas);
                    fgets(Reg.Data, sizeof(Reg.Data), arq);
                    printf("\n\nData: %s\n", Reg.Data);
                    fclose(arq);
                    getch();
                    break;

            case 3:
                    system("cls");
                    printf("-------------------------------------------------------------\n");
                    printf("|                Inserir Gabarito Oficial                   |\n");
                    printf("-------------------------------------------------------------\n");
                    /* PEGA OS DADOS DO NOVO GABARITO E ARMAZENA */
                    arq=fopen("Gabarito.txt","w");
                    printf("\n|--Gabarito--| \n\n");
                    for(i=0;i<G;i++){
                        fflush(stdin);
                        printf(" Questao %d: ",i+1);
                        scanf("%c",&Reg.Gabarito[i]);
                        fputc(Reg.Gabarito[i],arq);
                    }
                    fclose(arq);
                    printf("\n|------------| \n\n");
                    printf("\n\t\tNovo Gabarito Registrado!");
                    getch();
                    break;

            case 4:
                    system("cls");
                    printf("-------------------------------------------------------------\n");
                    printf("|                    Gabarito Oficial                       |\n");
                    printf("-------------------------------------------------------------\n");
                    /* PEGA OS DADOS DO GABARITO OFICIAL NO ARQUIVO E CARREGA */
                    arq=fopen("Gabarito.txt","r");
                    printf("\n|--Gabarito--| \n");
                    for(i=0;i<G;i++){
                        fflush(stdin);
                        Reg.Gabarito[i]=fgetc(arq);
                        printf("\n Questao %d: %c",i+1,Reg.Gabarito[i]);
                    }
                    printf("\n\n|------------| \n\n");
                    fclose(arq);
                    getch();
                    break;

            case 5:
                    system("cls");
                    Ins.Inscricao=pos+1;
                    printf("-------------------------------------------------------------\n");
                    printf("|                     Novo Candidato                        |\n");
                    printf("-------------------------------------------------------------\n");
                    /* PEGA OS DADOS DO NOVO CANDIDATO DO CONCURSO E ARMAZENA */
                    arq=fopen("Candidatos.txt","a");
                    printf("\nNumero da Inscricao: %d\n", Ins.Inscricao);
                    x.Chave=Ins.Inscricao;
                    itoa(Ins.Inscricao,Hash.Chave,10); //Transformar Inteiro em Char
                    printf("\nNome: ");fflush(stdin);
                    gets(Ins.Nome);
                    strcpy (x.Nome,Ins.Nome);
                    strcpy (Hash.Nome,Ins.Nome);
                    printf("\nConcurso: ");fflush(stdin);
                    gets(Ins.Concurso);
                    strcpy (x.Concurso,Ins.Concurso);
                    strcpy (Hash.Concurso,Ins.Concurso);
                    printf("\n|--Gabarito--| \n\n");
                    for(i=0;i<G;i++){
                        fflush(stdin);
                        printf(" Questao %d: ",i+1);
                        scanf("%c",&Ins.Gabarito[i]);
                    }
                    printf("\n|------------| \n\n");
                    Ins.Pontos=Gera_Nota(Ins.Gabarito,Reg.Gabarito);
                    strcpy (x.Gabarito,Reg.Gabarito);
                    strcpy (Hash.Gabarito,Reg.Gabarito);
                    x.Pontos=Ins.Pontos;
                    Hash.Pontos=Ins.Pontos;
                    /* SALVA OS DADOS NO ARQUIVO */
                    fprintf(arq,"%d\n%s\n%s\n%s\n%d\n\n",Ins.Inscricao,Ins.Nome,Ins.Concurso,Ins.Gabarito,Ins.Pontos);
                    /* INSERE OS DADOS NA LISTA */
                    Insere(&Lista,Ins,pos,Reg.Gabarito);
                    /* INSERE OS DADOS NA ARVORE SBB */
                    InsereSBB(x, &Dicionario);
                    /* INSERE OS DADOS NO HASH */
                    InsereHashHash(Hash, p, Tabela);
                    pos++;
                    printf("\n\n\tCadastro realizado com sucesso.");
                    fclose(arq);
                    getch();
                    break;

            case 6:
                    system("cls");
                    /* EXIBE OS CANDIDATOS CADASTRADOS NA LISTA */
                    Imprime(Lista);
                    getch();
                    break;

            case 7:
                    system("cls");
                    printf("-------------------------------------------------------------\n");
                    printf("|                   Lista de Aprovados                      |\n");
                    printf("-------------------------------------------------------------\n");
                    /* VERIFICA SE TEM CANDIDATOS CADASTRADOS NA LISTA */
                    if(TesteListaVazia(Lista)==1){
                        printf("Nenhum Candidato Cadastrado!\n");
                        getch();
                        break;
                    }
                    /* ORDENA A LISTA PELO QUICKSORT */
                    Quicksort(&Lista,pos-1);
                    IniciarFila(&Fila);
                    /* COPIA A LISTA ORDENA PARA A FILA */
                    Copia_Lista_Fila(Lista,&Fila);
                    vagas=Reg.Vagas;
                    /* MOSTRA A LISTA DE APROVADOS DE ACORDO COM O CONCURSO */
                    ImprimeFila(Fila,vagas);
                    /* SALVA OS DADOS NO ARQUIVO */
                    SalvaFila(Fila,vagas);
                    getch();
                    break;

            case 8:
                    do{
                       system("cls");
                       printf("-------------------------------------------------------------\n");
                       printf("|                     Tipo de Busca                         |\n");
                       printf("-------------------------------------------------------------\n\n");
                       printf(" 1 - Pesquisar Numero de Inscricao (SBB)\n\n");
                       printf(" 2 - Pesquisar Nome de Candidato (SBB)\n\n");
                       printf(" 3 - Pesquisar Numero de Inscricao (Hash)\n\n");
                       printf(" 4 - Pesquisar Nome de Candidato (Hash)\n\n");
                       //printf(" 5 - Tabela Hash\n\n");
                       printf(" 5 - Sair\n\n");
                       printf(" Opcao: ");
                       scanf("%d",&opb);

                       switch(opb){
                                   case 1:/* PESQUISA O CADASTRO ARMAZENADO NA ARVORE SBB PELA INSCRI��O */
                                        printf("\n Entre com o numero da Inscricao: ");
                                        scanf("%d",&num);
                                        start = clock();
                                        x.Chave=num;
                                        Pesquisa(&x, &Dicionario);
                                        end = clock();
                                        printf("\n  Tempo gasto: %4.0f ms",1000*(double)(end-start)/(double)(CLOCKS_PER_SEC));
                                        printf("\n|----------------------------------|");
                                        getch();
                                        break;

                                   case 2:/* PESQUISA O CADASTRO ARMAZENDA NA ARVORE SBB PELO NOME */
                                        printf("\n Entre com o nome do Candidato: ");
                                        scanf("%s",&temp);
                                        start = clock();
                                        strcpy (x.Nome,temp);
                                        PesquisaNome(&x, &Dicionario);
                                        end = clock();
                                        printf("\n  Tempo gasto: %4.0f ms",1000*(double)(end-start)/(double)(CLOCKS_PER_SEC));
                                        printf("\n|----------------------------------|");
                                        getch();
                                        break;

                                   case 3:/* PESQUISA O CADASTRO ARMAZENADO NA ESTRUTURA HASH PELA INSCRI��O */
                                        printf("\n Entre com o numero de inscricao: ");
                                        LerPalavra(Elemento.Chave,n);
                                        start = clock();
                                        T = Pesquisa(Elemento.Chave, p, Tabela);
                                        end = clock();
                                        if (T == NULL){
                                             printf("\n|--------- Tabela Hash ------------|\n");
                                             printf("              ERRO                    \n");
                                             printf("       Registro nao esta              \n");
                                             printf("       presente na tabela!            \n");
                                        }
                                        printf("\n  Tempo gasto: %4.0f ms",1000*(double)(end-start)/(double)(CLOCKS_PER_SEC));
                                        printf("\n|----------------------------------|");
                                        getch();
                                        break;

                                    case 4:/* PESQUISA O CADASTRO ARMAZENDO NA ESTRUTURA HASH PELO NOME */
                                         printf("\nEntre com um nome para pesquisa: ");
                                         LerPalavra(Elemento.Nome,n);
                                         start = clock();
                                         T = PesquisaNomeHash(Elemento.Nome, p, Tabela);
                                         end = clock();
                                         printf("\n  Tempo gasto: %4.0f ms",1000*(double)(end-start)/(double)(CLOCKS_PER_SEC));
                                         printf("\n|----------------------------------|");
                                         getch();
                                         break;

                                    case 5:
                                         Imprime(Tabela);
                                         getch();
                                         break;
                       }
                    }while(opb!=6);
            }
     }while(op!=9);
     return 0;
}

/* ===== GERA A NOTA DOS CANDIDATOS DE ACORDO COM O GABARITO OFICIAL ====== */
int Gera_Nota(char *Candidato, char *oficial){
     int cont,temp=0;
     for(cont=0;cont<G;cont++){
         if(Candidato[cont]=='n' || Candidato[cont]=='N')
             temp=temp;
         else if(Candidato[cont]==oficial[cont])
             temp=temp+3;
         else
             temp--;
     }
     printf("Nota: %d\n\n",temp);
     cont=temp;
     return cont;
}

/* =================== COPIA A LISTA PARA FILA =============================== */
void Copia_Lista_Fila(TipoLista Lista, TipoFila *Fila){
     Apontador laux,faux;
     if(TesteListaVazia(Lista) == 1){
         printf("\n Lista vazia!!\n");
         return;
     }
     laux = Lista.Primeiro->Prox;
     faux = Fila->Inicio;
     while(laux!=NULL){
         InsereFila(laux->Item,Fila);
         laux = laux->Prox;
     }
}

/* ====================== FUN��ES DE LISTA =================================== */
int TesteListaVazia(TipoLista Lista){
    return(Lista.Primeiro == Lista.Ultimo);
}

void IniciarLista(TipoLista *Lista){
    Lista->Primeiro = (Apontador) malloc(sizeof(Celula));
    Lista->Primeiro->Prox = NULL;
    Lista->Primeiro->Ant = NULL;
    Lista->Ultimo = Lista->Primeiro;
}

void Insere(TipoLista *Lista, Candidato X,int pos_def_main,char *oficial){
    Apontador aux;
    aux=Lista->Ultimo;
    Lista->Ultimo->Prox = (Apontador) malloc(sizeof(Celula));
    Lista->Ultimo = Lista->Ultimo->Prox;
    Lista->Ultimo->Ant = aux;
    Lista->Ultimo->Item = X;
    Lista->Ultimo->Indice=pos_def_main;
    Lista->Ultimo->Prox= NULL;
}

void Imprime(TipoLista Lista){
    Apontador aux;
    int i,j,cont=0;
    if(TesteListaVazia(Lista) == 1){
        printf("\nNenhum Candidato Cadastrado Ainda!!\n");
        return;
    }
    aux = Lista.Primeiro->Prox;
    while(aux !=NULL){
        if(cont%4==0){
            system("cls");
            printf("-------------------------------------------------------------\n");
            printf("|                 Candidatos Cadastrados                    |\n");
            printf("-------------------------------------------------------------");
        }
        printf("\n\nNumero de Inscricao: %d", aux->Item.Inscricao);
        printf("\nNome: %s", aux->Item.Nome);
        printf("\nCurso: %s", aux->Item.Concurso);
        printf("\nPontos: %d", aux->Item.Pontos);
        cont++;
        if(cont%4==0){
           printf("\n\n\tAperte qualquer tecla para continuar a lista.");
           getch();
        }
        aux = aux->Prox;
    }
}

/* ========================== FUN��ES DE FILA ======================================== */
int FilaVazia(TipoFila Fila){
     return (Fila.Inicio == Fila.Fim);
}

void IniciarFila(TipoFila *Fila){
     Fila->Inicio = (Apontador) malloc(sizeof(Celula));
     Fila->Fim = Fila->Inicio;
     Fila->Inicio->Prox = NULL;
}

void InsereFila(Candidato X, TipoFila *Fila){
     Fila->Fim->Prox = (Apontador) malloc(sizeof(Celula));
     Fila->Fim = Fila->Fim->Prox;
     Fila->Fim->Item = X;
     Fila->Fim->Prox = NULL;
}

void ImprimeFila(TipoFila Fila,int vagas){
     int cont=0;
     Apontador aux;
     aux = Fila.Inicio->Prox;
     if (FilaVazia(Fila)){
           printf("Fila vazia!\n");
           return;
     }
     while (aux != NULL){
         if(cont%4==0 && cont<vagas){
                    system("cls");
                    printf("-------------------------------------------------------------\n");
                    printf("|                       Aprovados                           |\n");
                    printf("-------------------------------------------------------------");
         }
         if(cont==vagas){
                    printf("\n\n");
                    printf("-------------------------------------------------------------\n");
                    printf("|                     Lista de Espera                       |\n");
                    printf("-------------------------------------------------------------");
         }
         printf("\n\nNumero de Inscricao: %d",aux->Item.Inscricao);
         printf("\nNome: %s",aux->Item.Nome);
         printf("\nCurso: %s",aux->Item.Concurso);
         printf("\nNota: %d",aux->Item.Pontos);
         cont++;
         if(cont%4==0){
            printf("\n\n\tAperte qualquer tecla para continuar a lista");
            getch();
         }
         aux = aux->Prox;
     }
}

void SalvaFila(TipoFila Fila,int vagas){
     int cont=0;
     FILE *arq;
     Apontador aux;
     arq=fopen("Fila.txt","w");
     aux = Fila.Inicio->Prox;
     if (FilaVazia(Fila)){
           printf("Nenhum candidato salvo!\n");
           return;
     }
     while (aux != NULL){
         fprintf(arq,"%d\n%s\n%s\n%s\n%d\n\n",aux->Item.Inscricao,aux->Item.Nome,aux->Item.Concurso,aux->Item.Gabarito,aux->Item.Pontos);
         aux = aux->Prox;
         cont++;
     }
     fclose(arq);
}

/* =============================  FUN��ES DE QUICKSORT ========================================================================= */
void Quicksort(TipoLista *Lista,int ind_ultimo){
       Ordena(1,ind_ultimo,Lista);
}

void Ordena(int esq, int dir, TipoLista *Lista){
       int i,j;
       Particao(esq,dir,&i,&j,Lista);
       if(esq<j)
           Ordena(esq,j,Lista);
       if(i<dir)
           Ordena(i,dir,Lista);
}

void Particao(int esq, int dir, int *i, int *j, TipoLista *Lista){
       int pivo,aux;
       Apontador paux,pi,pj;
       Candidato tmp;
       paux = Lista->Primeiro->Prox;
       pi = Lista->Primeiro->Prox;
       pj = Lista->Ultimo;
       *i=esq;
       *j=dir;
       aux=(*i+*j)/2;
       while(paux->Indice!=aux){
           paux=paux->Prox;
       }
       pivo=paux->Item.Pontos;
       do{
           while(pi->Indice!=*i)
               pi=pi->Prox;
           while(pivo<pi->Item.Pontos){
               (*i)++;
               pi=pi->Prox;
           }
           while(pj->Indice!=*j)
               pj=pj->Ant;
           while(pivo>pj->Item.Pontos){
               (*j)--;
               pj=pj->Ant;
           }
           if(*i<=*j){
               tmp=pi->Item;
               pi->Item=pj->Item;
               pj->Item=tmp;
               (*i)++;
               pi=pi->Prox;
               (*j)--;
               pj=pj->Ant;
           }
       }while(*i<=*j);
}

/* ========================  ARVORE SBB ====================================== */
void EE(Apont *Ap){
      Apont Ap1;
      Ap1 = (*Ap)->Esq;
      (*Ap)->Esq = Ap1->Dir;
      Ap1->Dir = *Ap;
      Ap1->BitE = Vertical;
      (*Ap)->BitE = Vertical;
      *Ap = Ap1;
}

void ED(Apont *Ap){
      Apont Ap1, Ap2;
      Ap1 = (*Ap)->Esq;
      Ap2 = Ap1->Dir;
      Ap1->BitD = Vertical;
      (*Ap)->BitE = Vertical;
      Ap1->Dir = Ap2->Esq;
      Ap2->Esq = Ap1;
      (*Ap)->Esq = Ap2->Dir;
      Ap2->Dir = *Ap; *Ap = Ap2;
}

void DD(Apont *Ap){
      Apont Ap1;
      Ap1 = (*Ap)->Dir;
      (*Ap)->Dir = Ap1->Esq;
      Ap1->Esq = *Ap;
      Ap1->BitD = Vertical;
      (*Ap)->BitD = Vertical;
      *Ap = Ap1;
}

void DE(Apont *Ap){
      Apont Ap1, Ap2;
      Ap1 = (*Ap)->Dir;
      Ap2 = Ap1->Esq;
      Ap1->BitE = Vertical;
      (*Ap)->BitD = Vertical;
      Ap1->Esq = Ap2->Dir;
      Ap2->Dir = Ap1;
      (*Ap)->Dir = Ap2->Esq;
      Ap2->Esq = *Ap;
      *Ap = Ap2;
}

void IInsereSBB(Registro x, Apont *Ap, Inclinacao *IAp, short *Fim){
      if (*Ap == NULL) {
           *Ap = (Apont)malloc(sizeof(No));
           *IAp = Horizontal;
           (*Ap)->Reg = x;
           (*Ap)->BitE = Vertical;
           (*Ap)->BitD = Vertical;
           (*Ap)->Esq = NULL;
           (*Ap)->Dir = NULL;
           *Fim = FALSE;
           return;
      }
      if (x.Chave < (*Ap)->Reg.Chave){
           IInsereSBB(x, &(*Ap)->Esq, &(*Ap)->BitE, Fim);
           if (*Fim)
               return;
           if ((*Ap)->BitE != Horizontal) {
               *Fim = TRUE;
               return;
           }
           if ((*Ap)->Esq->BitE == Horizontal){
               EE(Ap);
               *IAp = Horizontal;
               return;
           }
           if ((*Ap)->Esq->BitD == Horizontal){
               ED(Ap);
               *IAp = Horizontal;
           }
           return;
      }
      if (x.Chave <= (*Ap)->Reg.Chave){
           printf("Erro: Chave ja esta na arvore\n");
           *Fim = TRUE;
           return;
      }
      IInsereSBB(x, &(*Ap)->Dir, &(*Ap)->BitD, Fim);
      if(*Fim)
           return;
      if((*Ap)->BitD != Horizontal){
           *Fim = TRUE;
           return;
      }
      if((*Ap)->Dir->BitD == Horizontal){
           DD(Ap);
           *IAp = Horizontal;
           return;
      }
      if((*Ap)->Dir->BitE == Horizontal){
            DE(Ap);
            *IAp = Horizontal;
      }
}

void InsereSBB(Registro x, Apont *Ap){
      short Fim;
      Inclinacao IAp;
      IInsereSBB(x, Ap, &IAp, &Fim);
}

void Inicializa(Apont *Dicionario){
      *Dicionario = NULL;
}

void EsqCurto(Apont *Ap, short *Fim){ /* Folha esquerda retirada => arvore curta na altura esquerda */
      Apont Ap1;
      if((*Ap)->BitE == Horizontal){
           (*Ap)->BitE = Vertical;
           *Fim = TRUE;
           return;
      }
      if((*Ap)->BitD == Horizontal){
          Ap1 = (*Ap)->Dir;
          (*Ap)->Dir = Ap1->Esq;
          Ap1->Esq = *Ap;
          *Ap = Ap1;
          if((*Ap)->Esq->Dir->BitE == Horizontal){
               DE(&(*Ap)->Esq);
               (*Ap)->BitE = Horizontal;
          }
          else
               if((*Ap)->Esq->Dir->BitD == Horizontal){
                    DD(&(*Ap)->Esq);
                    (*Ap)->BitE = Horizontal;
               }
          *Fim = TRUE;
          return;
      }
      (*Ap)->BitD = Horizontal;
      if((*Ap)->Dir->BitE == Horizontal){
          DE(Ap);
          *Fim = TRUE;
          return;
      }
      if((*Ap)->Dir->BitD == Horizontal){
          DD(Ap);
          *Fim = TRUE;
      }
}

void DirCurto(Apont *Ap, short *Fim){ /* Folha direita retirada => arvore curta na altura direita */
      Apont Ap1;
      if((*Ap)->BitD == Horizontal){
           (*Ap)->BitD = Vertical;
           *Fim = TRUE;
           return;
      }
      if((*Ap)->BitE == Horizontal){
           Ap1 = (*Ap)->Esq;
           (*Ap)->Esq = Ap1->Dir;
           Ap1->Dir = *Ap;
           *Ap = Ap1;
           if((*Ap)->Dir->Esq->BitD == Horizontal){
                ED(&(*Ap)->Dir);
                (*Ap)->BitD = Horizontal;
           }
           else
                if((*Ap)->Dir->Esq->BitE == Horizontal){
                     EE(&(*Ap)->Dir);
                     (*Ap)->BitD = Horizontal;
                }
           *Fim = TRUE;
           return;
      }
      (*Ap)->BitE = Horizontal;
      if((*Ap)->Esq->BitD == Horizontal){
           ED(Ap);
           *Fim = TRUE;
           return;
      }
      if((*Ap)->Esq->BitE == Horizontal){
           EE(Ap);
           *Fim = TRUE;
      }
}

void Antecessor(Apont q, Apont *r, short *Fim){
      if((*r)->Dir != NULL){
           Antecessor(q, &(*r)->Dir, Fim);
           if(!*Fim)
                DirCurto(r, Fim);
           return;
      }
      q->Reg = (*r)->Reg;
      q = *r;
      *r = (*r)->Esq;
      free(q);
      if (*r != NULL)
           *Fim = TRUE;
}

void Pesquisa(Registro *x, Apont *p){

      if(*p == NULL){
           printf("\n|--------- Arvore SBB -------------|\n");
           printf("              ERRO                    \n");
           printf("       Registro nao esta              \n");
           printf("       presente na arvore!            \n");
           return;
      }
      if(x->Chave < (*p)->Reg.Chave){
           Pesquisa(x, &(*p)->Esq);
           return;
      }
      if(x->Chave > (*p)->Reg.Chave)
           Pesquisa(x, &(*p)->Dir);
      else{
           *x = (*p)->Reg;
           printf("\n|--------- Arvore SBB -------------|");
           printf("\n  Numero de Inscricao: %d",(*p)->Reg.Chave);
           printf("\n  Nome: %s",(*p)->Reg.Nome);
           printf("\n  Curso: %s",(*p)->Reg.Concurso);
           printf("\n  Nota: %d",(*p)->Reg.Pontos);

      }

}

void PesquisaNome(Registro *x, Apont *p){

      if(*p == NULL){
           printf("\n|--------- Arvore SBB -------------|\n");
           printf("              ERRO                    \n");
           printf("       Registro nao esta              \n");
           printf("       presente na arvore!            \n");
           return;
      }
      if(strcmp(x->Nome,(*p)->Reg.Nome)==-1){
           PesquisaNome(x, &(*p)->Esq);
           return;
      }
      if(strcmp(x->Nome,(*p)->Reg.Nome)==1){
           PesquisaNome(x, &(*p)->Dir);
      }

      else{
           *x = (*p)->Reg;
           printf("\n|--------- Arvore SBB -------------|");
           printf("\n  Numero de Inscricao: %d",(*p)->Reg.Chave);
           printf("\n  Nome: %s",(*p)->Reg.Nome);
           printf("\n  Curso: %s",(*p)->Reg.Concurso);
           printf("\n  Nota: %d",(*p)->Reg.Pontos);

      }

}
/* =================== ESTRUTURA HASH ======================================== */
void FLVazia(TipoListaHash *Lista){
     Lista->Primeiro = (CelulaHash *)malloc(sizeof(CelulaHash));
     Lista->Ultimo = Lista->Primeiro;
     Lista->Primeiro->Prox = NULL;
}

short Vazia(TipoListaHash Lista){
     return (Lista.Primeiro == Lista.Ultimo);
}

void Ins(TipoItem x, TipoListaHash *Lista){
     Lista->Ultimo->Prox = (CelulaHash *)malloc(sizeof(CelulaHash));
     Lista->Ultimo = Lista->Ultimo->Prox;
     Lista->Ultimo->Item = x;
     Lista->Ultimo->Prox = NULL;
}

void Inicializa(TipoDicionario T){
     int i;
     for(i = 0; i < M; i++)
          FLVazia(&T[i]);
}

void InsereHashHash(TipoItem x, TipoPesos p, TipoDicionario T){
     if(Pesquisa(x.Chave, p, T) == NULL)
          Ins(x, &T[h(x.Chave, p)]);
     else
          printf(" Registro ja  esta  presente\n");
}

void Imp(TipoListaHash Lista){
     Aponta Aux;
     Aux = Lista.Primeiro->Prox;
     while(Aux != NULL){
          printf("Numero de Inscricao: %s ", Aux->Item.Chave);
          printf("\n   Nome: %s ", Aux->Item.Nome);
          printf("\n   Concuros: %s ", Aux->Item.Concurso);
          printf("\n   Pontos: %d ", Aux->Item.Pontos);
          Aux = Aux->Prox;
    }
}

void Imprime(TipoDicionario Tabela){
     int i;
     for (i = 0; i < M; i++){
          printf("\n%d: ", i);
          if(!Vazia(Tabela[i]))
               Imp(Tabela[i]);
          putchar('\n');
    }
}

void LerPalavra(char *p, int Tam){
     char c;
     int i, j;
     fflush(stdin);
     j=0;
     while( ((c=getchar())!='\n')  && j<Tam-1)
          p[j++]= c;
     p[j]='\0';
     while(c!= '\n')
          c=getchar();
  /* Desconsiderar espacos ao final da cadeia como ocorre em Pascal.*/
     for(i=j-1;(i>=0 && p[i]==' ');i--) p[i]='\0';
}

void GeraPesos(TipoPesos p){  /* -Gera valores randomicos entre 1 e 10.000- */
     int i;
     struct timeval semente;
     /* Utilizar o tempo como semente para a funcao srand() */
     gettimeofday(&semente,NULL);
     srand((int)(semente.tv_sec + 1000000*semente.tv_usec));
     for(i = 0; i < n; i++)
          p[i] =  1+(int) (10000.0*rand()/(RAND_MAX+1.0));
}

Indice h(TipoChaveHash Chave, TipoPesos p){
     int i; unsigned int Soma = 0; int comp = strlen(Chave);
     for(i = 0; i < comp; i++)
          Soma += (unsigned int)Chave[i] * p[i];
     return (Soma % M);
}

Aponta Pesquisa(TipoChaveHash Ch, TipoPesos p, TipoDicionario T){
/* -- Obs.: Aponta de retorno aponta para o item anterior da lista -- */
     Indice i;
     Aponta Ap;
     i = h(Ch, p);
     if(Vazia(T[i]))
          return NULL;   /* Pesquisa sem sucesso */
     else{
          Ap = T[i].Primeiro;
          while(Ap->Prox->Prox != NULL && strncmp(Ch, Ap->Prox->Item.Chave, sizeof(TipoChaveHash)))
	           Ap = Ap->Prox;
          if(!strncmp(Ch, Ap->Prox->Item.Chave, sizeof(TipoChaveHash))){
               printf("\n|---------  Hash ------------------|");
               printf("\n  Numero de Inscricao: %s ", Ap->Prox->Item.Chave);
               printf("\n  Nome: %s ", Ap->Prox->Item.Nome);
               printf("\n  Concuros: %s ", Ap->Prox->Item.Concurso);
               printf("\n  Pontos: %d ", Ap->Prox->Item.Pontos);
               return Ap;
         }
         else
               return NULL;   /* Pesquisa sem sucesso */
    }
}

Aponta PesquisaNomeHash(TipoChaveHash Ch, TipoPesos p, TipoDicionario T){
/* -- Obs.: Aponta de retorno aponta para o item anterior da lista -- */
     Indice i;
     Aponta Ap;
     i = h(Ch, p);
     if(Vazia(T[i]))
          return NULL;   /* Pesquisa sem sucesso */
     else{
          Ap = T[i].Primeiro;
          while(Ap->Prox->Prox != NULL && strncmp(Ch, Ap->Prox->Item.Nome, sizeof(TipoChaveHash)))
	           Ap = Ap->Prox;

          printf("\n|---------  Hash ------------------|");
          printf("\n  Numero de Inscricao: %s ", Ap->Prox->Item.Chave);
          printf("\n  Nome: %s ", Ap->Prox->Item.Nome);
          printf("\n  Concuros: %s ", Ap->Prox->Item.Concurso);
          printf("\n  Pontos: %d ", Ap->Prox->Item.Pontos);
          return Ap;

          if(!strncmp(Ch, Ap->Prox->Item.Nome, sizeof(TipoChaveHash))){
               printf("\n|---------  Hash ----------------|");
               printf("\nNumero de Inscricao: %s ", Ap->Prox->Item.Chave);
               printf("\nNome: %s ", Ap->Prox->Item.Nome);
               printf("\nConcuros: %s ", Ap->Prox->Item.Concurso);
               printf("\nPontos: %d ", Ap->Prox->Item.Pontos);
               return Ap;
          }
          else
               return NULL;   /* Pesquisa sem sucesso */
    }
}
