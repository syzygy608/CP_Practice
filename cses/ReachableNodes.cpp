#include <iostream>
#include <queue>
#include <bitset>
#include <vector>

using namespace std;
const int maxn = 5e4 + 5;
vector<int> adj[maxn], in;
bitset<maxn> reach[maxn];

int main()
{
    int n, m;
    cin >> n >> m;
    in.assign(n + 1, 0);
    for(int i = 0, u, v; i < m; ++i)
    {
        cin >> u >> v;
        adj[v].push_back(u);
        in[u]++;
    }
    queue<int> q;
    for(int i = 1; i <= n; ++i)
    {
        if(!in[i])
        {
            q.push(i);
            reach[i].set(i);
        }
    }
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int nxt: adj[u])
        {
            reach[nxt] |= reach[u];
            in[nxt]--;
            if(!in[nxt])
            {
                reach[nxt].set(nxt);
                q.push(nxt);
            }
        }
    }

    for(int i = 1; i <= n; ++i)
        cout << reach[i].count() << " \n"[i == n];
}