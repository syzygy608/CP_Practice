#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define _ << ' ' << 
#define sz(a) ((int)(a).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define IO (*cin.tie(0)).sync_with_stdio(0);

using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;

void solve()
{
    int n;
    cin >> n;
    vector<ll> v(n);
    for(auto &iz: v)
        cin >> iz;
    sort(all(v));
    cout << abs(v[n - 1] - v[0]) + abs(v[0] - v[n - 2]) + abs(v[n - 2] - v[1]) + abs(v[1] - v[n - 1]) << '\n';
}

int main()
{
    IO;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
