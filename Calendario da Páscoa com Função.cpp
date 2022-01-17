#include <iostream>
#include <cstdlib>

void Pascoa(int ano);
int A(int ano);
int B(int ano);
int C(int ano);
int D(int b);
int E(int b);
int F(int b);
int G(int b,int f);
int H(int a,int b,int d,int g);
int I(int c);
int K(int c);
int L(int e,int i,int h,int k);
int M(int a,int h,int l);
int Mes(int h,int l,int m);
int Dia(int h,int l,int m);
using namespace std;

int main()
{
    int ano;
    cout << "Entre com o ano: ";
    cin >> ano;
    system("cls");
    Pascoa(ano);
    return 0;
}

void Pascoa(int ano){
    int a,b,c,d,e,f,g,h,i,k,l,m,mes,dia;
    a=A(ano);
    b=B(ano);
    c=C(ano);
    d=D(b);
    e=E(b);
    f=F(b);
    g=G(b,f);
    h=H(a,b,d,g);
    i=I(c);
    k=K(c);
    l=L(e,i,h,k);
    m=M(a,h,l);
    mes=Mes(h,l,m);
    dia=Dia(h,l,m);
    cout << "Pascoa " << dia << "/" << mes << "/" << ano << endl;
}

int A(int ano){
    int a;
    a=ano%19;
    return a;
}
int B(int ano){
    int b;
    b=ano/100;
    return b;
}
int C(int ano){
    int c;
    c=ano%100;
    return c;
}
int D(int b){
    int d;
    d=b/4;
    return d;
}
int E(int b){
    int e;
    e=b%4;
    return e;
}
int F(int b){
    int f;
    f=(b+8)/25;
    return f;
}
int G(int b,int f){
    int g;
    g=(b-f+1)/3;
    return g;
}
int H(int a,int b,int d,int g){
    int h;
    h=(19*a+b-d-g+15)%30;
    return h;
}
int I(int c){
    int i;
    i=c/4;
    return i;
}
int K(int c){
    int k;
    k=c%4;
    return k;
}
int L(int e,int i,int h,int k){
    int l;
    l=(32+2*e+2*i-h-k)%7;
    return l;
}
int M(int a,int h,int l){
    int m;
    m=(a+11*h+22*l)/451;
    return m;
}
int Mes(int h,int l,int m){
    int mes;
    mes=(h+l-7*m+114)/31;
    return mes;
}
 int Dia(int h,int l,int m){
    int dia;
    dia=((h+l-7*m+114)%31)+1;
    return dia;
 }
