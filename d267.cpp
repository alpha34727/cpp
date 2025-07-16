#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n, Max;
    int stats[26];

    string str;

    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++){
        for (int j = 0; j < 26; j++){
            stats[j] = 0;
        }

        getline(cin, str);
        for (auto chr : str){
            if ('a' <= chr && chr <= 'z'){
                stats[chr - 'a']++; 
            }
            else if ('A' <= chr && chr <= 'Z'){
                stats[chr - 'A']++;
            }
        }

        Max = -1;
        for (int j = 0; j < 26; j++){
            if (stats[j] > Max){
                Max = stats[j];
            }
        }

        for (int j = 0; j < 26; j++){
            if (stats[j] == Max){
                cout << (char)(j + 'a');
            }
        }
        cout << endl;
    }

    return 0;
}