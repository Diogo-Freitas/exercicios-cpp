#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
    int cont=1;
    system("cls");
    for( int lin=1; lin<=8; lin++){
        do{
        for(int col=1; col<=8; col++){
            if((lin+col)%2==0)
                cout << "\xdb\xdb\xdb\xdb";
            else
                cout << "    ";
            }
            cont++;
        cout << endl;
        }while(cont%2==0);
    }
    system("PAUSE");
    return 0;
}
