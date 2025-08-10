#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct Alphabet{
    char chr;
    int cnt;
};

bool cmp(Alphabet a, Alphabet b){
    if (a.cnt != b.cnt){
        return a.cnt > b.cnt;
    }
    return a.chr < b.chr;
}

int main()
{
    int n;
    string input;

    Alphabet stats[26];

    for (int i = 0; i < 26; i++){
        stats[i].chr = (char)(i + (int)'A');
        stats[i].cnt = 0;
    }

    cin >> n;
    cin.ignore();
    for (int test = 0; test < n; test++){
        getline(cin, input);

        for (char c : input){
            if ('a' <= c && c <= 'z'){
                stats[(int)c - (int)'a'].cnt++;
            }
            else if ('A' <= c && c <= 'Z'){
                stats[(int)c - (int)'A'].cnt++;
            }
        }
    }

    sort(stats, stats + 26, cmp);

    for (int i = 0; i < 26; i++){
        if (stats[i].cnt > 0){
            cout << stats[i].chr << " " << stats[i].cnt << endl;
        }
        else {
            break;
        }
    }

    return 0;
}