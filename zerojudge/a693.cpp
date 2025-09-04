#include <iostream>

using namespace std;

int foods[100001] = {};

int main()
{
    int n, m, tmp, l, r, sum;

    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    while (cin >> n >> m){
        sum = 0;
        for (int i = 1; i <= n; i++){
            cin >> tmp;
            sum += tmp;

            foods[i] = sum;
        }

        for (int i = 0; i < m; i++){
            cin >> l >> r;
            cout << foods[r] - foods[l-1] << endl;
        }
    }

    return 0;
}