#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;

bool cmp(int a, int b){
    int mod_a = a % M;
    int mod_b = b % M;

    if (mod_a != mod_b){
        return mod_a < mod_b;
    }
    
    if (a & 1){
        if (b & 1){
            return a > b;
        }
        else{
            return true;
        }
    }
    else{
        if (b & 1){
            return false;
        }
        else{
            return a < b;
        }
    }
}

int main()
{
    vector<int> arr;

    while (cin >> N >> M && (N != 0 && M != 0)){
        arr.clear();
        arr.resize(N);
        for (int i = 0; i < N; i++){
            cin >> arr[i];
        }

        sort(arr.begin(), arr.end(), cmp);

        cout << N << " " << M << endl;
        for (int i = 0; i < N; i++){
            cout << arr[i] << endl;
        }
    }

    cout << "0 0" << endl;

    return 0;
}