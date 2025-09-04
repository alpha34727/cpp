#include <iostream>

using namespace std;

int ans[301][301];

int split_chocolate(int m, int n){
    if (m == 1 && n == 1){
        return 0;
    }

    if (ans[m][n] != -1){
        return ans[m][n];
    }

    // cout << m << ", " << n << "  --> ";
    if (m > n){
        // cout << m / 2 << ", " << n  << " + " << m - m / 2 << ", " << n << endl;
        ans[m][n] = split_chocolate(m / 2, n) + split_chocolate(m - m / 2, n) + 1;
        return ans[m][n];
    }
    // cout << m << ", " << n / 2  << " + " << m << ", " << n - n / 2 << endl;
    ans[m][n] = split_chocolate(m, n / 2) + split_chocolate(m, n - n / 2) + 1;
    return ans[m][n];
}

int main()
{
    int m, n;

    for (int i = 0; i < 301; i++){
        for (int j = 0; j < 301; j++){
            ans[i][j] = -1;
        }
    }

    while (cin >> m >> n){
        cout << split_chocolate(m, n) << endl;
    }

    return 0;
}