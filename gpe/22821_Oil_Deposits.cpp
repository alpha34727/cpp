#include <iostream>
#include <vector>

using namespace std;

int width, height, total_oil_pocket;
vector<vector<int> > grid;

void BFS(int x, int y){
    if (!(0 <= x && x < width && 0 <= y && y < height)){
        return;
    }
    // cout << x << ", " << y << " -> " << grid[x][y] << endl;
    if (grid[x][y] == -1){
        return;
    }
    if (grid[x][y] == total_oil_pocket){
        return;
    }

    grid[x][y] = total_oil_pocket;

    for (int dx = -1; dx <= 1; dx++){
        for (int dy = -1; dy <= 1; dy++){
            BFS(x + dx, y + dy);
        }
    }
}

int main()
{
    char oil_pocket;

    while (cin >> height >> width && height + width != 0){
        total_oil_pocket = 0;
        grid.clear();
        
        grid.resize(width);
        for (int i = 0; i < grid.size(); i++){
            grid[i].resize(height);
        }
        for (int i = 0; i < height; i++){
            for (int j = 0; j < width; j++){
                cin >> oil_pocket;
                if (oil_pocket == '*'){
                    grid[j][i] = -1;
                }
                else{
                    grid[j][i] = -2;
                }
            }
        }

        for (int i = 0; i < width; i++){
            for (int j = 0; j < height; j++){
                if (grid[i][j] == -2){
                    total_oil_pocket++;
                }
                BFS(i, j);
            }
        }

        // for (int i = 0; i < height; i++){
        //     for (int j = 0; j < width; j++){
        //         cout << grid[j][i] << ", ";
        //     }
        //     cout << endl;
        // }

        cout << total_oil_pocket << endl;
    }


}