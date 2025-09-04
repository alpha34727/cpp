#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
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

struct Point{
    int x;
    int y;
};

int main()
{
    int case_count, point_count;
    int A, B, C, x0, x1, y0, y1, d;
    
    set<Line> lines;

    cin >> case_count;
    for (int c = 0; c < case_count; ++c){
        vector<Point> points;
        // unordered_set<Line> lines;

        cin >> point_count;
        points.resize(point_count);
        for (int i = 0; i < point_count; i++){
            cin >> points[i].x >> points[i].y;
        }

        for (int i = 0; i < point_count - 1; i++){
            for (int j = i; j < point_count; j++){
                x0 = points[i].x;
                y0 = points[i].y;
                x1 = points[j].x;
                y1 = points[j].y;
                A = y1 - y0;
                B = x0 - x1;
                C = x0 * y1 - x0 * y0 - x1 * y0 + x0 * y0;

                d = __gcd(__gcd(abs(A), abs(B)), abs(C));
                A /= d;
                B /= d;
                C /= d;

                // lines.insert({A, B, C});
            }
        }
        
        // cout << lines.size() << endl;
    }


    
}