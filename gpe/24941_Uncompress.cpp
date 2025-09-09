#include <iostream>
#include <string>
#include <deque>

using namespace std;

bool is_numeric(string & str){
    if (str.length() <= 0){
        return false;
    }
    for (auto c : str){
        if (!('0' <= c && c <= '9')){
            return false;
        }
    }
    return true;
}

bool is_numeric_alphabet(char c){
    if (!(('0' <= c && c <= '9') || ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'))){
        return false;
    }
    return true;
}

int main()
{   
    int st, len;
    string words, now_word;
    deque<string> word_bank;

    cin.tie(0);
    ios_base::sync_with_stdio(0);

    while (getline(cin, words) && words != "0"){
        // if (words == ""){
        //     continue;
        // }
        now_word = "";
        for (int i = 0; i < words.length(); i++){
            if (is_numeric_alphabet(words[i])){
                now_word += words[i];
            }
            else{
                if (is_numeric(now_word)){
                    int pos = stoi(now_word) - 1;
                    string tmp = word_bank[pos];
                    word_bank.erase(word_bank.begin() + pos);
                    now_word = tmp;
                }
                if (now_word != ""){
                    word_bank.push_front(now_word);
                }
                cout << now_word << words[i];
                now_word = "";
            }
        }
        if (is_numeric(now_word)){
            int pos = stoi(now_word) - 1;
            string tmp = word_bank[pos];
            word_bank.erase(word_bank.begin() + pos);
            now_word = tmp;
        }
        if (now_word != ""){
            word_bank.push_front(now_word);
        }
        cout << now_word<< endl;
    }
}