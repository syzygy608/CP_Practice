#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    int n, m, k, t;
    cin >> n >> m >> k >> t;
    vector<int> a(n);
    vector<int> forbid(k);
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    vector<int> diff(t + 1, 0);
    for(int i = 0, l, r; i < k; ++i)
    {
        cin >> forbid[i] >> l >> r;
        forbid[i]--;
        l--;
        diff[l] ^= (1 << i);
        diff[r] ^= (1 << i);
    }
    for(int i = 1; i < t; ++i)
        diff[i] ^= diff[i - 1];
    vector<vector<pair<int, int>>> adj(n, vector<pair<int, int>>());
    for(int i = 0, u, v, w; i < m; ++i)
    {
        cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    int last = -1;
    ll ans = 0;
    for(int i = 0; i < t; ++i)
    {
        if(diff[i] == last)
            cout << ans << '\n';
        else
        {
            priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
            for(int j = 0; j < k; ++j)
                if(diff[i] >> j & 1)
                    pq.emplace(0, forbid[j]);
            vector<ll> dis(n, -1);
            while(!pq.empty())
            {
                auto [w, u] = pq.top();
                pq.pop();
                if(dis[u] != -1)
                    continue;
                dis[u] = w;
                for(auto [v, ww]: adj[u])
                    pq.emplace(dis[u] + ww, v);
            }
            if(find(dis.begin(), dis.end(), -1) != dis.end())
            {
                ans = -1;
                cout << "-1\n";
            }
            else
            {
                ans = 0;
                for(int j = 0; j < n; ++j)
                    ans += 1ll * a[j] * dis[j];
                cout << ans << '\n';
            }
        }
        last = diff[i];
    }
}