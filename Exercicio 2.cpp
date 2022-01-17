#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int a,b,c,n,soma=0;
    do{
       system("cls");
       cout << "Entre com um numero positivo maior que 1: ";
       cin >> a;
    }while(a<=1);
    cout << "Entre com um numero: ";
    cin >> b;
    cout << "Entre com mais um numero: ";
    cin >> c;
    if(b>c){
         for(n=c; n<b; n++)
              if(n%a==0)
                  soma+=n;
    }
    else{
         for(n=b; n<c; n++)
               if(n%a==0)
                  soma+=n;
    }
    cout << "A soma e: " << soma << endl;
    system("PAUSE");
    return 0;
}
