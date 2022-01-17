#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int num,menor,maior=0;
    do{
        system("cls");
        cout << "Para encerrar o processo digite 0";
        cout << "\nEntre com um numero inteiro positivo: ";
        cin >> num;
        if(num<0)
            cout << "Numero invalido!!";
        else{
            if(menor>num && num!=0)
                menor=num;
            if(maior<num && num!=0)
                maior=num;
        }
    }while(num != 0);
    cout << "O Menor Numero e: " << menor << endl;
    cout << "O Mior Numero e: " << maior << endl;
    system("PAUSE");
    return 0;

}
