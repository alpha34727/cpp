#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int to_dec(int n, int b, int digits){
    if (b == 10){
        return n;
    }

    int new_n = 0;
    for (int i = 0; i < digits; i++){
        new_n += (n % 10) * pow(b, i);
        n /= 10;
    }
    return new_n;
}

int main()
{
    int b, N, N_calc, sum, digits;

    cin >> b >> N;

    digits = to_string(N).length();
    N_calc = N;
    sum = 0;

    for (int i = 0; i < digits; i++){
        sum += pow(N_calc % 10, digits);
        N_calc /= 10;
    }

    if (sum == to_dec(N, b, digits)){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }

    return 0;

}