#include <iostream>

using namespace std;

int main()
{
    int a, b, nxt;
    int carry_operation;

    while (cin >> a >> b && a != 0 && b != 0){
        carry_operation = 0;
        nxt = 0;
        for (int i = 0; i < 10; i++){
            nxt = (a % 10 + b % 10 + nxt) / 10;
            if (nxt >= 1){
                carry_operation++;
            }

            a /= 10;
            b /= 10;
        }

        if (carry_operation == 0){
            cout << "No carry operation." << endl;
        }
        else if (carry_operation == 1){
            cout << "1 carry operation." << endl;
        }
        else{
            cout << carry_operation << " carry operations." << endl;
        }
    }

    return 0;
}