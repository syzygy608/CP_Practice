#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 2e5 + 5;
int dep[maxn], sz[maxn], far[maxn], mxson[maxn], topf[maxn], id[maxn], idn, we[maxn], w[maxn];
vector<int> graph[maxn];

struct seg
{
    int data[maxn << 1];
    int n;
    inline int id(int l, int r)
    {
        return (l + r) | (l != r);
    }
    void init(int _n)
    {
        n = _n;
        build(1, n);
    }
    void build(int l, int r)
    {
        if(l == r)
        {
            data[id(l, r)] = we[l];
            return;
        }
        int mid = (l + r) / 2;
        build(l, mid);
        build(mid + 1, r);
        data[id(l, r)] = max(data[id(l, mid)], data[id(mid + 1, r)]);
    }
    void update(int l, int r, int pos, int val)
    {
        if(l == r)
        {
            data[id(l, r)] = val;
            return;
        }
        int mid = (l + r) / 2;
        if(pos <= mid)
            update(l, mid, pos, val);
        else
            update(mid + 1, r, pos, val);
        data[id(l, r)] = max(data[id(l, mid)], data[id(mid + 1, r)]);
    }
    int query(int l, int r, int ql, int qr)
    {
        if(ql <= l && r <= qr)
            return data[id(l, r)];
        int mid = (l + r) / 2;
        int res = 0;
        if(ql <= mid)
            res = max(res, query(l, mid, ql, qr));
        if(qr > mid)
            res = max(res, query(mid + 1, r, ql, qr));
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

int query_range(int x, int y)
{
    int res = -1e9;
    while(topf[x] != topf[y])
    {
        if(dep[topf[x]] < dep[topf[y]])
            swap(x, y);
        res = max(res, sgt.query(1, idn, id[topf[x]], id[x]));
        x = far[topf[x]];
    }
    if(id[x] > id[y])
        swap(x, y);
    res = max(res, sgt.query(1, idn, id[x], id[y]));
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
        cin >> t >> a >> b;
        if(t == 1)
            sgt.update(1, idn, id[a], b);
        else
            cout << query_range(a, b) << ' ';
    }
}