#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <cmath>

using namespace std;

/*

A = y1 - y0
B = x0 - x1
C = x0 * y1 - x0 * y0 - x1 * y0 + x0 * y0

Ax + By = C

*/

struct Line{
    int A;
    int B;
    int C;
};

struct LineHash{
    size_t operator()(const Line &line) const {
        return (line.A * 10007 + line.B * 101 + line.C) % sizeof(size_t);
    }
};

struct LineEqual{
    bool operator()(const Line &a, const Line &b) const {
        return a.A == b.A && a.B == b.B && a.C == b.C;
    }
};

struct Point{
    int x;
    int y;
};

int main()
{
    int case_count, point_count;
    int A, B, C, x0, x1, y0, y1, d;

    cin >> case_count;
    for (int c = 0; c < case_count; ++c){
        vector<Point> points;
        unordered_set<Line, LineHash, LineEqual> lines;

        cin >> point_count;
        points.resize(point_count);
        for (int i = 0; i < point_count; i++){
            cin >> points[i].x >> points[i].y;
        }

        for (int i = 0; i < point_count - 1; i++){
            for (int j = i + 1; j < point_count; j++){
                x0 = points[i].x;
                y0 = points[i].y;
                x1 = points[j].x;
                y1 = points[j].y;
                A = y1 - y0;
                B = x0 - x1;
                C = x0 * y1 - x0 * y0 - x1 * y0 + x0 * y0;

                d = __gcd(__gcd(abs(A), abs(B)), abs(C));

                if (A < 0){
                    d = -d;
                }

                A /= d;
                B /= d;
                C /= d;

                lines.insert({A, B, C});
            }
        }
        
        for (auto i : lines){
            cout << i.A << "x + " << i.B << "y = " << i.C << endl;
        }

        cout << lines.size() << endl;
    }


    
}