#include <iostream>
#include <vector>
#include <stack>
#include <array>

using namespace std;
const int maxn = 2e5 + 5;
int scc_id[maxn], scc_cnt = 0, n, m;
vector<int> scc[maxn], rev[maxn];
bool vis[maxn];
stack<int> st; 

void dfs(int u)
{
    vis[u] = true;
    for(int v: scc[u])
    {
        if(v == u || vis[v])
            continue;
        dfs(v);
    }
    st.push(u);
}

void rdfs(int u, int id)
{
    scc_id[u] = id;
    for(int v: rev[u])
    {
        if(v == u || scc_id[v])
            continue;
        rdfs(v, id);
    }
}

void kosaraju()
{
    for(int i = 1; i <= 2 * m; ++i)
        if(!vis[i])
            dfs(i);
    while(!st.empty())
    {
        int u = st.top();
        st.pop();
        if(!scc_id[u])
            rdfs(u, ++scc_cnt);
    }
}

int main()
{
    cin >> n >> m;
    vector<int> state(n + 1);
    for(int i = 1; i <= n; ++i)
        cin >> state[i];
    // switch control
    vector<array<int, 2>> adj(n + 1, {0, 0});
    for(int i = 1, x; i <= m; ++i)
    {
        cin >> x;
        for(int j = 0, y; j < x; ++j)
        {
            cin >> y;
            if(adj[y][0] == 0)
                adj[y][0] = i;
            else
                adj[y][1] = i;
        }
    }
    for(int i = 1; i <= n; ++i)
    {
        if(state[i] == 1)
        {
            // door is open
            scc[adj[i][0]].push_back(adj[i][1]);
            scc[adj[i][1]].push_back(adj[i][0]);
            scc[adj[i][0] + m].push_back(adj[i][1] + m);
            scc[adj[i][1] + m].push_back(adj[i][0] + m);
            rev[adj[i][0]].push_back(adj[i][1]);
            rev[adj[i][1]].push_back(adj[i][0]);
            rev[adj[i][0] + m].push_back(adj[i][1] + m);
            rev[adj[i][1] + m].push_back(adj[i][0] + m);
        }
        else
        {
            // door is closed
            scc[adj[i][0]].push_back(adj[i][1] + m);
            scc[adj[i][1]].push_back(adj[i][0] + m);
            scc[adj[i][0] + m].push_back(adj[i][1]);
            scc[adj[i][1] + m].push_back(adj[i][0]);
            rev[adj[i][0] + m].push_back(adj[i][1]);
            rev[adj[i][1] + m].push_back(adj[i][0]);
            rev[adj[i][0]].push_back(adj[i][1] + m);
            rev[adj[i][1]].push_back(adj[i][0] + m);
        }
    }
    // check if there is a solution
    kosaraju();
    for(int i = 1; i <= m; ++i)
    {
        if(scc_id[i] == scc_id[i + m])
        {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
}