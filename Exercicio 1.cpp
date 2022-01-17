#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    float v,r,a;
    cout << "Entre com o raio da lata de oleo: ";
    cin >> r;
    cout << "Entre com a altura da lata de oleo: ";
    cin >> a;
    v=3.14159*(r*r)*a;
    cout << "O volume da lata e: " << v << "ml" << endl;
    system("PAUSE");
    return 0;
}
