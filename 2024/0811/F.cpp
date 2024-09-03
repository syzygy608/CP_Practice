#include <bits/stdc++.h>

#define X first
#define Y second
#define all(x) ((x).begin(), (x).end())
using namespace std;

using ll = long long;

void sol()
{
    int n, m;
    cin >> n >> m;
    int s, t, k;
    cin >> s >> t >> k;
    vector<vector<pair<int, int>>> adj(n);
    for(int i = 0, u, v, w; i < m; ++i)
    {
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
    }
    vector<array<ll, 2>> dist(n, {1ll<<60, k + 1});
    vector<int> pre(n, -1);
    vector<array<bool, 15>> vis(n);
    dist[s] = {0, 0};
    pre[s] = s;
    
    priority_queue<array<ll, 4>, vector<array<ll, 4>>, greater<>> pq;
    pq.emplace(0, 0, -1, 0);
    // {dist, discount_used, pre_idx, idx};
    while(!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();
        if(vis[cur[3]][cur[1]])
            continue;
        pre[cur[3]] = cur[2];
        for(auto nxt: adj[cur[3]])
        {
            if(nxt[1] + cur[0] < dist[nxt[0]])
            {
                dist[nxt[0]] = nxt[1] + cur[0];
                pq.emplace(dist[nxt[0]], cur[1], cur[3], nxt[0]);
            }
            else if()
        }

        vis[cur[3]][cur[1]] = true;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)
        sol();
}

