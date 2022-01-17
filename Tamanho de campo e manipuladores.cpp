//Programa com tamanho de campo e manipuladores

#include <iostream>
#include <cstdlib>
#include <iomanip> // Para uso de manipuladores

using namespace std;

int main()
{
    int lapis=45, borrachas=2345, canetas=420, cadernos=8;
    cout << "Sem manipuladores";
    cout << '\n' << "Lapis     " << lapis;
    cout << '\n' << "Borrachas " << borrachas;
    cout << '\n' << "Canetas   " << canetas;
    cout << '\n' << "Cadernos  " << cadernos;
    cout << endl;
    cout << "\nCom manipulador setw";
    cout << '\n' << "Lapis     " << setw(12) << lapis;
    cout << '\n' << "Borrachas " << setw(12) << borrachas;
    cout << '\n' << "Canetas   " << setw(12) << canetas;
    cout << '\n' << "Cadernos  " << setw(12) << cadernos;
    cout << endl;
    cout << "\nCom manipulador setw e setfill";
    cout << setfill('.');
    cout << '\n' << "Lapis     " << setw(12) << lapis;
    cout << '\n' << "Borrachas " << setw(12) << borrachas;
    cout << '\n' << "Canetas   " << setw(12) << canetas;
    cout << '\n' << "Cadernos  " << setw(12) << cadernos;
    cout << endl;
    system("PAUSE");
    return 0;
}
