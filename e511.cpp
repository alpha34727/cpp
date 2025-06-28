#include <iostream>

using namespace std;

int main()
{
    int t, n, Min, Max, tmp;

    cin >> t;

    for (int i = 0; i < t; i++){
        cin >> n;

        Min = 100;
        Max = -1;
        for (int j = 0; j < n; j++){
            cin >> tmp;
            if (tmp < Min){
                Min = tmp;
            }
            if (tmp > Max){
                Max = tmp;
            }
        }

        cout << 2 * (Max - Min) << endl;
    }

    return 0;
}