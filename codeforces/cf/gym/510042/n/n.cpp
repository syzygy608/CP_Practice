#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <sstream>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <bitset>
#include <vector>
#include <utility>
#include <cassert>
#include <unordered_set>

#define F first
#define S second
#define pb push_back
#define _ << ' ' << 
#define sz(a) ((int)(a).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define IO (*cin.tie(0)).sync_with_stdio(0);

using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;
map<int, vector<int>> sub;
map<int, bool> vis;
map<int, int> par, low, depth;
map<int, vector<pair<int, int>>> G;
unordered_set<int> AP;

void add_edge(int u, int v, int i)
{
    G[u].emplace_back(v, i);
    G[v].emplace_back(u, i);
}
void dfs(int u, int parent, int dep)
{
    sub[parent].pb(u);
    depth[u] = low[u] = dep;
    int child = 0;
    bool isAP = false; 
    for(auto &v : G[u])
    {
        if(v.F == parent)
            continue;
        if(depth[v.F] == 0)
        {
            child++;
            dfs(v.F, u, dep + 1);
            low[u] = min(low[v.F], low[u]);
            if(low[v.F] >= depth[u])
                isAP = true;
        }
        else
            low[u] = min(low[u], depth[v.F]);
    }
    if(u == parent && child < 2)
        isAP = false;
    if(isAP)
        AP.insert(u);
}
void dfs2(int node, int pa)
{
    vis[node] = true;
    par[node] = pa;
    for(auto i: G[node])
    {
        if(vis[i.F])
            continue;
        dfs2(i.F, pa);
    }
}

void solve()
{
    int n;
    cin >> n;
    set<int> occur;
    for(int i = 1, u, v; i <= n; i++)
    {
        cin >> u >> v;
        add_edge(u, v, i);
        occur.insert(u);
        occur.insert(v);
    }
    int cnt = 0;
    for(auto i: occur)
    {
        if(!vis[i])
        {
            dfs(i, i, 1);
            dfs2(i, i);
            cnt++;
        }
    }
    cout << cnt - 1 << '\n';
    int root = par[*occur.begin()];
    map<int, int> mp;
    for(auto i: occur)
        if(AP.count(i) || G[i].size() == 1)
            mp[par[i]]++;
    for(auto i: occur)
    {
        if(mp[par[i]] == 0)
        {
            root = par[i];
            break;
        }
    }
    for(auto i: occur)
    {
        if(par[i] == root || !vis[par[i]])
            continue;
        bool ok = false;
        for(auto j: sub[i])
        {
            if(!AP.count(j))
            {
                cout << G[j][0].S _ j _ root << '\n';
                break;
            }
        }
        vis[par[i]] = false;
    }
    for(auto i: occur)
    {
        G[i].clear();
        vis[i] = false;
        par[i] = 0;
        sub[i].clear();
        low[i] = depth[i] = 0;
    }
    AP.clear();
}

int main()
{
    IO;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
