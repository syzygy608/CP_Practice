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
    int cur = 0;
    for(int i = 1; i <= 200; ++i)
    {
        if(i & 1)
            cur -= (2 * i - 1);
        else
            cur += (2 * i - 1);
        if(abs(cur) >= n)
        {
            if(i % 2 == 1)
                cout << "Kosuke\n";
            else
                cout << "Sakurako\n";
            break;
        }
    }
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