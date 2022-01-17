//Com tamanho de campo
//Com manipuladores setw, setiosflags e setprecision
#include <iostream>
#include <cstdlib>
#include <iomanip> //para o uso de manipuladores
using namespace std;
int main()
{ float lapis=4.875, borrachas=23.542, canetas=42.036, cadernos=8.0;
cout <<"\n\n\n";
cout << setiosflags(ios::fixed) //parte inteira inalterada
<< setiosflags(ios::showpoint) //sempre imprimir o ponto decimal
<< setprecision(2); //duas casas decimais
cout <<'\n'<<"Lapis "<< setw(12) << lapis;
cout <<'\n'<<"Borrachas "<< setw(12) << borrachas;
cout <<'\n'<<"Canetas "<< setw(12) << canetas;
cout <<'\n'<<"Cadernos "<< setw(12) << cadernos;
cout << endl; system("PAUSE"); return 0; }
