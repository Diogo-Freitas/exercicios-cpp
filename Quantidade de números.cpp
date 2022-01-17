#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int n,i,j,x=0;
    cout << "Deseja entra com quantos numeros: ";
    cin >> n;
    int vet[n-1],fib[n],vf[n-1];
    fib[0]=fib[1]=1;
    system("cls");
    for(i=0;i<n;i++){
        cout << "Digite o " << i+1 << "\xa7 numero: ";
        cin >> vet[i];
        if(vet[i]==1)
            x++;
    }
    for(i=0;i<n;i++){
        for(j=2;j<=20;j++){
            fib[j]=fib[j-2]+fib[j-1];
            if(vet[i]==fib[j])
                x++;
        }
    }
    cout << x << endl;
    system("PAUSE");
    return 0;
}
