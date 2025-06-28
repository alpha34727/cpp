#include <iostream>

using namespace std;

int c_question[13] = {};

int main()
{
    int S, tmp, sum, case_count = 1;

    while (cin >> S && S >= 0){
        cout << "Case "<< case_count << ":" << endl;

        sum = S;
        c_question[1] = S;
        for (int i = 2; i <= 12; i++){
            cin >> tmp;
            sum += tmp;

            c_question[i] = sum;
        }
        cin >> tmp;

        for (int i = 1; i <= 12; i++){
            cin >> tmp;

            if (tmp > c_question[i]){
                cout << "No problem. :(" << endl;
            }
            else{
                for (int j = i; j <= 12; j++){
                    c_question[j] -= tmp;
                }
                cout << "No problem! :D" << endl;
            }
        }

        case_count++;
    }

    return 0;
}