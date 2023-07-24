#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 2e5 + 5;
int dep[maxn], sz[maxn], far[maxn], mxson[maxn], topf[maxn], id[maxn], idn;
ll we[maxn], w[maxn];
vector<int> graph[maxn];

struct seg
{
    ll data[maxn << 2];
    int n;
    void init(int _n)
    {
        n = _n;
        build(1, 1, n);
    }
    void build(int idx, int l, int r)
    {
        if(l == r)
        {
            data[idx] = we[l];
            return;
        }
        int mid = (l + r) / 2;
        build(idx << 1, l, mid);
        build(idx << 1 | 1, mid + 1, r);
        data[idx] = data[idx << 1] + data[idx << 1 | 1];
    }
    void update(int idx, int l, int r, int pos, int val)
    {
        if(l == r)
        {
            data[idx] = val;
            return;
        }
        int mid = (l + r) / 2;
        if(pos <= mid)
            update(idx << 1, l, mid, pos, val);
        else
            update(idx << 1 | 1, mid + 1, r, pos, val);
        data[idx] = data[idx << 1] + data[idx << 1 | 1];
    }
    ll query(int idx, int l, int r, int ql, int qr)
    {
        if(ql <= l && r <= qr)
            return data[idx];
        int mid = (l + r) / 2;
        ll res = 0;
        if(ql <= mid)
            res += query(idx << 1, l, mid, ql, qr);
        if(qr > mid)
            res += query(idx << 1 | 1, mid + 1, r, ql, qr);
        return res;
    }
}sgt;

void dfs(int now, int fa)
{
    dep[now] = dep[fa] + 1;
    sz[now] = 1;
    far[now] = fa;
    mxson[now] = 0;
    for(auto v: graph[now])
    {
        if(v != fa)
        {
            dfs(v, now);
            sz[now] += sz[v];
            if(sz[v] > sz[mxson[now]])
                mxson[now] = v;
        }
    }
}

void dfs2(int now, int top)
{
    topf[now] = top;
    id[now] = ++idn;
    we[idn] = w[now];
    if(mxson[now])
        dfs2(mxson[now], top);
    for(auto v: graph[now])
        if(v != far[now] && v != mxson[now])
            dfs2(v, v);
}

ll query_range(int x, int y)
{
    ll res = 0;
    while(topf[x] != topf[y])
    {
        if(dep[topf[x]] < dep[topf[y]])
            swap(x, y);
        res += sgt.query(1, 1, idn, id[topf[x]], id[x]);
        x = far[topf[x]];
    }
    if(id[x] > id[y])
        swap(x, y);
    res += sgt.query(1, 1, idn, id[x], id[y]);
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
        cin >> w[i];
    for(int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    dfs(1, 0);
    dfs2(1, 1);
    sgt.init(idn);
    while(q--)
    {
        int t, a, b;
        cin >> t;
        if(t == 1)
        {
            cin >> a >> b;
            sgt.update(1, 1, idn, id[a], b);
        }       
        else
        {
            cin >> a;
            cout << query_range(1, a) << '\n';
        }
    }
}