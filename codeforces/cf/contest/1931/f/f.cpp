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
const int maxn = 2e5 + 5;

vector<int> adj[maxn];

void solve()
{
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; ++i)
        adj[i].clear();
    vector<int> indeg(n);
    for(int i = 0; i < k; ++i)
    {
        int last = -1;
        for(int j = 0; j < n; ++j)
        {
            int x;
            cin >> x;
            x--;
            if(j > 1)
                adj[last].pb(x), ++indeg[x];
            last = x;
        }
    }
    queue<int> q;
    for(int i = 0; i < n; ++i)
        if(!indeg[i])
            q.push(i);
    vector<int> ans;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        ans.pb(u);
        for(int v: adj[u])
            if(!--indeg[v])
                q.push(v);
    }
    if(sz(ans) != n)
        cout << "NO\n";
    else
        cout << "YES\n";
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
