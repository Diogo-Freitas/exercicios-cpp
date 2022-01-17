//Mostra o uso do cin com várias entradas
//Calcula a média de 4 notas
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    cout << "Digite as notas das 4 provas: ";
    float p1,p2,p3,p4;
    cin >> p1 >> p2 >> p3 >> p4;
    float media = (p1+p2+p3+p4)/4.0;
    cout << "\nMEDIA: " << media << endl;
    system("PAUSE");
    return 0;
}
