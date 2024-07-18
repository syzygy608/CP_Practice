#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const double eps = 1e-8, pi = acos(-1);
using Point = pair<double, double>;
#define x first
#define y second
double dis_p(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
struct Circle {
    Point p;
    double r;
    double dis(Point a) {
        return dis_p(a, p) + r;
    }
    Circle(Point _p, double _r) {
        p = _p;
        r = _r;
    }
};
 
double rad(double x, double y, vector<Circle> &circle) {
    double mx = 0;
    for(auto c : circle) {
        mx = max(mx, c.dis({x, y}));
    }
    return mx;
}

double search_y(double x, vector<Circle> &circle) {
    double l = -1000000, r = 1000000;
    ll times = 100;
 
    while(times--) {
        double a = (2 * l + r) / 3;
        double b = (l + 2 * r) / 3;
 
        if(rad(x, a, circle) < rad(x, b, circle))
            r = b;
        else
            l = a;
    }
    return l;
}

pair<double, double> min_enclose_circle(vector<Circle> &circle) {
    double l = -1000000, r = 1000000;
    ll times = 100;
 
    while(times--) {
        double a = (2 * l + r) / 3;
        double b = (l + 2 * r) / 3;
 
        if(rad(a, search_y(a, circle), circle) < rad(b, search_y(b, circle), circle))
            r = b;
        else
            l = a;
    }
    return {l, search_y(l, circle)};
}

int main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ifstream cin("robots.in");
    int t;
    cin >> t;
    while(t--)
    {
        int n, R, r;
        cin >> n >> R >> r;
        vector<Circle> circle;
        circle.push_back(Circle({0, 0}, r));
        double x = 0, y = 0;
        for(int i = 0; i < n; ++i)
        {
            double dx, dy;
            cin >> dx >> dy;
            x += dx;
            y += dy;
            circle.push_back(Circle({x, y}, r));
        }
        auto c = min_enclose_circle(circle);
        cout << fixed << setprecision(10) << -c.first << ' ' << -c.second << '\n';
    }
    return 0;
}