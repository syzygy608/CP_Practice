#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
using ll = long long;

const double eps = 1e-8, pi = acos(-1);
struct Pt
{
    ll x, y;
    Pt (ll _x, ll _y) : x(_x), y(_y) {}
    Pt operator + (Pt o) {return Pt(x + o.x, y + o.y);}
    Pt operator - (Pt o) {return Pt(x - o.x, y - o.y);}
    Pt operator * (ll k) {return Pt(x * k, y * k);}
    Pt operator / (ll k) {return Pt (x / k, y / k);}
    ll operator * (Pt o) {return x * o.x + y * o.y;}
    ll operator ^ (Pt o) {return x * o.y - y * o.x;}
};
ll abs2(Pt o)
{
    return o.x * o.x + o.y * o.y;
}
ll abs(Pt o)
{
    return (int)sqrt(abs2(o));
}
ll polygon_area(vector<Pt> pts)
{
    ll ret = 0;
    for(int i = 0; i < pts.size(); i++)
        ret += pts[i] ^ pts[(i + 1) % pts.size()];
    return abs(ret) / 2;
}

int main()
{
    int n;
    cin >> n;
    vector<Pt> pts;
    for(int i = 0; i < n; i++)
    {
        double x, y;
        cin >> x >> y;
        pts.push_back(Pt(x, y));
    }
    ll area = polygon_area(pts);
    // Pick's theorem: A = i + b / 2 - 1
    // i = A - b / 2 + 1
    // count boundary points b
    ll b = 0;
    for(int i = 0; i < n; i++)
        b += __gcd(abs(pts[i].x - pts[(i + 1) % n].x), abs(pts[i].y - pts[(i + 1) % n].y));
    cout << area - b / 2 + 1 << ' ' << b << '\n';
    
}