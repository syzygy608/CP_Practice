#include <iostream>
#include <vector>
#include <stack>
#include <utility>

using namespace std;
const int maxn = 2e5 + 5;

struct AP_bridge
{
    vector<int> low, depth;
    vector<vector<int>> G;
    vector<int> AP;
    vector<pair<int, int>> Bridge;
    void init(int n)
    {
        depth.assign(n+1, 0);
        low.assign(n+1, 0);
        G.assign(n+1, vector<int>());
        AP.clear();
        Bridge.clear();
    }
    void add_edge(int u, int v)
    {
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    void solve(int root)
    {
        dfs(root, root, 1);
    }
    void dfs(int u, int parent, int dep)
    {
        depth[u] = low[u] = dep;
        int child = 0;
        bool isAP = false; 
        for(auto &v : G[u])
        {
            if(v == parent)
                continue;
            if(depth[v] == 0)
            {
                child++;
                dfs(v, u, dep+1);
                low[u] = min(low[v], low[u]);
                if(low[v] >= depth[u])
                    isAP = true;
                if(low[v] > depth[u])
                    Bridge.emplace_back(u,v);
            }
            else
                low[u] = min(low[u], depth[v]);
        }
        if(u == parent && child < 2)
            isAP = false;
        if(isAP)
            AP.emplace_back(u);
    }
    vector<int> get_AP()
    {
        return AP;
    }
    vector<pair<int, int>> get_bridge()
    {
        return Bridge;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    AP_bridge ap;
    ap.init(n);
    for(int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        ap.add_edge(u, v);
    }
    ap.solve(1);
    vector<int> AP = ap.get_AP();
    cout << AP.size() << '\n';
    for(auto &x : AP)
        cout << x << " ";
    return 0;
}