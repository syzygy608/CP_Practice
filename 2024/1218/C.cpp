#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define eb emplace_back
using namespace std;
using ll = long long;
const int INF = numeric_limits<int>::max() / 2;
const ll LINF = numeric_limits<ll>::max() / 2;

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> brand(n), sum(n);
    vector<set<int>> adj(n);
    set<pair<int, int>> s[n];
    for(int i = 0; i < n; ++i)
    {
        cin >> brand[i];
        brand[i]--;
    }
    for(int i = 0, u, v; i < m; ++i)
    {
        cin >> u >> v;
        u--;
        v--;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    vector<int> dis1(n, n), dis2(n, n);
    auto bfs = [&](int st, vector<int> &dis)
    {
        vector<int> vis(n);
        vis[st] = true;
        queue<int> q;
        q.push(st);
        dis[st] = 0;
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            for(int v: adj[u])
            {
                if(!vis[v])
                {
                    vis[v] = true;
                    dis[v] = dis[u] + 1;
                    q.push(v);
                }
            }
        }
    };
    bfs(0, dis1);
    bfs(n - 1, dis2);
    for(int i = 0; i < n; ++i)
    {
        sum[i] = dis1[i] + dis2[i];
        if(dis1[i] == n || dis2[i] == n)
            continue;
        s[brand[i]].insert({sum[i], i});
    }
    while(q--)
    {
        string str;
        int a, b;
        cin >> str >> a;
        a--;
        if(str == "query")
        {
            if(s[a].empty())
                cout << "-1\n";
            else
                cout << s[a].begin()->first << '\n';
        }
        else
        {
            cin >> b;
            b--;
            if(dis1[a] != n && dis2[a] != n)
            {
                auto it = s[brand[a]].find(make_pair(sum[a], a));
                s[brand[a]].erase(it);
                s[b].insert(make_pair(sum[a], a));
            }
            brand[a] = b;
        }
    }
}

int main()
{
    (*cin.tie(0)).sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}