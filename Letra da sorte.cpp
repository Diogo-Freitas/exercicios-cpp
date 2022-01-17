// Testa a capacidade de adinhar uma letra

#include <iostream>
#include <cstdlib>
#include <conio.h>

using namespace std;

int main()
{
    do{
        int tentativas =1;
        char adivinha; 
        srand((unsigned)time(0));
        adivinha = rand() %26 + 'a';
        srand((unsigned)time(NULL));
        cout << "\n\nDigite uma letra entra 'a' e 'z': " << endl;
        char resp;
        while((resp=getch())!=adivinha){
            cout << resp << " e incorreto. Tente novamente" << endl;
            tentativas++;
        }
        cout << resp << "\n E CORRETO!!" << "\nVocr acertou em " << tentativas << "tentativas";
        cout << "\nQuer jogar novamente? (s/n): ";
    }while(getche()=='s');
    cout << "\nAte logo!" << endl;
    system("PAUSE");
    return 0;
}
