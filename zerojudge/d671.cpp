#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    int T, decode_n;
    string str;

    cin >> T;
    cin.ignore();
    for (int test = 0; test < T; test++){
        getline(cin, str);

        decode_n = (int)sqrt(str.length());
        if (decode_n * decode_n != str.length()){
            cout << "INVALID" << endl;
            continue;
        }

        for (int j = 0; j < decode_n; j++){
            for (int i = 0; i < str.length(); i += decode_n){
                cout << str[i + j];
            }
        }
        cout << endl;
    }
}