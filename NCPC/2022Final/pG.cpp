#include <bits/stdc++.h>

using namespace std;
double a[505][505];

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
        scc_id.assign(2*n,-1), is.assign(2*n,false);
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
        for(int j : g[i])
            if(scc_id[j] == -1)
            {
                if (dep[j] == -1)
                dfs(j);
                low[i] = min(low[i], low[j]);
            }
        if(low[i] == dep[i])
        {
            int id = _id++;
            while(stk.back() != i)
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

void sol()
{
    fill(a[0], a[505], 0);
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            cin >> a[i][j];
    SAT sat;
    sat.init(n * n + 1);
    // row
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            for(int k = j + 1; k < n; ++k)
            {
                double x = a[i][j] - (int)a[i][j], y = a[i][k] - (int)a[i][k];
                if(x + y > 1)
                    sat.add_clause(i * n + j, i * n + k);
                else if(x + y == 1)
                {
                    sat.add_clause(i * n + j, i * n + k);
                    sat.add_clause(sat.rev(i * n + j), sat.rev(i * n + k));
                }
                else
                    sat.add_clause(sat.rev(i * n + j), sat.rev(i * n + k));
            }
        }
    }
    // col
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            for(int k = j + 1; k < n; ++k)
            {
                double x = a[j][i] - (int)a[j][i], y = a[k][i] - (int)a[k][i];
                if(x + y > 1)
                    sat.add_clause(j * n + i, k * n + i);
                else if(x + y == 1)
                {
                    sat.add_clause(j * n + i, k * n + i);
                    sat.add_clause(sat.rev(j * n + i), sat.rev(k * n + i));
                }
                else
                    sat.add_clause(sat.rev(j * n + i), sat.rev(k * n + i));
            }
        }
    }
    // solve
    if(sat.solve())
    {
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j) 
                cout << (sat.is[i * n + j] ? (int)a[i][j] + 1 : (int)a[i][j]) << " ";
            cout << "\n";
        }
    }
    else
        cout << "-1\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
        sol();
}