#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int num,cont=1,n;
    num = rand()%100;
    do{
        system("cls");
        cout << "Tente adivinhar o numero: ";
        cin >> n;
        if(num<n){
            cout << "Voce digitou um numero MAIOR.\n";
            cont++;
            system("PAUSE");
        }
        if(num>n){
            cout << "Voce digitou um numero MENOR.\n";
            cont++;
            system("PAUSE");
        }
        if(num==n){
            cout << "Voce acertou!!!\nNumero de tentativas: " << cont << endl;
            system("PAUSE");
        }
    }while(num!=n);
    return 0;
}
