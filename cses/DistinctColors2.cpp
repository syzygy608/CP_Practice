#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int maxn = 2e5 + 5;
int n, cur, col[maxn], pos[maxn], sz[maxn], timer, seq[maxn], ans[maxn], color[maxn];
vector<int> adj[maxn];

void add(int x)
{
    col[x]++;
    if(col[x] == 1)
        cur++;
}

int dfs(int u, int par)
{
    sz[u] = 1;
    for(int v: adj[u])
    {
        if(v == par)
            continue;
        sz[u] += dfs(v, u);
    }
    return sz[u];
}

void dfs2(int u, int par, bool keep)
{
    int mxson = 0;
    pos[u] = ++timer;
    seq[timer] = u;
    for(int v: adj[u])
        if(v != par && sz[mxson] < sz[v])
            mxson = v;
    for(int v: adj[u])
    {
        if(v == par || v == mxson)
            continue;
        dfs2(v, u, false);
    }
    if(mxson)
        dfs2(mxson, u, true);
    for(int v: adj[u])
    {
        if(v == par || v == mxson)
            continue;
        for(int i = pos[v]; i < pos[v] + sz[v]; ++i)
            add(color[seq[i]]);
    }
    add(color[u]);
    ans[u] = cur;
    if(!keep)
    {
        cur = 0;
        for(int i = pos[u]; i < pos[u] + sz[u]; ++i)
            col[color[seq[i]]]--;       
    }
}

int main()
{
    cin >> n;
    vector<int> tmp;
    for(int i = 1; i <= n; ++i)
    {
        cin >> color[i];
        tmp.push_back(color[i]);
    }
    sort(tmp.begin(), tmp.end());
    tmp.resize(unique(tmp.begin(), tmp.end()) - tmp.begin());
    for(int i = 1; i <= n; ++i)
        color[i] = lower_bound(tmp.begin(), tmp.end(), color[i]) - tmp.begin() + 1;
    for(int i = 1, u, v; i < n; ++i)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    dfs2(1, 0, true);
    for(int i = 1; i <= n; ++i)
        cout << ans[i] << " \n"[i == n];
}