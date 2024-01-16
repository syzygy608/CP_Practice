#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <sstream>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <bitset>
#include <vector>
#include <utility>
#include <cassert>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

#define AnNinMiRu (*cin.tie(0)).sync_with_stdio(0);
#define eb emplace_back
#define X first
#define Y second
#define _ << ' ' <<
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(x) ((int)(x).size())
#define debug(x) cerr << "\e[1;31m" << #x << " = " << (x) << "\e[0m\n"

const ld PI = atan2(0, -1);
const ld EPS = 1e-6;
const ll INF = 4557430888798830399;
const int MOD = 1e9 + 7; 
const int maxn = 2e5 + 5;
int score[maxn], ans = 2e9, n, m;
vector<vector<pair<int, int>>> g;

void sol()
{
    cin >> n >> m;
    g.resize(n);
    for(int i = 0; i < n; ++i)
        g[i].clear();
    for(int i = 0; i < m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    vector<int> score(n);
    for(auto &i : score)
        cin >> i;
    vector<vector<ll>> dis(n, vector<ll>(n, INF));
    priority_queue<array<ll, 3>, vector<array<ll, 3>>, greater<array<ll, 3>>> pq;
    pq.push({0, 0, 0});
    dis[0][0] = 0;
    while(!pq.empty())
    {
        auto [d, u, bicycle] = pq.top();
        pq.pop();
        if(dis[u][bicycle] == INF || dis[u][bicycle] < d)
            continue;
        for(auto [v, w] : g[u])
        {
            if(dis[v][bicycle] > d + w * score[bicycle])
            {
                dis[v][bicycle] = d + w * score[bicycle];
                pq.push({dis[v][bicycle], v, bicycle});
            }
        }
        if(u != bicycle && dis[u][u] == INF)
        {
            dis[u][u] = d;
            pq.push({dis[u][u], u, u});
        }
    }
    cout << *min_element(all(dis[n - 1])) << '\n';
}

signed main()
{
    AnNinMiRu
    int t = 1;
    cin >> t;
    while(t--)
        sol();
    return 0;
}