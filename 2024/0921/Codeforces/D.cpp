#include <bits/stdc++.h>

#define sz(a) ((int)(a).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define IO (*cin.tie(0)).sync_with_stdio(0);
using namespace std;
using ll = long long;

ll ceilDiv(ll n, ll m)
{
    if(n >= 0)
        return (n + m - 1) / m;
    else
        return n / m;
}

ll floorDiv(ll n, ll m)
{
    if(n >= 0)
        return n / m;
    else 
        return (n - m + 1) / m;
}

void sol()
{
    /*
        0 0 0 0 0 
        0 1 1 1 1
          1 0 0 0 -1

    */

    int n, d, k;
    cin >> n >> d >> k;
    vector<int> v;
    for(int i = 0, L, R; i < k; ++i)
    {
        cin >> L >> R;
        v.push_back(L);
        v.push_back(R);
    }
    sort(all(v));
    for(auto el: v)
        cout << el << ' ';
    cout << '\n';
    cout << '\n';
    int cur = 0, mx = -1, mn = 1<<30, ans1 = 1<<30, ans2 = 1<<30;
    for(int i = 1; i <= n - d + 1; ++i)
    {
        auto L = lower_bound(all(v), i);
        auto R = upper_bound(all(v), i + d - 1);
        cerr << R - L << '\n';
        if(R - L > mx)
        {
            mx = R - L;
            ans1 = i;
        }
        if(R - L < mn)
        {
            mn = R - L;
            ans2 = i;
        }
    }
    cout << ans1 << ' ' << ans2 << '\n';
    
}

int main()
{
    IO
    cin.exceptions(cin.failbit);
    int t;
    cin >> t;
    while(t--)
        sol();
    return 0;
}