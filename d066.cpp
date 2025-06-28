#include <iostream>

using namespace std;

int main()
{
    int h, m;

    cin >> h >> m;

    if (7 * 60 + 30 <= h * 60 + m && h * 60 + m < 17 * 60 + 0){
        cout << "At School" << endl;
    }
    else{
        cout << "Off School" << endl;
    }

    return 0;
}