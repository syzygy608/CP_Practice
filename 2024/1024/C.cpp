#include <bits/stdc++.h>

#define sz(a) ((int)(a).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define IO (*cin.tie(0)).sync_with_stdio(0);
using namespace std;
using ll = long long;

ll ceilDiv(ll n, ll m)
{
    return ((n >= 0) ? (n + m - 1) / m : n / m);
}

ll floorDiv(ll n, ll m)
{
    return ((n >= 0) ? n / m : (n - m + 1) / m);
}

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &i: v)
        cin >> i;
    for(int i = 0; i < n / 2; ++i)
    {
        bool f = true;
        if(i == 0)
        {
            if(v[i] == v[i + 1] || v[n - i - 1] == v[n - i - 2])
                f = false;
        }
        else
        {
            if(v[i] == v[i - 1] || v[n - i - 1] == v[n - i])
                f = false;
        }
        if(!f)
            swap(v[i], v[n - i - 1]);
    }
    int ans = 0;
    for(int i = 0; i < n - 1; ++i)
        if(v[i] == v[i + 1])
            ans++;
    cout << ans << '\n';
}

int main()
{
    IO
    cin.exceptions(cin.failbit);
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}