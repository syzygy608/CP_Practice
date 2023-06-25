#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using ll = long long;
const int maxn = 1e5 + 5;
vector<int> graph[maxn];
int n, m, in[maxn];

int main()
{
    cin >> n >> m;
    for(int i = 0, v, u; i < m; ++i)
    {
        cin >> u >> v;
        graph[v].push_back(u);
        in[u]++;
    }
    priority_queue<int> q;
    for(int i = 1; i <= n; ++i)
        if(!in[i])
            q.push(i);
    vector<int> ans;
    while(!q.empty())
    {
        int now = q.top();
        q.pop();
        ans.push_back(now);
        for(int nxt: graph[now])
        {
            in[nxt]--;
            if(!in[nxt])
                q.push(nxt);
        }
    }
    for(int i = ans.size(); i >= 1; --i)
        cout << ans[i - 1] << ' ';
}