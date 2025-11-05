#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class DisjointSet{
    private:
        vector<int> parent;
        vector<int> rank;
    
    public:
        DisjointSet(){};

        void init(int n){
            parent.resize(n);
            rank.resize(n);

            for (int i = 0; i < n; i++){
                parent[i] = i;
                rank[i] = 0;
            }
        }

        int find(int n){
            if (parent[n] != n){
                parent[n] = find(parent[n]);
            }

            return parent[n];
        }

        void Union(int a, int b){
            int root1 = find(a);
            int root2 = find(b);

            // cout << "Union: " << a << ", " << b << ", r1 = " << root1 << ", r2 = " << root2 << endl;

            if (root1 == root2){
                return;
            }

            if (rank[root1] > rank[root2]){
                parent[root2] = root1;
            }
            else if (rank[root1] < rank[root2]){
                parent[root1] = root2;
            }
            else{
                parent[root2] = root1;
                rank[root1]++;
            }
        }

        bool is_union(int a, int b){
            return find(a) == find(b);
        }
};

int main()
{
    DisjointSet computer;

    int total_test;
    string line;
    char cmd;
    int a, b;

    cin >> total_test;

    for (int test = 0; test < total_test; test++){
        int success = 0, failed = 0, total_computer;

        cin >> total_computer;
        cin.ignore();
        computer.init(total_computer+1);

        while (getline(cin, line) && line != ""){
            stringstream ss;
            ss << line;
            ss >> cmd >> a >> b;

            if (cmd == 'c'){
                computer.Union(a, b);
            }
            else{
                if (computer.is_union(a, b)){
                    success++;
                }
                else{
                    failed++;
                }
            }
        }

        cout << success << "," << failed << endl;
        if (test != total_test - 1){
            cout << endl;
        }
    }
}