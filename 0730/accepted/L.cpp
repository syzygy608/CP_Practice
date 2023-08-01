#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define _ << ' ' << 
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define IO (*cin.tie(0)).sync_with_stdio(0);

using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;

int main()
{
    IO
    double x[2], y[2], r[2];
    for(int i = 0; i < 2; ++i)
        cin >> x[i] >> y[i] >> r[i];
    double ad = sqrt((x[0] - x[1]) * (x[0] - x[1]) + (y[0] - y[1]) * (y[0] - y[1]));
    double ansr = (r[0] + r[1] - ad) / 2.0;
    double ar = ad - r[1] + ansr;
    double ansy = y[0] + (y[1] - y[0]) * ar / ad;
    double ansx = x[0] + (x[1] - x[0]) * ar / ad;
    cout << fixed << setprecision(12) << ansx << ' ' << ansy << ' ' << ansr << '\n';
    return 0;
}