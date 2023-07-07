#include <bits/stdc++.h>

#define IO (cin.tie(0))->sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define _ << ' ' <<
using namespace std;
typedef long long ll;
const int mxn = 1e5 + 5;
const int mod = 1e9 + 7;
const int inf32 = 1 << 30;
const ll inf64 = 1ll << 60;

vector<int> adj[mxn];
vector<int> len, dep;

void dfs(int r, int d)
{
    dep[r] = d;
    for(int nx: adj[r])
    {
        if(!dep[nx])
        {
            dep[nx] = d + 1;
            dfs(nx, dep[nx]);
            len[nx] = max(len[nx], len[r] + 1);
        }
    }
}

int main()
{
    IO
    int n, k;
    cin >> n >> k;
    for(int i = 2, u; i <= n; ++i)
    {
        cin >> u;
        adj[u].push_back(i);
    }
    len.assign(n + 1, 0);
    dep.assign(n + 1, 0);
    dfs(1, 0);
    // tree
    // 剖分，找到前 k 條長的樹練
    for(int i = 1; i <= n; ++i)
        cout << len[i] << " \n"[i == n];
    return 0;
}