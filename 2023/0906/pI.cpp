#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define _ << ' ' <<
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define IO (*cin.tie(0)).sync_with_stdio(0);

using namespace std;
using ll = long long;
const int maxn = 2e5 + 5;

vector<int> adj[maxn];
bitset<maxn> vis;
int ans = 0;

void dfs(int r)
{
    vis[r] = true;
    ans++;
    for(int v: adj[r])
        if(!vis[v])
            dfs(v);
}

int main()
{
    IO
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> pt;
    for(int i = 0, num; i < k; ++i)
    {
        cin >> num;
        pt.push_back(num);
    }
    for(int i = 0, u, v; i < m; ++i)
    {
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for(int v: pt)
        if(!vis[v])
            dfs(v);
    cout << ans << '\n';
    return 0;
}