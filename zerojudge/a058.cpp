#include <iostream>

using namespace std;

int main()
{
    int n, digit;
    int k3 = 0;
    int k3_1 = 0;
    int k3_2 = 0;

    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> digit;

        if (digit % 3 == 0){
            k3++;
        }
        if ((digit - 1) % 3 == 0){
            k3_1++;
        }
        if ((digit - 2) % 3 == 0){
            k3_2++;
        }
    }

    cout << k3 << " " << k3_1 << " " << k3_2 << endl;

    return 0;
}