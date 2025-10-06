#include <iostream>
#include <deque>

using namespace std;

bool graph[6][6] = {{false, true, true, false, false, true},
                    {true, false, false, true, true, false},
                    {true, false, false, true, true, false},
                    {false, true, true, false, false, true},
                    {false, true, true, false, false, true},
                    {true, false, false, true, true, false}};

bool is_visited[6];

deque<int> path;

void print_path(){
    cout << path[0];
    if (path.size() > 1){
        for (int i = 1; i < path.size(); i++){
            cout << " -> " << path[i];
        }
    }
    cout << endl;
}

int DFS(int st, int target){
    int min_path = 99999, tmp;
    is_visited[st] = true;
    path.push_back(st);

    if (st == target){
        // print_path();
        int path_len = path.size();
        is_visited[st] = false;
        path.pop_back();
        return path_len;
    }

    for (int i = 0; i < 6; i++){
        if (graph[st][i] && !is_visited[i]){
            tmp = DFS(i, target);
            if (min_path > tmp){
                min_path = tmp;
            }
        }
    }

    is_visited[st] = false;
    path.pop_back();

    return min_path;
}

int main()
{
    for (int i = 0; i < 6; i++){
        is_visited[i] = false;
    }

    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 6; j++){
            cout << DFS(i, j) << ", ";
        }
        cout << endl;
    }


}