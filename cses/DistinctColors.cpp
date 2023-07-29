#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int maxn = 2e5 + 5;
int n, id[maxn], idn = 1, out[maxn], a[maxn << 1], C;
vector<int> adj[maxn];

struct MoSolver
{
    struct query
    {
        int l, r, id;
        bool operator < (const query &o)
        {
            if(l / C == o.l / C)
                return (l / C) & 1 ? r > o.r : r < o.r;
            return l / C < o.l / C;
        }
    };
    int cur;
    vector<int> ans;
    vector<int> cnt;
    void init(int n)
    {
        ans.clear();
        cnt.clear();
        cnt.assign(n + 1, 0);
    }
    void add(int x)
    {
        if(x != 0 && cnt[x]++ == 0)
            cur++;
    }
    void sub(int x)
    {
        if(x != 0 && --cnt[x] == 0)
            cur--;   
    }
    vector<query> Q;
    void add_query(int l, int r, int id)
    {
        // [l, r)
        Q.push_back({l, r, id});
        ans.push_back(0);
    }
    void run()
    {
        sort(Q.begin(), Q.end());
        int pl = 0, pr = 0;
        cur = 0;
        for(query &i : Q)
        {
            while(pl > i.l)
                add(a[--pl]);
            while(pr < i.r)
                add(a[pr++]);
            while(pl < i.l)
                sub(a[pl++]);
            while(pr > i.r)
                sub(a[--pr]);
            ans[i.id] = cur;
        }
    }
};

void dfs(int u)
{
    id[u] = idn++;
    for(int v : adj[u])
        if(!id[v])
            dfs(v);
    out[u] = idn++;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    C = max(1, (int)sqrt(n));
    vector<int> color(n + 1);
    for(int i = 1; i <= n; ++i)
        cin >> color[i];
    vector<int> tmp = color;
    sort(tmp.begin(), tmp.end());
    tmp.resize(unique(tmp.begin(), tmp.end()) - tmp.begin());
    for(int i = 1, u, v; i < n; ++i)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    MoSolver mo;
    mo.init(n);
    for(int i = 1; i <= n; ++i)
    {
        a[id[i]] = lower_bound(tmp.begin(), tmp.end(), color[i]) - tmp.begin() + 1;
        a[out[i]] = a[id[i]];
    }    
    for(int i = 1; i <= n; ++i)
        mo.add_query(id[i], out[i] + 1, i);
    mo.run();
    for(int i = 1; i <= n; ++i)
        cout << mo.ans[i] << ' ';
}