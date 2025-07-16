#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

bool is_pali(long long num){
    string num_str = to_string(num);

    for (int i = 0; i < num_str.length() / 2; i++){
        if (num_str[i] != num_str[num_str.length() - i - 1]){
            return false;
        }
    }
    return true;
}

void rev_add(long long &num){
    string tmp = to_string(num);

    for (int i = 0; i < tmp.length() / 2; i++){
        swap(tmp[i], tmp[tmp.length() - i - 1]);
    }
    
    for (int i = 0; i < tmp.length(); i++){
        num += (tmp[i] - '0') * pow(10, tmp.length() - i - 1);
    }
}

int main()
{
    int N, least_add;
    long long P;

    cin >> N;
    for (int test = 0; test < N; test++){
        cin >> P;

        least_add = 0;
        do{
            rev_add(P);
            least_add++;
        } while (!is_pali(P));

        cout << least_add << " " << P << endl;
    }
}