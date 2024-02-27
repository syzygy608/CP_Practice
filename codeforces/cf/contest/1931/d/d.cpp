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
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> v(n);
    map<int, map<int, int>> mp;
    ll ans = 0;
    for(int &i: v)
    {
        cin >> i;
        int a = i % x, b = i % y;
        if(a == 0)
            a = x;
        ans += mp[b][x - a];
        if(a == x)
            a = 0;
        mp[b][a]++;
    }
    cout << ans << '\n';
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
