#include <iostream>

using namespace std;

int main()
{
    int T, n;
    bool has_negative, is_symmetric;
    long long matrix[100][100];

    cin >> T;
    for (int test = 1; test <= T; test++){
        has_negative = false;
        
        cin >> n;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                cin >> matrix[i][j];
                if (matrix[i][j] < 0){
                    has_negative = true;
                }
            }
        }

        if (has_negative){
            cout << "Test #" << test << ": Non-symmetric." << endl;
            continue;
        }

        is_symmetric = true;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n / 2; j++){
                if (matrix[i][j] != matrix[n - i - 1][n - j - 1]){
                    is_symmetric = false;
                    break;
                }
            }
        }

        if (is_symmetric){
            cout << "Test #" << test << ": Symmetric." << endl;
        }
        else{
            cout << "Test #" << test << ": Non-symmetric." << endl;
        }
    }



    return 0;
}