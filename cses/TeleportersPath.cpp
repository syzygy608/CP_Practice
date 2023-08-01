#include <iostream>
#include <stack>
#include <vector>

using namespace std;
const int maxn = 1e5 + 5;
vector<int> adj[maxn];
stack<int> st;
int in[maxn], out[maxn];
bool vis[maxn];

void dfs(int r)
{
    vis[r] = true;
    while(!adj[r].empty())
    {
        int now = adj[r].back();
        adj[r].pop_back();
        dfs(now);
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
        adj[u].push_back(v);
        in[v]++;
        out[u]++;
    }
    if(in[1] != out[1] - 1 || in[n] != out[n] + 1)
    {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    dfs(1);
    for(int i = 1; i <= n; ++i)
    {
        if(i == 1 || i == n)
        {
            if(!vis[i])
            {
                cout << "IMPOSSIBLE\n";
                return 0;
            }
        }
        else if(in[i] != out[i])
        {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }
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