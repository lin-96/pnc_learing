/*
 * @Author: chenlin325
 * @Date: 2022-10-01 20:50:41
 * @FilePath: /pnc_learing/cpp_bezier/src/cpp_bezier.cpp
 */
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
    vector<double> control_x, control_y, bezier_x, bezier_y;
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
        bezier_x.push_back(ans.x);
        bezier_y.push_back(ans.y);

        control_x.push_back(i);
        control_y.push_back((i <= 25.0) ? -2.0 : 2.0);
    }

    plt::xlim(0, 50);
    plt::ylim(-3, 3);
    for(int k=0; k<vp.size()-1; k++) {
        plt::annotate("P" + to_string(k), vp[k].x + 0.1, vp[k].y - 0.2);
    }
    plt::annotate("P4", vp.back().x - 1.5, vp.back().y - 0.2);
    plt::annotate("Bezier curve", 33.0, 0.4);
    plt::title("Bezier change lane");
    plt::arrow(37.1, 0.54, 0.0, 0.7);
    plt::plot(control_x, control_y);
    plt::plot(bezier_x, bezier_y, "r--");
    plt::show();
}
