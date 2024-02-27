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
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(auto &x : v)
        cin >> x;
    map<ll, ll> mp;
    for(int i = 0, x; i < n; ++i)
    {
        cin >> x;
        mp[abs(x)] += v[i];
    }
    ll left = 0, last = 0;
    for(auto &x : mp)
    {
        left += (x.first - last) * k;
        if(left < x.second)
        {
            cout << "NO\n";
            return;
        }
        left -= x.second;
        last = x.first;
    }
    cout << "YES\n";
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
