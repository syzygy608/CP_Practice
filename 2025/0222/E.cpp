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
    vector adj(n, vector<int>());
    for(int i = 0, x; i < n; ++i)
    {
        cin >> x;
        if(i + x <= n - 1)
            adj[i + x].emplace_back(i);
        if(i - x >= 0)
            adj[i - x].emplace_back(i);
    }
    queue<int> q;
    vector<int> dis(n, -1);
    auto bfs = [&](int st, vector<vector<int>> &adj, vector<int> &d) -> void
    {
        queue<int> q;
        q.push(st);
        d[st] = 0;
        while(!q.empty())
        {
            int f = q.front();
            q.pop();
            for(int i: adj[f])
            {
                if(!~d[i])
                {
                    d[i] = d[f] + 1;
                    q.push(i);
                }
            }
        }
    };
    bfs(n - 1, adj, dis);
    for(int i = 0; i < n; ++i)
        cout << dis[i] << '\n';
}

int main()
{
    freopen("jumping.in", "r", stdin);
    (cin.tie(0))->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}