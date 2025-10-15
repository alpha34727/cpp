#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> pi_arr;

void build_prefix(const string &pattern){
    pi_arr.resize(pattern.size());
    pi_arr[0] = 0;

    int i = 1;
    int prefix_len = 0;
    while (i < pattern.size()){
        if (pattern[i] == pattern[prefix_len]){
            prefix_len++;
            pi_arr[i] = prefix_len;
            i++;
        }
        else{
            if (prefix_len != 0){
                prefix_len = pi_arr[prefix_len - 1];
            }
            else{
                pi_arr[i] = 0;
                i++;
            }
        }
    }
}

int kmp_search(const string &str, const string &pattern){
    build_prefix(pattern);

    int i = 0;
    int j = 0;

    while (i < str.size()){
        if (str[i] == pattern[j]){
            i++;
            j++;
        }
        else{
            if (j != 0){
                j = pi_arr[j - 1];
            }
            else{
                i++;
            }
        }

        if (j == pattern.size()){
            break;
        }
    }

    return i - j;
}

int main()
{
    int pail_st;
    string str, str_rev;

    while (cin >> str){
        str_rev = str;
        reverse(str_rev.begin(), str_rev.end());

        pail_st = str.size() - kmp_search(str, str_rev) - 1;

        cout << str;
        for (int i = pail_st + 1; i < str_rev.size(); i++){
            cout << str_rev[i];
        }
        cout << endl;
    }

    return 0;
}