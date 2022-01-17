#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int a,b,c;
    cout << "Entre com o primeiro numero: ";
    cin >> a;
    cout << "Entre com o segundo numero : ";
    cin >> b;
    if(a>b){
         c=a-b;
         cout << "A diferenca e: " << c << endl;
    }
    else{
         c=b-a;
         cout << "A diferenca e: " << c << endl;
    }
    system("PAUSE");
    return 0;
}
