#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> history;

int main()
{
    int total_case, instructions, target, pos;
    string command;
    cin >> total_case;

    for (int test = 0; test < total_case; test++){
        cin >> instructions;

        pos = 0;
        history.clear();
        history.resize(instructions);

        for (int instruction = 0; instruction < instructions; instruction++){
            cin >> command;
            if (command == "LEFT"){
                pos -= 1;
                history[instruction] = -1;
            }
            else if (command == "RIGHT"){
                pos += 1;
                history[instruction] = 1;
            }
            else{
                cin >> command >> target;
                pos += history[target - 1];
                history[instruction] = history[target - 1];
            }
        }

        cout << pos << endl;
    }


}