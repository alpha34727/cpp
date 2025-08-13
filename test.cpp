#include <iostream>
#include <bitset>

using namespace std;

char get_operator(int op) {
    switch (op) {
        case 0: return '+';
        case 1: return '-';
        case 2: return '*';
        case 3: return '/';
        default: return '?'; // Invalid operator
    }
}

int main() {
    int operand;

    for (int op1 = 0; op1 < 4; op1++) {
        for (int op2 = 0; op2 < 4; op2++) {
            for (int op3 = 0; op3 < 4; op3++) {
                operand = (op1 << 4) | (op2 << 2) | op3;
                bitset<6> x(operand);
                cout << "case 0b" << x << ":" << endl;
                cout << "    return" << " c1 " << get_operator(op1) << " c2 " 
                     << get_operator(op2) << " c3 " 
                     << get_operator(op3) << " c4;" << endl;
            }
        }
    }
}