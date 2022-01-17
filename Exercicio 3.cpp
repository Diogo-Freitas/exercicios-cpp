#include <iostream>
#include <cstdlib>
#include <iomanip>
#define C 12 // Define quanto o veiculo faz por km
using namespace std;

int main()
{
    float t,v,d,l;
    do{
       system("cls");
       cout << "Digite a velocidade(Km/h): ";
       cin >> v;
       if(v<=0)
           cout << "Velocidade invalida!!";
    }while(v<=0);
    do{
       system("cls");
       cout << "Digite o tempo(h): ";
       cin >> t;
       if(t<=0)
           cout << "Tempo invalido!!";
    }while(t<=0);
    d = t*v;
    l = d/C;
    system("cls");
    cout << "\nVelocidade Media:     " << setw(5) << v << " Km/h";
    cout << "\nTempo Gasto:          " << setw(5) << t << " Hora";
    cout << "\nDistancia Percorrida: " << setw(5) << d << " Km";
    cout << setprecision(2);
    cout << "\nCombustivel Gasto:    " << setw(5) << l << " L\n\n";
    system("PAUSE");
    return 0;
}
