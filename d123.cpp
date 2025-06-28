#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;
vector<vector<int> > check_arr;

bool is_B2_sequence(){
    // 檢查基本條件
    if (arr[0] < 1){
        return false;
    }
    for (int i = 0; i < arr.size() - 1; i++){
        if (!(arr[i] < arr[i+1])){
            return false;
        }
    }

    // 檢查 bi + bj 接不相等
    check_arr.resize(arr.size());
    for (int i = 0; i < arr.size(); i++){
        check_arr[i].resize(arr.size());
    }

    for (int i = 0; i < arr.size(); i++){
        for (int j = i; j < arr.size(); j++){
            check_arr[i][j] = arr[i] + arr[j];
        }
    }
    for (int i = 0; i < arr.size(); i++){
        for (int j = i; j < arr.size(); j++){
            for (int x = 0; x < arr.size(); x++){
                for (int y = x; y < arr.size(); y++){
                    if (check_arr[i][j] == check_arr[x][y] && i != x && j != y){
                        return false;
                    }
                }
            }
        }
    }

    return true;
}

int main()
{
    int N, case_count = 0;

    while (cin >> N){
        case_count++;

        arr.resize(N);
        for (int i = 0; i < N; i++){
            cin >> arr[i];
        }

        if (is_B2_sequence()){
            cout << "Case #" << case_count << ": It is a B2-Sequence." << endl;
        }
        else{
            cout << "Case #" << case_count << ": It is not a B2-Sequence." << endl;
        }
    }

    return 0;
}