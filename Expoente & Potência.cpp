#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int x,y,i,n=1;
    do{
        system("cls");
        cout << "Entre com o Expoente: ";
        cin >> x;
        cout << "Entre com a Potencia: ";
        cin >> y;
    }while(x<0 && y<0);
    if(x==0 && y==0)
        cout << "Respotas: Indeterminado\n";
    else{
        for(i=0;i<y;i++)
            n=n*x;
        cout << "Respotas: " << n << endl;
    }

    system("PAUSE");
    return 0;
}
