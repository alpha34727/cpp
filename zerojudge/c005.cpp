#include <iostream>

using namespace std;

int main()
{
    int n, f, junk;
    long long area, eco_level, money;

    cin >> n;
    for (int j = 0; j < n; j++){
        cin >> f;
        money = 0;
        for (int i = 0; i < f; i++){
            cin >> area >> junk >> eco_level;
            money += area * eco_level;
        }
        cout << money << endl;
    }

    return 0;
}