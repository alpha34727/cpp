#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

struct Node{
    string key;
    vector<int> child;
    unordered_map<string, int> key_to_index;
};

vector<Node> Tree;

string phrase_path(string &path){
    string tmp;
    for (int i = 0; i < path.length(); ++i){
        if (path[i] == '\\'){
            tmp = path.substr(0, i);
            path = path.substr(i + 1, path.size() - (i + 1));
            return tmp;
        }
    }
    tmp = path;
    path = "";
    return tmp;
}

void make_node(string &input_path){
    int now_index = 0;
    string folder = phrase_path(input_path);

    while (folder != ""){
        // cout << "now at: " << folder << ",   " << input_path << endl;

        auto it = Tree[now_index].key_to_index.find(folder);
        if (it == Tree[now_index].key_to_index.end()){
            // cout << "not found: " << folder << endl;

            bool is_inserted = false;
            for (int i = 0; i < Tree[now_index].child.size(); ++i){
                if (Tree[Tree[now_index].child[i]].key > folder){
                    Tree[now_index].child.insert(Tree[now_index].child.begin() + i, Tree.size());
                    is_inserted = true;
                    break;
                }
            }
            if (!is_inserted){
                Tree[now_index].child.push_back(Tree.size());
            }

            Tree[now_index].key_to_index[folder] = Tree.size();
            Tree.push_back({folder, vector<int>(0), unordered_map<string, int>()});
        }
        now_index = Tree[now_index].key_to_index[folder];

        folder = phrase_path(input_path);
    }
}

void visit_tree(int st = 0, int depth = 0){
    if (Tree[st].child.size() <= 0){
        return;
    }

    for (int i = 0; i < Tree[st].child.size(); i++){
        for (int s = 0; s < depth; ++s){
            cout << " ";
        }
        cout << Tree[Tree[st].child[i]].key << endl;
        visit_tree(Tree[st].child[i], depth + 1);
    }
}

int main()
{
    int path_count;
    string path;

    while (cin >> path_count){
        Tree.clear();

        Tree.push_back({"", vector<int>(0), unordered_map<string, int>()});
        for (int i = 0; i < path_count; ++i){
            cin >> path;
            make_node(path);
        }

        visit_tree();

        cout << endl;
    }

    return 0;
}