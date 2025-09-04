#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int a, b, c, d;

    cin >> a >> b >> c;

    d = b * b - 4 * a * c;

    if (d > 0){
        cout << "Two different roots x1=" << (int)((-b + sqrt(d)) / (2.0 * a))
             << " , x2=" << (int)((-b - sqrt(d)) / (2.0 * a)) << endl;
    }
    else if (d == 0){
        cout << "Two same roots x=" << (int)((-b + sqrt(d)) / (2.0 * a)) << endl;
    }
    else{
        cout << "No real root" << endl;
    }

    return 0;
}