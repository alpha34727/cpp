#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node{
    char type;
    bool visited;
};

struct Point{
    int x, y, z;
    int price;
};

int L, R, C, path_len;
Node Map[30][30][30];

inline bool is_free(int x, int y, int z){
    if (0 <= x && x < L && 0 <= y && y < R && 0 <= z && z < C && Map[x][y][z].type != '#' && !Map[x][y][z].visited){
        Map[x][y][z].visited = true;
        return true;
    }
    return false;
}

void BFS(Point &st){
    Point np;
    queue<Point> q;
    q.push(st);
    Map[st.x][st.y][st.z].visited = true;

    while (q.size() > 0){
        np = q.front();
        q.pop();

        if (Map[np.x][np.y][np.z].type == 'E'){
            path_len = np.price;
            return;
        }

        if (is_free(np.x-1, np.y, np.z)){
            q.push({np.x-1, np.y, np.z, np.price+1});
        }
        if (is_free(np.x+1, np.y, np.z)){
            q.push({np.x+1, np.y, np.z, np.price+1});
        }
        if (is_free(np.x, np.y-1, np.z)){
            q.push({np.x, np.y-1, np.z, np.price+1});
        }
        if (is_free(np.x, np.y+1, np.z)){
            q.push({np.x, np.y+1, np.z, np.price+1});
        }
        if (is_free(np.x, np.y, np.z-1)){
            q.push({np.x, np.y, np.z-1, np.price+1});
        }
        if (is_free(np.x, np.y, np.z+1)){
            q.push({np.x, np.y, np.z+1, np.price+1});
        }
    }
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    Point st;
    while (cin >> L >> R >> C && L + R + C != 0){
        path_len = -1;
        for (int i = 0; i < L; i++){
            for (int j = 0; j < R; j++){
                for (int k = 0; k < C; k++){
                    cin >> Map[i][j][k].type;
                    Map[i][j][k].visited = false;
                    if (Map[i][j][k].type == 'S'){
                        st = {i, j, k, 0};
                    }
                }
            }
        }
        

        BFS(st);
        if (path_len != -1){
            cout << "Escaped in " << path_len << " minute(s)." << endl;
        }
        else{
            cout << "Trapped!" << endl;
        }
    }
}