#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
using ll = long long;
const int maxn = 3e3 + 5;
struct edge
{
    int u, v;
    ll w;
};

ll dis[maxn];
int n, m;   
bool vis[maxn], vis2[maxn];
vector<edge> edgelist;
vector<int> adj[maxn], check;

void dfs(int now)
{
    vis[now] = true;
    for(int nxt: adj[now])
        if(!vis[nxt])
            dfs(nxt);
}

void dfs2(int now)
{
    vis2[now] = true;
    for(int nxt: adj[now])
        if(!vis2[nxt])
            dfs2(nxt);
}

void bellmen()
{
    memset(dis, 0x3f, sizeof(dis));
    dis[1] = 0;
    for(int i = 1; i <= n; ++i)
    {
        bool update = false;
        for(edge el: edgelist)
        {
            if(dis[el.v] > dis[el.u] + el.w)
            {
                dis[el.v] = dis[el.u] + el.w;
                update = true;
                if(i == n)
                    check.push_back(el.v);   
            }
        }
        if(!update)
            break;
    }
}

int main()
{
    cin >> n >> m;
    for(int i = 0, u, v, c; i < m; ++i)
    {
        cin >> u >> v >> c;
        adj[u].push_back(v);
        edgelist.push_back({u, v, -c});
    }
    dfs(1);
    check.clear();
    bellmen();
    for(int el: check)
    {
        if(vis[el])
        {
            cerr << el << '\n';
            memset(vis2, false, sizeof(vis2));
            dfs2(el);
            if(vis2[n])
            {
                cout << "-1\n";
                return 0;
            }
        }
    }
    cout << -dis[n] << '\n';
    return 0;
}