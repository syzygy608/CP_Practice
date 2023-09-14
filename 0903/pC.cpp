#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define _ << ' ' << 
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define IO (*cin.tie(0)).sync_with_stdio(0);

using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;

struct Edge
{
   ll v, weight;
};
vector<Edge> adj[maxn];
int in[maxn];
int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0, u, v, w; i < m; ++i)
    {
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        in[v]++;
    }
    ll ans = -1e18;
    for(int i = 1; i <= n; ++i)
    {
        if(in[i] == 0)
        {
            priority_queue<pair<ll, int>, vector<pair<ll, int>>> pq;
            vector<ll> dis(n + 1, -1e18);
            dis[i] = 0;
            pq.push({0, i});
            while(!pq.empty())
            {
                auto [w, u] = pq.top();
                pq.pop();
                if(w < dis[u])
                    continue;
                for(auto [v, weight] : adj[u])
                {
                    if(dis[v] < dis[u] + weight)
                    {
                        dis[v] = dis[u] + weight;
                        pq.push({dis[v], v});
                    }
                }
            }
            for(int i = 1; i <= n; ++i)
                if(dis[i] != -1e18)
                    ans = max(ans, dis[i]);
        }
    }
    cout << ans << '\n';
    return 0;
}