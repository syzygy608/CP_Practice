#include <bits/stdc++.h>

#define IO (cin.tie(0))->sync_with_stdio(0);
#define F first
#define S second
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define _ << ' ' <<

using namespace std;
using ll = long long;

const int maxn = 1e5 + 5;

int deg[maxn];

vector<int> adj1[maxn], adj2[maxn];

void sol()
{
    int n, m;
    cin >> n >> m;
    int idx, mx = 0;
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        deg[u]++;
        deg[v]++;
        if(deg[u] > mx)
        {
            mx = deg[u];
            idx = u;
        }
        if(deg[v] > mx)
        {
            mx = deg[v];
            idx = v;
        }
        adj1[u].push_back(v);
        adj1[v].push_back(u);
    }
    vector<pair<int, int>> degs;
    for(int i = 0; i < n; i++)
        degs.push_back({deg[i], i});
    sort(rall(degs));
    for(auto i: degs)
    {
        int u = i.S;
        int d = i.F;
        for(auto v: adj1[u])
            if(deg[v] < d)
                adj2[u].push_back(v);
    }
    memset(deg, 0, sizeof deg);
    // set deg to indeg
    for(int i = 0; i < n; i++)
        for(auto j: adj2[i])
            deg[j]++;
    int ans = 0;
    vector<int> dp(n + 1, 0);
    queue<int> q;
    for(int i = 0; i < n; i++)
        if(deg[i] == 0)
            q.push(i);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(auto v: adj2[u])
        {
            dp[v] = max(dp[v], dp[u] + 1);
            deg[v]--;
            if(deg[v] == 0)
                q.push(v);
        }
    }
    for(int i = 0; i < n; i++)
        ans = max(ans, dp[i]);
    cout << ans + 1 << '\n';
}

int main()
{
    IO
    int t = 1;
    // cin >> t;
    while(t--)
        sol();
    return 0;
}
