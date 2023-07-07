#include <iostream>
#include <queue>
#include <array>
#include <vector>
#include <cstring>

using namespace std;
using ll = long long;
const int maxn = 1e5 + 5;
vector<array<int, 2>> graph[maxn];
int vis[maxn], n, m, k;

int main()
{
    cin >> n >> m >> k;
    for(int i = 0, u, v, w; i < m; ++i)
    {
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }
    priority_queue<array<ll, 2>, vector<array<ll, 2>>, greater<array<ll,2>>> pq;
    pq.push({0, 1});
    while(!pq.empty() && vis[n] < k)
    {
        auto tp = pq.top();
        pq.pop();
        if(vis[tp[1]] >= k)
            continue;
        vis[tp[1]]++;
        if(tp[1] == n)
            cout << tp[0] << ' ';
        for(auto nxt: graph[tp[1]])
            pq.push({tp[0] + nxt[1], nxt[0]});
    }
}