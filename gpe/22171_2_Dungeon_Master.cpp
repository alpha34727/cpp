#include <iostream>
#include <queue>

using namespace std;

struct Point{
    char type;
    bool visited;
    int price;
};

struct pt{
    int x, y, z;
};

int L, R, C;
Point Map[30][30][30];

bool is_visited(int x, int y, int z){
    if ((!(0 <= x && x < L)) || (!((0 <= y && y < R))) || (!((0 <= z && z < C)))){
        return true;
    }
    if (Map[x][y][z].visited){
        return true;
    }
    if (Map[x][y][z].type == '#'){
        return true;
    }
    return false;
}

int BFS(int sx, int sy, int sz){
    queue<pt> q;
    pt np;
    q.push({sx, sy, sz});
    Map[sx][sy][sz].visited = true;

    while (q.size() > 0){
        np = q.front();
        q.pop();

        if (Map[np.x][np.y][np.z].type == 'E'){
            return Map[np.x][np.y][np.z].price;
        }

        if (!is_visited(np.x+1, np.y, np.z)){
            q.push({np.x+1, np.y, np.z});
            Map[np.x+1][np.y][np.z].visited = true;
            Map[np.x+1][np.y][np.z].price = Map[np.x][np.y][np.z].price + 1;
        }
        if (!is_visited(np.x-1, np.y, np.z)){
            q.push({np.x-1, np.y, np.z});
            Map[np.x-1][np.y][np.z].visited = true;
            Map[np.x-1][np.y][np.z].price = Map[np.x][np.y][np.z].price + 1;
        }
        if (!is_visited(np.x, np.y+1, np.z)){
            q.push({np.x, np.y+1, np.z});
            Map[np.x][np.y+1][np.z].visited = true;
            Map[np.x][np.y+1][np.z].price = Map[np.x][np.y][np.z].price + 1;
        }
        if (!is_visited(np.x, np.y-1, np.z)){
            q.push({np.x, np.y-1, np.z});
            Map[np.x][np.y-1][np.z].visited = true;
            Map[np.x][np.y-1][np.z].price = Map[np.x][np.y][np.z].price + 1;
        }
        if (!is_visited(np.x, np.y, np.z+1)){
            q.push({np.x, np.y, np.z+1});
            Map[np.x][np.y][np.z+1].visited = true;
            Map[np.x][np.y][np.z+1].price = Map[np.x][np.y][np.z].price + 1;
        }
        if (!is_visited(np.x, np.y, np.z-1)){
            q.push({np.x, np.y, np.z-1});
            Map[np.x][np.y][np.z-1].visited = true;
            Map[np.x][np.y][np.z-1].price = Map[np.x][np.y][np.z].price + 1;
        }
    }

    return -1;
}

int main()
{
    int ans;
    char a;
    int sx, sy, sz;

    cin.tie(0);
    ios_base::sync_with_stdio(0);

    while (cin >> L >> R >> C && L + R + C != 0){
        for (int x = 0; x < L; x++){
            for (int y = 0; y < R; y++){
                for (int z = 0; z < C; z++){
                    cin >> a;

                    Map[x][y][z] = {a, false, 0};
                    if (a == 'S'){
                        sx = x;
                        sy = y;
                        sz = z;
                    }
                }
            }
        }

        ans = BFS(sx, sy, sz);
        if (ans == -1){
            cout << "Trapped!" << endl;
        }
        else{
            cout << "Escaped in " << ans << " minute(s)." << endl;
        }
    }
}
