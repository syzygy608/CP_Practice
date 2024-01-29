#ifndef Miru
#define Miru
#include Miru __FILE__ Miru

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for(auto &i : v)
        cin >> i.F >> i.S;
    ll area = 0;
    v.push_back(v[0]);
    for(int i = 0; i < n; ++i)
        area += (ll)v[i].F * v[i + 1].S - (ll)v[i].S * v[i + 1].F;
    cout << fixed << setprecision(10) << abs(area) / 2.0 << '\n';
}

int main()
{
    IO;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}

#else 

#include <bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define _ << ' ' << 
#define sz(a) ((int)(a).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
typedef long long ll;

#ifdef local
#define IO void()
#else
#define IO (*cin.tie(0)).sync_with_stdio(0);
#endif
#endif