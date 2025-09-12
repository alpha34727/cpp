#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

int n;
vector<int> all_num;

int calc()
{
    for (int i = n - 1; i >= 3; i--){
        int d = all_num[i];

        for (int ai = 0; ai < n; ai++){
            for (int bi = 0; bi < n; bi++){
                for (int ci = 0; ci < n; ci++){
                    if (ai == bi || ai == ci || ai == i || bi == ci || bi == i || ci == i){
                        continue;
                    }

                    if (all_num[ai] + all_num[bi] + all_num[ci] == d){
                        return d;
                    }
                }
            }
        }
    }
    return -1;
}

int main()
{
    while (cin >> n && n != 0){
        all_num.clear();

        all_num.resize(n);
        for (int i = 0; i < n; i++){
            cin >> all_num[i];
        }

        sort(all_num.begin(), all_num.end());

        int ans = calc();
        if (ans == -1){
            cout << "no solution" << endl;
        }
        else{
            cout << ans << endl;
        }
    }
}