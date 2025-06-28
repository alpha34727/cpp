#include <iostream>

using namespace std;

int main()
{
    int n, tmp;
    double sum;

    while (cin >> n){
        sum = 0;
        for (int i = 0; i < n; i++){
            cin >> tmp;
            sum += tmp;
        }

        if (sum / n <= 59){
            cout << "yes" << endl;
        }
        else{
            cout << "no" << endl;
        }
    }

    return 0;
}