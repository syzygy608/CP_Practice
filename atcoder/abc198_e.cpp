#include <iostream>
#include <algorithm>
#include <bitset>
#include <vector>

using namespace std;
const int maxn = 1e5 + 5;
int col[maxn], cnt[maxn];
vector<int> adj[maxn], ans;
bitset<maxn> vis;

void dfs(int u)
{
    if(!cnt[col[u]])
        ans.push_back(u);
    vis[u] = true;
    cnt[col[u]]++;
    for(int v: adj[u])
    {
        if(v == u || vis[v])
            continue;
        dfs(v);
    }
    cnt[col[u]]--;
}

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> col[i];
    for(int i = 1, u, v; i < n; ++i)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    sort(ans.begin(), ans.end());
    for(int i: ans)
        cout << i << '\n';
    return 0;
}