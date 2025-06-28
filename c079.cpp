#include <iostream>

using namespace std;

int main()
{
    int n, k, butt, cigarette, smoke;

    while (cin >> n >> k){
        butt = 0;
        cigarette = n;
        smoke = 0;
        while (cigarette != 0){
            smoke += cigarette;
            butt += cigarette;
            cigarette = 0;

            // cout << "smoke: " << smoke << " | " << "butt: " << butt << " | " << "cigra: " << cigarette << endl;

            cigarette = butt / k;
            butt -= butt / k * k;

            // cout << "smoke: " << smoke << " | " << "butt: " << butt << " | " << "cigra: " << cigarette << endl;
        }

        cout << smoke << endl;
    }

    return 0;
}