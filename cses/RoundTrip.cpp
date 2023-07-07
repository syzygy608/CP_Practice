#include <iostream>
#include <vector>
#include <stack>
#include <bitset>
#include <cstring>

using namespace std;
const int maxn = 1e5 + 5;
vector<int> graph[maxn];
int pre[maxn];
bitset<maxn> vis;
int n, m, start = -1, ed = -1;

bool dfs(int now, int par)
{
    vis[now] = true;
    for(int &nxt: graph[now])
    {
        if(nxt == par)
            continue;
        if(vis[nxt])
        {
            ed = now;
            start = nxt;
            return true;
        }
        pre[nxt] = now;
        if(dfs(nxt, pre[nxt]))
            return true;
    }
    return false;
}

int main()
{
    cin >> n >> m;
    for(int i = 0, u, v; i < m; ++i)
    {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);   
    }
    vis.reset();
    memset(pre, -1, sizeof(pre));
    for(int i = 1; i <= n; ++i)
        if(!vis[i] && dfs(i, pre[i]))
            break;
    stack<int> ans;
    if(start == -1)
    {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    for(int u = ed; u != start; u = pre[u])
        ans.push(u);
    ans.push(start);
    ans.push(ed);
    cout << ans.size() << '\n';
    while(!ans.empty())
    {
        cout << ans.top() << ' ';
        ans.pop();
    }
    return 0;
}