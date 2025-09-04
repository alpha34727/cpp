#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main()
{
    int arr_len;
    vector<int> arr;
    unordered_map<int, int> arr_set;

    while (cin >> arr_len){
        arr.clear();
        arr.resize(arr_len);
        arr_set.clear();

        for (int i = 0; i < arr.size(); i++){
            cin >> arr[i];
            if (arr_set.count(arr[i]) == 0){
                arr_set[arr[i]] = 1;
            }
            else{
                arr_set[arr[i]] += 1;
            }
        }

        sort(arr.begin(), arr.end());

        if (arr_len & 1){
            cout << arr[arr_len / 2] << " " << arr_set[arr[arr_len / 2]] << " " << 1 << endl;
        }
        else{
            int A1 = arr[arr_len / 2 - 1];
            int A2 = arr[arr_len / 2];
            cout << A1 << " ";

            if (A1 != A2){
                cout << arr_set[A1] + arr_set[A2] << " " << A2 - A1 + 1 << endl;
            }
            else{
                cout << arr_set[A1] << " " << 1 << endl;
            }
        }
    }


    return 0;
}