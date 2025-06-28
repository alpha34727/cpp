#include <iostream>

using namespace std;

int main()
{
    int a, b, c, d, N, Max = 0, ratio;
    int arr[4][10];
    bool can_make;

    cin >> a >> b >> c >> d;
    cin >> N;

    for (int i = 0; i < 4; i++){
        for (int j = 0; j < N; j++){
            cin >> arr[i][j];
            if (arr[i][j] > Max){
                Max = arr[i][j];
            }
        }
    }

    for (int i = 1; i <= Max; i++){
        can_make = false;
        for (int A = 0; A < N; A++){
            for (int B = 0; B < N; B++){
                for (int C = 0; C < N; C++){
                    for (int D = 0; D < N; D++){
                        if (arr[0][A] == i * a &&
                            arr[1][B] == i * b &&
                            arr[2][C] == i * c &&
                            arr[3][D] == i * d){
                            ratio = i;
                            can_make = true;
                            break;
                        }
                    }
                    if (can_make) break;
                }
                if (can_make) break;
            }
            if (can_make) break;
        }
        if (can_make) break;
    }

    if (can_make){
        cout << ratio * a << " " << ratio * b << " " << ratio * c << " " << ratio * d << endl; 
    }
    else{
        cout << -1 << endl;
    }

    return 0;
}