#include <iostream>
#include <ctime>
#include "DynamicArray.h"

using namespace std;

int main()
{
    srand(time(0));

    DynamicArray a(5);
    a.Input();
    a.Output();

    a.Sort();
    a.Output();

    a.Reverse();
    a.Output();

    cout << a.Search(a.GetPtr()[0]) << endl;

    a.ReSize(7);
    a.Output();

    DynamicArray rez = a + 10;
    rez.Output();

    DynamicArray rez1 = a - 2;
    rez1.Output();

    DynamicArray rez2 = a * 2;
    rez2.Output();

    DynamicArray b(3);
    b.Input();
    b.Output();

    DynamicArray rez4 = a + b;
    rez4.Output();

    ++rez;
    rez.Output();

    --rez;
    rez.Output();

    return 0;
}
