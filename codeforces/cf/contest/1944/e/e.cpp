#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define _ << ' ' << 
#define sz(a) ((int)(a).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define IO (*cin.tie(0)).sync_with_stdio(0);

using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;
vector<int> adj[maxn];
int sz[maxn], n, color[maxn], dis[maxn];
bool dead[maxn];
vector<pair<int, int>> ans;
 
void pre_cal(int root, int par)
{
    sz[root] = 1;
    for(int &i: adj[root])
    {
        if(i == par || dead[i])
            continue;
        pre_cal(i, root);
        sz[root] += sz[i];
    }
}
 
int find_centroid(int v, int par, int num)
{
    for(int &i: adj[v])
        if(i != par && !dead[i] && sz[i] * 2 > num)
            return find_centroid(i, v, num);
    return v;
}

void bfs(int root)
{
    queue<int> q;
    q.push(root);
    color[root] = 1;
    dis[root] = 0;
    while(!q.empty())
    {
        int v = q.front();
        q.pop();
        for(int &i: adj[v])
        {
            if(color[i] == 0)
            {
                color[i] = 1;
                dis[i] = dis[v] + 1;
                q.push(i);
            }
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i)
        adj[i].clear();
    for(int i = 0, u, v; i < n - 1; ++i)
    {
        cin >> u >> v;
        --u, --v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    memset(dead, 0, sizeof(dead));
    memset(color, 0, sizeof(color));
    pre_cal(0, -1);
    int cen = find_centroid(0, -1, sz[0]);
    bfs(cen);
    if(adj[cen].size() == 1)
    {
        ans.pb({adj[cen][0], 1});
        set<int> s;
        for(int i = 0; i < n; ++i)
            if(dis[i] != 2 && dis[i] != 0)
                s.insert(dis[i]);
        for(int i: s)
            ans.pb({cen, i});
    }
    else
    {
        set<int> s;
        for(int i = 0; i < n; ++i)
            s.insert(dis[i]);
        for(int i: s)
            ans.pb({cen, i});
    }
    cout << sz(ans) << '\n';
    for(auto &i: ans)
        cout << i.F + 1 _ i.S << '\n';
    ans.clear();
}

int main()
{
    IO;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
