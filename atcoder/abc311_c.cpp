#include <iostream>
#include <vector>
#include <stack>

using namespace std;
const int maxn = 2e5 + 5;
vector<int> adj[maxn];
int vis[maxn], pre[maxn];

void dfs(int r)
{
    vis[r] = 1;
    for(int nxt: adj[r])
    {
        if(vis[nxt] == 1)
        {
            stack<int> ans;
            ans.push(r);
            while(ans.top() != nxt)
                ans.push(pre[ans.top()]);
            cout << ans.size() << '\n';
            while(!ans.empty())
            {
                cout << ans.top() << ' ';
                ans.pop();
            }
            exit(0);
        }
        else if(!vis[nxt])
        {
            pre[nxt] = r;
            dfs(nxt);
        }
    }
    vis[r] = 2;
}

int main()
{
    int n;
    cin >> n;
    fill_n(pre, n + 1, -1);
    for(int i = 1, v; i <= n; ++i)
    {
        cin >> v;
        adj[i].push_back(v);
    }
    for(int i = 1; i <= n; ++i)
        if(!vis[i])
            dfs(i);
    return 0;
}