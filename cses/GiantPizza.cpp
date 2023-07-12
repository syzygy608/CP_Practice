#include <bits/stdc++.h>

using namespace std;

struct SAT
{
    vector <vector<int>> g;
    vector <int> dep, low, scc_id;
    vector <bool> is;
    vector <int> stk;
    int n, _id, _t;
    SAT(){}
    void init(int _n)
    {
        n = _n, _id = _t = 0;
        g.assign(2 * n, vector<int>());
        dep.assign(2 * n, -1), low.assign(2 * n, -1);
        scc_id.assign(2 * n, -1), is.assign(2 * n, false);
        stk.clear();
    }
    void add_edge(int x, int y)
    {
        g[x].push_back(y);
    }
    int rev(int i) {return i < n ? i + n : i - n;}
    void add_ifthen(int x, int y){add_clause(rev(x),y);}
    void add_clause(int x, int y) // x or y
    {
        add_edge(rev(x), y);
        add_edge(rev(y), x);
    }
    void dfs(int i)
    {
        dep[i] = low[i] = _t++;
        stk.push_back(i);
        for (int j : g[i])
        if(scc_id[j] == -1)
        {
            if(dep[j] == -1)
                dfs(j);
            low[i] = min(low[i], low[j]);
        }
        if(low[i] == dep[i])
        {
            int id = _id++;
            while (stk.back() != i)
            {
                int x = stk.back();
                stk.pop_back();
                scc_id[x] = id;
            }
            stk.pop_back();
            scc_id[i] = id;
        }
    }
    bool solve()
    {
        for(int i = 0; i < 2 * n; ++i)
            if(dep[i] == -1)
                dfs(i);
        for(int i = 0; i < n; ++i)
        {
            if(scc_id[i] == scc_id[i + n])
                return false;
            if(scc_id[i] < scc_id[i + n])
                is[i] = true;
            else
                is[i + n] = true;
        }
        return true;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    SAT sol;
    sol.init(m);
    for(int i = 0; i < n; ++i)
    {
        char a, b;
        int u, v;
        cin >> a >> u >> b >> v;
        if(a == '+' && b == '+')
            sol.add_clause(u, v);
        else if(a == '-' && b == '-')
            sol.add_clause(sol.rev(u), sol.rev(v));
        else if(a == '+' && b == '-')
            sol.add_clause(u, sol.rev(v));
        else if(a == '-' && b == '+')
            sol.add_clause(sol.rev(u), v);
    }
    bool flag = sol.solve();
    if(!flag)
        cout << "IMPOSSIBLE\n";
    else
        for(int i = 1; i <= m; ++i)
            cout << ((sol.is[i]) ? "+" : "-") << " \n"[i == m];
    return 0;
}