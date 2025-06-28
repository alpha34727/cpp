#include <iostream>
#include <vector>

using namespace std;

int Sum(vector<int> &arr){
    int sum = 0;
    for (auto i:arr){
        sum += i;
    }
    return sum;
}

int main()
{
    int n, sum, avg, moves, set_cnt = 1;
    vector<int> blocks;

    while (cin >> n && n != 0){
        blocks.clear();
        blocks.resize(n);
        for (int i = 0; i < n; i++){
            cin >> blocks[i];
        }

        sum = Sum(blocks);
        avg = sum / n;

        moves = 0;
        for (auto i:blocks){
            if (i > avg){
                moves += i - avg; 
            }
        }
        
        cout << "Set #" << set_cnt << endl;
        cout << "The minimum number of moves is " << moves << "." << endl << endl;

        set_cnt++;
    }

    return 0;
}