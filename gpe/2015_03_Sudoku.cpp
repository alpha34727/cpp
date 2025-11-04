#include <iostream>

using namespace std;

int sudoku_map[9][9];
int zero_cnt;

bool is_valid(int x, int y){
    for (int i = (x/3)*3; i < (x/3)*3+3; i++){
        for (int j = (y/3)*3; j < (y/3)*3+3; j++){
            if (sudoku_map[i][j] == sudoku_map[x][y] && (x != i && y != j)){
                return false;
            }
        }
    }
    for (int i = 0; i < 9; i++){
        if (sudoku_map[i][y] == sudoku_map[x][y] && x != i){
            return false;
        }
    }
    for (int j = 0; j < 9; j++){
        if (sudoku_map[x][j] == sudoku_map[x][y] && y != j){
            return false;
        }
    }
    return true;
}

bool is_finish(){
    return zero_cnt == 0;
}

void pprint(){
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            cout << sudoku_map[i][j] << " ";
        }
        cout << endl;
    }
}

bool solve(int sx, int sy){
    if (sx >= 9 || sy >= 9 || is_finish()){
        return false;
    }
    
    if (sudoku_map[sx][sy] != 0){
        return solve((sx+1)%9, sy + (sx+1 >= 9));
    }

    for (int i = 1; i <= 9; i++){
        sudoku_map[sx][sy] = i;
        zero_cnt--;

        if (is_valid(sx, sy)){
            if (is_finish()){
                pprint();
                return true;
            }
            if (solve((sx+1)%9, sy + (sx+1 >= 9))){
                return true;
            }
        }

        sudoku_map[sx][sy] = 0;
        zero_cnt++;
    }

    return false;
}

int main()
{
    int n;
    cin >> n;

    for (int test = 0; test < n; test++){
        zero_cnt = 0;
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                cin >> sudoku_map[i][j];
                if (sudoku_map[i][j] == 0){
                    zero_cnt++;
                }
            }
        }
        
        if (!solve(0, 0)){
            cout << "NO" << endl;
        }
    }
}