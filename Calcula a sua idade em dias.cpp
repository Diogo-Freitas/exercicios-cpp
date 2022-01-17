//Calcula a sua idade em dias
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    cout << "Digite a sua idade em anos: ";
    int anos;
    cin >> anos;
    cout << " \nA sua idade em dia e: " << (anos*365) << endl;
    system("PAUSE");
    return 0;
}
