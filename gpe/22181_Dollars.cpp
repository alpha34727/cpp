#include <iostream>
#include <iomanip>

using namespace std;

#define PRECISION 0.00001

const int coins[] = {10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5};
const int coins_len = sizeof(coins) / sizeof(int);
long long comb[30001];

int main()
{
    int a, b, target;
    char junk;

    for (int i = 0; i < 30001; i++){
        comb[i] = 0;
    }
    comb[0] = 1;

    for (int i = 0; i < coins_len; i++){
        for (int j = coins[i]; j <= 30000; j++){
            comb[j] += comb[j - coins[i]];
        }
    }

    while (cin >> a >> junk >> b && a + b != 0){
        target = a * 100 + b;
        cout << setw(6) << fixed << setprecision(2) << target / 100.0;
        cout << setw(17) << comb[target] << endl;
    }
}