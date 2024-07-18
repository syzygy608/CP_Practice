#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
const int N = 2e5 + 5;
 
multiset<pair<int, int>> nei[N];
ll indeg[N], outdeg[N], n, m, a, b, dist[N];
ll ans = 0;
 
void dfs(int u)
{
    while(!nei[u].empty())
    {
        auto it = nei[u].begin();
        int v = it->first, w = it->second;
        nei[u].erase(it);
        dfs(v);
        ans += w * 1ll;
    }
}
 
int main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ifstream cin("bugged.in");
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        for(int i = 1; i <= n; ++i)
            nei[i].clear(), indeg[i] = outdeg[i] = 0;
        for(int i = 1; i <= n; ++i)
            cin >> dist[i];
        for(int i = 0; i < m; ++i)
        {
            cin >> a >> b;
            nei[a].insert({b, abs(dist[b] - dist[a])});
            ++outdeg[a];
            ++indeg[b];
        }
        bool ok = 1;
        for(int i = 1; i <= n; ++i)
            if(indeg[i] != outdeg[i])
                ok = 0;
        if(!ok)
        {
            cout << "-1\n";
            continue;
        }
        ans = 0;
        for(int i = 1; i <= n; i++) {
            dfs(i);
        }
        cout << ans << '\n';
    }
    return 0;
}
