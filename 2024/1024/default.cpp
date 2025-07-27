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
    vector<int> v(n), p(n);
    for(auto &i: p)
        cin >> i;
    // iota(all(v), 1);
    // do
    // {
    //     bool f = true;
    //     for(int i = 1; i <= n; ++i)
    //     {
    //         if(v[i - 1] != i && v[v[i - 1] - 1] != i)
    //         {
    //             f = false;
    //             break;
    //         }
    //     }
    //     if(f)
    //     {
    //         for(int i: v)
    //             cout << i << ' ';
    //         cout << '\n';
    //     }

    // }while(next_permutation(all(v)));
    int cnt = 0;
    for(int i = 1; i <= n; ++i)
        if(p[i - 1] != i && p[p[i - 1] - 1] != i)
            cnt++;
    if(cnt)
    {
        cnt = 0;
        for(int i = 0; i < n; ++i)
            if(p[i] != i + 1)
                cnt++;
        if(p[0] == 1)
        {
            // 1 2 4 3
            // n, n - 2, ...
            if(n & 1)
            {
                if(cnt & 1)
                    cout << "2\n";
                else
                    cout << "1\n";
            }
            else
            {
                if(cnt & 1)
                    cout << "2\n";
                else
                    cout << "1\n";
            }
        }
        else
        {
            if(n & 1)
            {
                if(cnt & 1)
                    cout << "2\n";
                else
                    cout << "1\n";
            }
            else
            {
                if(cnt & 1)
                    cout << "1\n";
                else
                    cout << "2\n";
            }
        }
    }
    else
        cout << "0\n";
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