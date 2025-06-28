#include <iostream>

using namespace std;

int main()
{
    int n, y;

    cin >> n;

    for (int i = 1; i <= n; i++){
        cin >> y;

        cout << "Case " << i << ": ";
        if (y % 4 == 0 && !(y % 400 != 0 && y % 100 == 0)){
            cout << "a leap year" << endl;
        }
        else{
            cout << "a normal year" << endl;
        }
    }

    return 0;
}