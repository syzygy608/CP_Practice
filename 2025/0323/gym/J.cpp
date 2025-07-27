#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define all(x) (x).begin(), (x).end()
#define F first
#define S second

constexpr i64 MOD = 1e9 + 7;

template<class T>
static void cmn(T &a, T b) { a = (a <=> b > 0) ? b : a; }
template<class T>
static void cmx(T &a, T b) { a = (a <=> b < 0) ? b : a; }

struct Node
{
    int l, r, val;
    Node *lc, *rc;
    void pull()
    {
        val = max(lc->val, rc->val);
    }
};

void update(Node *rt, int l, int r, int pos, int val)
{
    if(l == r)
    {
        rt->val = val;
        return;
    }
    int mid = l + r >> 1;
    if(!rt->lc)
        rt->lc = new Node();
    if(!rt->rc)
        rt->rc = new Node();
    if(pos <= mid)
        update(rt->lc, l, mid, pos, val);
    else
        update(rt->rc, mid + 1, r, pos, val);
    rt->pull();
}

int query(Node *rt, int l, int r, int ql, int qr)
{
    if(ql <= l && r <= qr)
        return rt->val;
    int mid = l + r >> 1, res = -1;
    if(ql <= mid)
        cmx(res, query(rt->lc, l, mid, ql, qr));
    if(qr > mid)
        cmx(res, query(rt->rc, mid + 1, r, ql, qr));
    return res;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n), compress;
    for(int i = 0; i < n; ++i)
    {
        cin >> v[i];
        compress.push_back(v[i]);
    }
    ranges::sort(compress);
    compress.erase(unique(all(compress)), compress.end());
    vector dp(2, vector<int>(n, 1));
    Node *rt1 = new Node(), *rt2 = new Node();
    for(int i = 0; i < n; ++i)
    {
        int rk = lower_bound(all(compress), v[i]) - compress.begin() + 1;
        
    }
}

int main()
{
    (cin.tie(0))->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}