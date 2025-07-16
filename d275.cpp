#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n, M_cnt, F_cnt;
    string str;

    cin >> n;
    cin.ignore();

    for (int test = 0; test < n; test++){
        getline(cin, str);

        if (str.length() <= 2){
            cout << "NO LOOP" << endl;
            continue; 
        }

        M_cnt = F_cnt = 0;
        for (auto c : str){
            if (c == 'M'){
                M_cnt++;
            }
            else if (c == 'F'){
                F_cnt++;
            }
        }

        if (M_cnt == F_cnt){
            cout << "LOOP" << endl;
        }
        else{
            cout << "NO LOOP" << endl;
        }
    }

}