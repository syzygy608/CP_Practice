#include <bits/stdc++.h>

#define show(x) cerr << "\n" << (#x) << " is " << (x) << endl
#define sz(a) ((int)size((a)))
#define all(x) begin((x)), end((x))
using namespace std;
using ll = long long;

constexpr int INF = numeric_limits<int>::max() / 2;
constexpr int MOD = 1e9 + 7;

#define _T double
const double eps = 1e-8, pi = acos(-1);

struct Pt
{
    _T x, y;
    Pt() : x(0), y(0) {}
    Pt(_T _x, _T _y) : x(_x), y(_y) {}
    Pt operator + (const Pt &o) const {return Pt(x + o.x, y + o.y);}
    Pt operator - (const Pt &o) const {return Pt(x - o.x, y - o.y);}
    Pt operator * (_T k) const {return Pt(x * k, y * k);}
    Pt operator / (_T k) const {return Pt(x / k, y / k);}
    _T operator * (const Pt &o) const {return x * o.x + y * o.y;}
    _T operator ^ (const Pt &o) const {return x * o.y - y * o.x;}
    bool operator < (const Pt &o) const {
        return x < o.x || (x == o.x && y < o.y);}
    bool operator == (const Pt &o) const {return x == o.x && y == o.y;}
};

double polygon_area(vector<Pt> pts)
{
    double ret = 0;
    for(int i = 0; i < pts.size(); i++)
        ret += pts[i] ^ pts[(i + 1) % pts.size()];
    return abs(ret) / 2;
}

void solve()
{
	int n;
	cin >> n;
	vector<Pt> v;
	double x, y;
	for(int i = 0; i < n; ++i)
	{
		cin >> x >> y;
		v.push_back(Pt(x, y));
	}
	cout << fixed << setprecision(10) << polygon_area(v) / n << '\n';
}

int main()
{
	(*cin.tie(0)).sync_with_stdio(0);
	int t = 1;
	// cin >> t;
	while(t--)
		solve();
	return 0;
}