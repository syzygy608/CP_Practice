#include <bits/stdc++.h>

#define sz(a) ((int)(a).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define IO (*cin.tie(0)).sync_with_stdio(0);
using namespace std;
using ll = long long;
const double EPS = 1e-9;

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
    int n, k;
    cin >> n >> k;
    bool p = true;
    vector<int> factor;
    for(int i = 2; i * i <= n; ++i)
    {
        if(n % i == 0)
        {
            p = false;
            factor.push_back(i);
            if(i * i != n)
                factor.push_back(n / i);
        }
    }
    if(p)
    {
        if(k != n / 2 + 1)
            cout << "-1\n";
        else
        {
            cout << n << '\n';
            for(int i = 1; i <= n; ++i)
                cout << i << " \n"[i == n];
        }
    }
    else
    {
        sort(all(factor));
        int c = factor.back();
        vector<int> t, tt;
        if(k > n / 2 + 1 + c / 2)
            cout << "-1\n";
        else
        {
            cout << n / c << '\n';
            if(k == n / 2 + 1)
                for(int i = 0; i < n / c; ++i)
                    cout << 1 + c * i << ' ';
            else
            {
                for(int i = 0; i < n / c; ++i)
                {
                    if(i != n / c / 2 + 1)
                        cout << 1 + c * i << ' ';
                    else
                        cout << n / 2 + 1 << ' ';
                }
            }
           
            cout << '\n';
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