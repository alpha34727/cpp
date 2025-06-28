#include <iostream>

using namespace std;

int main()
{
    int n, Max = -1, tmp;

    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> tmp;
        if (tmp > Max){
            Max = tmp;
        }
    }

    cout << Max;

    return 0;
}