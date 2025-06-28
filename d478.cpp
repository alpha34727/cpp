#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> digits;

int main()
{
    int n, m, same, tmp;

    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    cin >> n >> m;
    digits.resize(m);
    for (int i = 0; i < n; i++){
        same = 0;
        for (int j = 0; j < m; j++){
            cin >> digits[j];
        }

        for (int j = 0; j < m; j++){
            cin >> tmp;

            if (tmp < digits[0] || tmp > digits[m-1]){
                continue;
            }

            if (binary_search(digits.begin(), digits.end(), tmp)){
                same++;
            }
        }

        cout << same << endl;
    }

    return 0;
}