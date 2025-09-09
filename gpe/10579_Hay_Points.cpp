#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
    int n, m, money;
    string key;
    unsigned long long total_money;
    unordered_map<string, int> word_to_money;

    cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> key >> money;
        word_to_money[key] = money;
    }

    for (int test = 0; test < m; test++){
        total_money = 0;
        bool isEnd = false;
        while (true){
            cin >> key;
            
            if (key.back() == '.'){
                isEnd = true;
                key = key.substr(0, key.length() - 1);
            }

            if (word_to_money.count(key) > 0){
                total_money += word_to_money[key];
            }

            if (isEnd){
                break;
            }
        }
        cout << total_money << endl;
    }


}