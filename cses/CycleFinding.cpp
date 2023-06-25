#include <iostream>
#include <vector>
#include <array>
#include <cstring>
#include <set>
#include <algorithm>

using namespace std;
using ll = long long;
const int maxn = 3e3 + 5;
vector<array<int, 3>> edgelist;
vector<int> graph[maxn], path;
int n, m, pre[maxn];
ll dis[maxn];
bool vis[maxn];

void bellmen()
{
    memset(dis, 0x3f, sizeof(dis));
    dis[1] = 0;
    for(int i = 1; i <= n; ++i)
    {
        for(auto edge: edgelist)
        {
            if(dis[edge[1]] > dis[edge[0]] + edge[2])
            {
                dis[edge[1]] = dis[edge[0]] + edge[2];
                pre[edge[1]] = edge[0];
                if(i == n)
                {
                    int now = edge[1];
                    for(int j = 1; j <= n; ++j)
                        now = pre[now];
                    for(int st = now;; st = pre[st])
                    {
                        path.push_back(st);
                        if(path.size() > 1 && st == now)
                            break;
                    }
                    reverse(path.begin(), path.end());
                    cout << "YES\n";
                    for(auto el: path)
                        cout << el << ' ';
                    exit(0);
                }
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for(int i = 0, u, v, c; i < m; ++i)
    {
        cin >> u >> v >> c;
        graph[u].push_back(v);
        edgelist.push_back({u, v, c});
    }
    memset(pre, -1, sizeof(pre));
    bellmen();
    cout << "NO\n";
    return 0;
}