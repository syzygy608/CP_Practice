#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define all(x) (x).begin(), (x).end()
#define F first
#define S second

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> v;
    int t = n, cur = 0;
    if(t != 1)
    {
        v.push_back(0);
        t--;
    }

    for(int i = 1; i < n; ++i)
    {
        if((i | x) == x && t > 0)
        {
            if(t == 1 && cur != x)
            {
                t--;
                v.push_back(cur ^ x);
                break;
            }
            cur |= i;
            v.push_back(i);
            t--;
        }
        else
            break;
    }
    while(t)
    {
        v.push_back(cur ^ x);
        t--;
    }
    for(int i = 0; i < n; ++i)
        cout << v[i] << " \n"[i == n - 1];
}

int main()
{
    (cin.tie(0))->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}