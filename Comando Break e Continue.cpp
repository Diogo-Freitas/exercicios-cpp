#include <iostream>
#include <cstdlib>
#include <conio.h> //para getche()
using namespace std;
int main()
{
    cout << "Pense em um numero entre 1 e 99, e responda" << endl;
    cout << " =, > ou < para igual, maior ou menor" << endl;
    float incr=50.0, adiv=50.0;
    while ( incr > 1){
        char ch; incr/=2;
        cout << "\n=, > ou < a " << int (adiv) << "? ";
        if((ch=getche())== '=')
            break;
        else if ( ch == '>')
            adiv += incr;
        else adiv -= incr;
    }
    cout << "\nO numero e " << int(adiv);
    cout << "\nCOMO SOU ESPERTO!!!" << endl;
    system("PAUSE"); return 0;
}
