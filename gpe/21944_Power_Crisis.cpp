#include <iostream>

using namespace std;

int dp[101];

int calc(int sit, int gap){
    if (sit == 1){
        return 0;
    }
    if (dp[sit] != -1){
        return dp[sit];
    }
    dp[sit] = (calc(sit-1, gap) + gap) % sit;
    return dp[sit];
}

int main()
{
    int N, M;

    while (cin >> N && N != 0){
        M = 1;
        while (true){
            for (int i = 0; i < 101; i++){
                dp[i] = -1;
            }
            
            if (calc(N - 1, M) == 11){
                break;
            }
            ++M;
        }
        cout << M << endl;
    }

    return 0;
}