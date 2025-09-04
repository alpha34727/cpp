#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

bool is_armstrong_num(long long num){
    string str_num = to_string(num);
    long long n = str_num.length();
    long long arm_num = 0;

    for (auto i : str_num){
        arm_num += pow(((long long)i - (long long)'0'), n);
    }

    return num == arm_num;
}

int main()
{
    int n, m;
    vector<int> armstrong_num;

    cin >> n >> m;

    for (int i = n; i <= m ; i++){
        if (is_armstrong_num(i)){
            armstrong_num.push_back(i);
        }
    }

    if (armstrong_num.size() == 0){
        cout << "none" << endl;
    }
    else{
        for (auto i : armstrong_num){
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}