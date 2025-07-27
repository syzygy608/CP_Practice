#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define all(x) (x).begin(), (x).end()
#define F first
#define S second

void solve()
{
    int n;
    cin >> n;
    map<int, int> mp;
    auto dfs = [&](auto &&self, int B, int N) -> int
    {
        if(mp.find(N) != mp.end())
            return mp[N];
        vector<bool> vis(1000);
        if(B == 1)
        {
            int mex = self(self, B, N - 1);
            if(mex < 1000)
                vis[mex] = true;
        }
        i64 base = 1;
        while(base <= N)
        {
            int mex = self(self, B, N - base);
            if(mex < 1000)
                vis[mex] = true;
            base *= B;
        }
        for(int i = 0; i < 1000; ++i)
            if(!vis[i])
                return mp[i] = i;
    };
    int ans = 0;
    while(n--)
    {
        int a, b;
        cin >> a >> b;
        if(a % 2 == 0)
        {
            // 1, 2, 0
            // 1, 2, 0, 1, 0
            // 1, 2, 0, 1, 0, 1, 0
            if(b < a)
                ans ^= (b & 1);
            else
            {
                b -= a;
                b %= (a + 1);
                if(!b)
                    ans ^= 2;
                else
                    ans ^= ((b & 1) ^ 1);
            }
        }
        else
            ans ^= (b & 1);
    }
    cout << ((ans) ? 1 : 2) << '\n';
}

int main()
{
    freopen("powers.in", "r", stdin);
    (cin.tie(0))->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}