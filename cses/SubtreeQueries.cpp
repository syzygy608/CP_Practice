#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
const int maxn = 2e5 + 5;
int idn, in[maxn], out[maxn], arr[maxn];
ll val[maxn << 1];
vector<int> G[maxn];

void update(int x, ll v)
{
    for(; x <= idn; x += x & -x)
        val[x] += v;
}

ll query(int x)
{
    ll ret = 0;
    for(; x; x -= x & -x)
        ret += val[x];
    return ret;
}

void dfs(int u, int fa)
{
    in[u] = ++idn;
    for(int v : G[u])
        if(v != fa)
            dfs(v, u);
    out[u] = idn;
}

int main()
{
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; ++i)
        cin >> arr[i];
    for(int i = 1; i < n; ++i)
    {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1, 0);
    for(int i = 1; i <= n; ++i)
        update(in[i], arr[i]);
    while(q--)
    {
        int op;
        cin >> op;
        if(op == 1)
        {
            int s, x;
            cin >> s >> x;
            update(in[s], x - arr[s]);
            arr[s] = x;
        }
        else
        {
            int s;
            cin >> s;
            cout << query(out[s]) - query(in[s] - 1) << '\n';
        }
    }
}