#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int maxn = 1e5 + 5;
vector<int> graph[maxn], pre(maxn, -1), ans;
int ed = -1, st = -1, n, m, vis[maxn];

void dfs(int now)
{
    if(vis[now] == 2)
        return;
    vis[now] = 1;
    for(int nxt: graph[now])
    {
        if(vis[nxt] == 1)
        {
            ans.push_back(now);
            while(ans.back() != nxt)
                ans.push_back(pre[ans.back()]);
            ans.push_back(now);
            reverse(ans.begin(), ans.end());
            cout << ans.size() << '\n';
            for(int i: ans)
                cout << i << ' ';
            exit(0);
        }
        pre[nxt] = now;
        dfs(nxt);
    }
    vis[now] = 2;
}

int main()
{
    cin >> n >> m;
    for(int i = 0, u, v; i < m; ++i)
    {
        cin >> u >> v;
        graph[u].push_back(v);
    }
    for(int i = 1; i <= n; ++i)
        if(vis[i] == 0)
            dfs(i);
    cout << "IMPOSSIBLE\n";
    return 0;
}