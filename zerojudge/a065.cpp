#include <iostream>

using namespace std;

int main()
{
    char str[7];

    cin >> str;
    for (int i = 0; i < 6; i++){
        if (str[i] > str[i+1])
            cout << str[i] - str[i+1];
        else
            cout << str[i+1] - str[i];
    }
    cout << endl;

    return 0;
}