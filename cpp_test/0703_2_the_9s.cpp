#include <iostream>
#include <string>

using namespace std;

int sum_digits(string &str_num){
    int Sum = 0;
    for (char i : str_num){
        Sum += (int)i - (int)'0';
    }
    str_num = to_string(Sum);
    return Sum;
}

int main()
{
    string input, original_input;
    int nine_degree;
    int result;

    while (cin >> input && input != "0"){
        original_input = input;
        nine_degree = 0;

        while (true){
            result = sum_digits(input);

            if (result % 9 == 0){
                nine_degree++;
            }
            else{
                break;
            }

            if (result == 9){
                break;
            }
        }

        cout << original_input << " ";
        if (nine_degree == 0){
            cout << "is not a multiple of 9." << endl;
        }
        else{
            cout <<  "is a multiple of 9 and has 9-degree " << nine_degree << "." << endl;
        }
    }

    return 0;
}