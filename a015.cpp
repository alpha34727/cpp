#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > arr;

int main()
{
    int m, n;

    while (cin >> m >> n){
        arr.resize(m);
        for (int i = 0; i < m; i++){
            arr[i].resize(n);
            for (int j = 0; j < n; j++){
                cin >> arr[i][j];
            }
        }

        for (int j = 0; j < n; j++){
            for (int i = 0; i < m; i++){
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
        arr.clear();
    }

    return 0;
}