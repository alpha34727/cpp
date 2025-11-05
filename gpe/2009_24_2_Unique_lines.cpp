#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ax + by + c = 0
struct Line{
    int a;
    int b;
    int c;
};

/*
(y - y0) = m(x - x0)
(y - y0) = (y1-y0)/(x1-x0)  * (x-x0)
(y-y0) * (x1-x0) = (y1-y0) * (x-x0)
x1*y - x0*y - x1*y0 + x0*y0 = y1*x - x0*y1 - y0*x + x0*y0
(x1 - x0)y - x1*y0 + x0*y0 = (y1-y0)x - x0*y1 + x0*y0
(y0 - y1)x + (x1 - x0)y - x1*y0 + x0*y0 + x0*y1 - x0*y0 = 0

a = y0 - y1
b = x1 - x0
c = - x1*y0 + x0*y0 + x0*y1 - x0*y0

*/

void line_add(vector<Line> &lines, int a, int b, int c){
    for (int i = 0; i < lines.size(); i++){
        if (lines[i].a == a && lines[i].b == b && lines[i].c == c){
            return;
        }
    }
    lines.push_back({a, b, c});
}

int main()
{
    int N, point, a, b, c, d;

    vector<vector<int> > points;
    vector<Line> lines;

    cin >> N;
    for (int test = 0; test < N; test++){
        cin >> point;
        lines.clear();
        points.resize(2);
        points[0].resize(point);
        points[1].resize(point);
        for (int i = 0; i < point; i++){
            cin >> points[0][i] >> points[1][i];
        }

        for (int i = 0; i < point-1; i++){
            for (int j = i+1; j < point; j++){
                a = points[1][i] - points[1][j];
                b = points[0][j] - points[0][i];
                c = -points[0][j]*points[1][i] + points[0][i]*points[1][i] + points[0][i]*points[1][j] - points[0][i]*points[1][i];

                d = __gcd(__gcd(abs(a), abs(b)), abs(c));

                if (a < 0){
                    d = -d;
                }

                a /= d;
                b /= d;
                c /= d;

                line_add(lines, a, b, c);
            }
        }

        cout << lines.size() << endl;
    }


}
