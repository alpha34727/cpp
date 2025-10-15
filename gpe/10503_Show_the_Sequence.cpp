#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int N;

vector<int> seq_base(int n){
    return vector<int>(N, n);
}

vector<int> seq_add(int m, const vector<int> &seq){
    vector<int> new_seq(seq);
    new_seq[0] = m;
    for (int i = 1; i < N; i++){
        new_seq[i] = new_seq[i-1] + seq[i-1];
    }
    return new_seq;
}

vector<int> seq_multiply(int m, const vector<int> &seq){
    vector<int> new_seq(seq);
    new_seq[0] = m * seq[0];
    for (int i = 1; i < N; i++){
        new_seq[i] = new_seq[i-1] * seq[i];
    }
    return new_seq;
}

int main()
{
    string codi;
    int bracket_st;
    vector<int> seq;
    stringstream ss;
    char junk, op;
    int a;

    while (cin >> codi >> N){
        for (int i = 0; i < codi.size(); i++){
            if (codi[i] == '['){
                bracket_st = i;
            }
            if (codi[i] == ']'){
                ss.clear();
                ss << codi.substr(bracket_st, i - bracket_st + 1);
                ss >> junk >> a >> junk;
                seq = seq_base(a);

                codi.erase(codi.begin() + bracket_st, codi.begin() + i + 1);
                // cout << codi << endl;
                break;
            }
        }

        while (codi.size() > 0){
            for (int i = 0; i < codi.size(); i++){
                if (codi[i] == '['){
                    bracket_st = i;
                }
                if (codi[i] == ']'){
                    ss.clear();
                    ss << codi.substr(bracket_st, i - bracket_st + 1);
                    ss >> junk >> a >> op >> junk;

                    if (op == '+'){
                        seq = seq_add(a, seq);
                    }
                    else{
                        seq = seq_multiply(a, seq);
                    }

                    codi.erase(codi.begin() + bracket_st, codi.begin() + i + 1);
                    // cout << codi << endl;
                    break;
                }
            }
        }

        for (int i = 0; i < seq.size() - 1; i++){
            cout << seq[i] << " ";
        }
        cout << seq.back() << endl;
    }

    return 0;
}