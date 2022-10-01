#include <iostream>
#include <vector>
#include <algorithm>

#include "matplotlib-cpp/matplotlibcpp.h"

namespace plt = matplotlibcpp;
using namespace std; 

struct Point {
    double x;
    double y;
};

inline int Cni(int n, int i) {
    int numerator = 1, denominator = 1;
    while(i) {
        denominator *= n--;
        numerator *= i--;
    }
    return denominator / numerator;
};

inline double Bint(double t, int i, int n) {
    return Cni(n, i) * pow(1 - t, n - i) * pow(t, i);
}

int main() {
    vector<double> x0, y0, x1, y1;
    Point p0 = {0.0, -2.0}, p1 = {25.0, -2.0}, p2 = {25.0, 2.0}, p3 = {50.0, 2.0};
    vector<Point> vp = {p0, p1, p2, p3};

    auto pn = [](double t, vector<Point> &vp) ->Point {
        Point ret = {0.0, 0.0};
        int n = vp.size()-1;
        for(int i=0; i<=n; i++) {
            ret.x += Bint(t, i, n) * vp[i].x;
            ret.y += Bint(t, i, n) * vp[i].y;
        }
        return ret;
    };

    for(double i=0.0; i<=50.0; i+=0.01) {
        Point ans = pn(i, vp);
        x1.push_back(ans.x);
        y1.push_back(ans.y);

        x0.push_back(i);
        y0.push_back((i <= 25.0) ? -2.0 : 2.0);
    }

    plt::xlim(0, 50);
    plt::ylim(-3, 3);
    plt::title("Bezier change lane");
    plt::plot(x0, y0);
    plt::plot(x1, y1, "r--");
    plt::show();
}
