#include <iostream>
#include <set>
#include <stack>

using namespace std;
const int maxn = 1e5 + 5;
set<int> adj[maxn];
int deg[maxn];
stack<int> st;

void dfs(int r)
{
    while(!adj[r].empty())
    {
        int tmp = *adj[r].begin();
        adj[r].erase(tmp);
        adj[tmp].erase(r);
        dfs(tmp);
    }
    st.push(r);
}

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0, u, v; i < m; ++i)
    {
        cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
        deg[u]++;
        deg[v]++;
    }
    for(int i = 1; i <= n; ++i)
    {
        if(deg[i] % 2 != 0)
        {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }
    dfs(1);
    if(st.size() != m + 1)
    {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    while(!st.empty())
    {
        cout << st.top() << ' ';
        st.pop();
    }
    return 0;
}