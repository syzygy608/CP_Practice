#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define eb emplace_back
using namespace std;
using ll = long long;
const int INF = numeric_limits<int>::max() / 2;
const ll LINF = numeric_limits<ll>::max() / 2;

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n, vector<int>());
    vector<int> ind(n);
    for(int i = 0, x; i < n; ++i)
    {
        cin >> x;
        x--;
        ind[x]++;
        adj[i].eb(x);
    }
    queue<int> q;
    int ans = 2;
    vector<int> dp(n, 0);
    for(int i = 0; i < n; ++i)
    {
        if(!ind[i])
        {
            dp[i] = 1;
            q.push(i);
        }
    }
    while(!q.empty())
    {
        int f = q.front();
        q.pop();
        for(int nxt: adj[f])
        {
            if(!--ind[nxt])
            {
                dp[nxt] = max(dp[nxt], dp[f] + 1);
                q.push(nxt);
            }

        }
    }
    cout << ans + *max_element(all(dp)) << '\n';
}

int main()
{
    (*cin.tie(0)).sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}