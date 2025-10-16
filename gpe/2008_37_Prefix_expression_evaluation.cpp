#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int isNum(string &s){
    bool isNumeric = true;
    for (auto c : s){
        if (!('0' <= c && c <= '9')){
            isNumeric = false;
            return -1;
        }
    }
    return stoi(s);
}

char isOp(string &s){
    if (s == "-"){
        return '-';
    }
    else if (s == "+"){
        return '+';
    }
    else if (s == "*"){
        return '*';
    }
    else if (s == "/"){
        return '/';
    }
    else if (s == "%"){
        return '%';
    }
    else{
        return 'x';
    }
}

int main()
{
    string lines, token;
    while (getline(cin, lines) && lines != "."){
        stringstream ss(lines);
        vector<string> tokens;
        stack<int> num_stk;

        while (ss >> token){
            tokens.push_back(token);
        }

        bool isIllegal = false;
        for (int i = tokens.size() - 1; i >= 0; i--){
            int num = isNum(tokens[i]);
            char op;
            if (num != -1){ // number
                num_stk.push(num);
            }
            else{ 
                op = isOp(tokens[i]);
                if (op != 'x'){  // operator
                    if (num_stk.size() >= 2){
                        int a = num_stk.top();
                        num_stk.pop();
                        int b = num_stk.top();
                        num_stk.pop();

                        switch (op){
                            case '-':
                                num_stk.push(a - b);
                                break;
                            case '+':
                                num_stk.push(a + b);
                                break;
                            case '*':
                                num_stk.push(a * b);
                                break;
                            case '/':
                                num_stk.push(a / b);
                                break;
                            case '%':
                                num_stk.push(a % b);
                                break;
                            default:
                                break;
                        }
                    }
                    else{
                        isIllegal = true;
                        break;
                    }
                }
                else{  // error
                    isIllegal = true;
                    break;
                }
            }
        }

        if (num_stk.size() != 1){
            isIllegal = true;
        }

        if (isIllegal){
            cout << "illegal" << endl;
        }
        else{
            cout << num_stk.top() << endl;
        }
    }
}

/*

- 1 * 4 3

- * + 23 % 45 10 6 / 77 12
        ^
stack: ((45%10)+23)*6-(77/12)

*/