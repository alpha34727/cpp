#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const unsigned long long format_len[] = {10000000, 100000, 1000, 100};
const string format_text[] = {" kuti", " lakh", " hajar", " shata"};

bool calc(unsigned long long num, bool is_end = true){
    bool has_front = false;
    bool has_output = false;
    if (num >= format_len[0] * 100){
        has_output = has_output || calc(num / format_len[0], false);
        num %= format_len[0] * 100;
        has_front = true;
    }

    for (int i = 0; i < 4; i++){
        if (num / format_len[i] > 0){
            cout << " " << num / format_len[i] << format_text[i];
            has_output = true;
        }
        else if (is_end && has_front && i == 0){
            cout << format_text[i];
            has_output = true;
        }
        num %= format_len[i];
    }

    if (is_end){
        if (has_output){
            if (num != 0)
                cout << " " << num << endl;
            else{
                cout << endl;
            }
        }
        else{
            cout << " " << num << endl;
        }
    }

    return has_output;
}

int main()
{
    int test = 1, digit, orilen;
    unsigned long long num;
    
    while (cin >> num){
        cout << setw(4) << test << ".";        
        calc(num);
        ++test;
    }
}