//Conta caracteres de uma frase
#include <iostream>
#include <cstdlib>
#include <conio.h>
using namespace std;
int main()
{
int cont=0; //contador
while(getche() != '\r') //enquanto n�o [Enter]
cont++; //Corpo do la�o
//Fora do la�o
cout << "\nO numero de caracteres e " << cont << endl;
system("PAUSE"); return 0;
}
