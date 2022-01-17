#include <iostream>
#include <cstdlib>

void Pascoa(int ano);

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

void Pascoa(int Ano){
    int A,B,C,D,E,F,G,H,I,K,L,M,Mes,Dia;
    A=Ano%19;
    B=Ano/100;
    C=Ano%100;
    D=B/4;
    E=B%4;
    F=(B+8)/25;
    G=(B-F+1)/3;
    H=(19*A+B-D-G+15)%30;
    I=C/4;
    K=C%4;
    L=(32+2*E+2*I-H-K)%7;
    M=(A+11*H+22*L)/451;
    Mes=(H+L-7*M+114)/31;
    Dia=((H+L-7*M+114)%31)+1;
    cout << "Pascoa " << Dia << "/" << Mes << "/" << Ano << endl;
}
