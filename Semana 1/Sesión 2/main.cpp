#include <iostream>
using namespace std;

int main()
{
    int num;
    int fact = 1;
    cout << "Escribe un numero para convertirlo en factorial: ";
    cin >> num;
    if (num == 0)
    {
        fact = 1;
    }
    else
    {
        for (int i = 1; i <= num; i++)
        {
            fact = fact * i;
        }
    }
    cout << "Tu numero fue: " << num << " y su factorial es: " << fact;
}