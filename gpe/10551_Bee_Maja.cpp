#include <iostream>

using namespace std;

struct coord{
    int x;
    int y;
};

coord dp[100000];

int main()
{
    int loop;
    int willi;

    for (int i = 0; i < 100000; i++){
        dp[i] = {10000, 10000};
    }
    dp[0] = {0, 0};
    dp[1] = {0, 0};

    while (cin >> willi){
        if (dp[willi].x != 10000 && dp[willi].y != 10000){
            cout << dp[willi].x << " " << dp[willi].y << endl;
            continue;
        }

        loop = 0;
        while (!(willi <= 3 * loop * loop + 3 * loop + 1)){
            loop++;
        }

        int x = loop, y = 0;
        int now_willi = 3 * loop * loop + 3 * loop + 1;
        for (int i = 0; i < loop * 6; i++){
            dp[willi] = {x, y};

            if (now_willi == willi){
                break;
            }

            switch (i / loop){
            case 0:
                y--;
                break;
            case 1:
                x--;
                break;
            case 2:
                x--;
                y++;
                break;
            case 3:
                y++;
                break;
            case 4:
                x++;
                break;
            case 5:
                x++;
                y--;
                break;
            default:
                break;
            }

            now_willi--;
        }

        cout << x << " " << y << endl;
    }

    return 0;
}

/*


0+6+12

1: 1 = 1 + 0*6 = 
2: 1+6 = 1 + 1*6
3: 1+6+12 = 1 + 1*6 + 2*6
4: 1+6+12+18 = 1 + 1*6 + 2*6 + 3*6

1 + (0 + n) * (n+1) / 2 * 6 = 1 + 3 * (n^2 + n) = 3n^2 + 3n + 1

n=0: 1
n=1: 7
n=2: 19
n=3: 37

3n^2 + 3n + 1

*/