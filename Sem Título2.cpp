//Conta caracteres de uma frase
#include <iostream>
#include <cstdlib>
#include <conio.h>
using namespace std;
int main()
{
int cont=0; //contador
while(getche() != '\r') //enquanto não [Enter]
cont++; //Corpo do laço
//Fora do laço
cout << "\nO numero de caracteres e " << cont << endl;
system("PAUSE"); return 0;
}
