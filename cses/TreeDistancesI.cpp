#include <vector>
#include <queue>
#include <iostream>
#include <cstring>

using namespace std;
const int maxn = 2e5 + 5;
vector<int> adj[maxn];
int l, r, n;
vector<int> dis1, dis2;

void dfs(int u, int p)
{
    dis1[u] = dis1[p] + 1; 
    for(int v: adj[u])
        if(v != p && dis1[v] == -1)
            dfs(v, u);
}

void build()
{
    dfs(1, 1);
    for(int i = 1; i <= n; ++i)
        if(dis1[l] < dis1[i])
            l = i;
    dis1.assign(n + 1, -1);
    dfs(l, l);
    for(int i = 1; i <= n; ++i)
        if(dis1[r] < dis1[i])
            r = i;
    swap(dis1, dis2);
    dfs(r, r);
}

int main()
{
    (*cin.tie(0)).sync_with_stdio(0);
    cin >> n;
    dis1.assign(n + 1, -1);
    dis2.assign(n + 1, -1);
    for(int i = 1, u, v; i < n; ++i)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    build();
    for(int i = 1; i <= n; ++i)
        cout << max(dis1[i], dis2[i]) << " \n"[i == n];
    return 0;
}