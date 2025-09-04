#include <iostream>

using namespace std;

int main()
{
    int T, a, b, n;

    cin >> T;

    for (int i = 1; i <= T; i++){
        cin >> a >> b;
        
        a = ((a >> 1) << 1) + 1;
        b = (((b + 1) >> 1) << 1) - 1;
        n = ((b - a) >> 1) + 1;

        // cout << a << " " << b << " " << n << endl;
        cout << "Case " << i << ": ";
        cout << n * (a + b) / 2 << endl;
    }

    return 0;
}