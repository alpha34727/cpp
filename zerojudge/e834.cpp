#include <iostream>

using namespace std;

int main()
{
    int base, order;

    cin >> base;

    while (cin >> order && order != 0){
        if (order % base == 0){
            cout << order / base << endl;
        }
        else{
            cout << base - order % base << endl;
        }
    }

    return 0;
}