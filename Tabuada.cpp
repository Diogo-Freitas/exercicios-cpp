//Imprime a tabuada do 1 ao oo

#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

int main()
{
    system("cls"); //limpa tela

    for( int k=0 ; k <= 1 ; k++ ){ // Quantidade de colunas de 5 tabuadas
        cout << endl;
        for( int i=0 ; i <=4 ; i++ ) // Imprime o cabeçario da tabuada
            cout << "TABUADA DO " << setw(3) << (i+5*k+1) << " ";
        cout << endl;
        for( int i = 1 ; i <= 10 ; i++ ){ // Multipilca do 1 ao 10
            for( int j=1+5*k; j <=5+5*k; j++)
                cout << setw(3) << j << "x" << setw(3) << i << " = " << setw(3) << j*i << " ";
            cout << endl;
        }
    }

    system("PAUSE");
    return 0;
}
