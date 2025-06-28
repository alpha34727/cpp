#include <iostream>

using namespace std;

int main()
{
    int st_cnt, st1, st2, st3;

    cin >> st_cnt >> st1 >> st2 >> st3;

    for (int i = st_cnt; i >= 1; i--){
        if (i == st1 || i == st2 || i == st3){
            continue;
        }
        cout << "No. " << i << endl;
    }

    return 0;
}