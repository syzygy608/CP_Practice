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
    int n, k;
    cin >> n >> k;
    int ans = 0;
    int cur = 0;
    for(int i = 0; i < n; ++i)
    {
        int num;
        cin >> num;
        if(num >= k)
            cur += num;
        else if(num == 0 && cur > 0)
            ans++, cur--;

    }
    cout << ans << '\n';
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