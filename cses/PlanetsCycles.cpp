#include <iostream>
#include <vector>
#include <bitset>

using namespace std;
const int maxn = 200005;

vector<int> nxt, ans, vis, path;
vector<vector<int>> cycles;

void dfs(int u)
{
    path.push_back(u);
    vis[u] = 1;
    int v = nxt[u];
    if(vis[v] == 1)
    {
        cycles.push_back({});
        for(int j = path.size() - 1; j >= 0; --j)
        {
            cycles.back().push_back(path[j]);
            if(path[j] == v)
                break;
        }
    }
    else if(!vis[v])
        dfs(v);
    vis[u] = 2;
    path.pop_back();
}

int dis(int u)
{
    if(ans[u])
        return ans[u];
    return ans[u] = dis(nxt[u]) + 1;
}

int main()
{
    int n;
    cin >> n;
    nxt.resize(n);
    ans.resize(n);
    vis.resize(n);
    for(int i = 0; i < n; i++)
    {
        cin >> nxt[i];
        nxt[i]--;
    }
    for(int i = 0; i < n; ++i)
        if(!vis[i])
            dfs(i);
    for(auto &c : cycles)
        for(int i: c)
            ans[i] = c.size();
    vis.assign(n, 0);
    for(int i = 0; i < n; ++i)
        if(!ans[i])
            dis(i);
    for(int i = 0; i < n; ++i)
        cout << ans[i] << " \n"[i == n - 1];
}