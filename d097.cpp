#include <iostream>

using namespace std;

bool jolly_jumper[3001] = {};

int main()
{
    int n, a1, a2, d;
    bool is_jolly_jumper;

    while (cin >> n){
        is_jolly_jumper = true;
        for (int i = 1; i < n; i++){
            jolly_jumper[i] = false;
        }

        cin >> a1;
        for (int i = 1; i < n; i++){
            cin >> a2;
            d = (a2 > a1) ? (a2 - a1) : (a1 - a2);

            // cout << "a1: " << a1 << ", a2: " << a2 << endl;

            if (!(1 <= d && d <= n - 1)){
                is_jolly_jumper = false;
                // break;
            }

            if (jolly_jumper[d]){
                is_jolly_jumper = false;
                // break;
            }
            jolly_jumper[d] = true;

            a1 = a2;
        }

        // for (int i = 1; i < n; i++){
        //     cout << jolly_jumper[i] << ", ";
        // }
        // cout << "\n";

        for (int i = 1; i < n; i++){
            if (!jolly_jumper[i]){
                is_jolly_jumper = false;
                break;
            }
        }

        if (is_jolly_jumper){
            cout << "Jolly" << endl;
        }
        else{
            cout << "Not jolly" << endl;
        }
    }


    return 0;
}