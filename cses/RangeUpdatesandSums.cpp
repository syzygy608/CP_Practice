#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int maxn = 2e5 + 5;

struct Node
{
    int l, r;
    short lazy_type;
    ll tag, sum;
    Node *lc, *rc;
    Node () {}
    Node(int l, int r) : l(l), r(r), lazy_type(0), tag(0), sum(0), lc(nullptr), rc(nullptr) {}
}node[maxn << 1], *last_node = node, *root;
ll a[maxn];

void build(Node *rt, int l, int r)
{
    rt->l = l, rt->r = r;
    if(l == r)
    {
        rt->sum = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    rt->lc = ++last_node;
    rt->rc = ++last_node;
    build(rt->lc, l, mid);
    build(rt->rc, mid + 1, r);
    rt->sum = rt->lc->sum + rt->rc->sum;
}

void setup_tag(Node *rt, int type, ll val);
void push(Node *rt);
void update(Node *rt, int l, int r, int tupe, ll val);
ll query(Node *rt, int l, int r);

int main()
{
    (cin.tie(0))->sync_with_stdio(0);
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    build(root = ++last_node, 1, n);
    while(q--)
    {
        int type, l, r;
        ll val;
        cin >> type >> l >> r;
        if(type == 1 || type == 2)
        {
            cin >> val;
            update(root, l, r, type, val);
        }
        else
            cout << query(root, l, r) << '\n';
    }
    return 0;
}

void push(Node *rt)
{
    if(!rt->lazy_type)
        return;
    if(rt->lazy_type == 1)
        rt->sum += (rt->r - rt->l + 1) * rt->tag;
    else 
        rt->sum = (rt->r - rt->l + 1) * rt->tag;
    int type = rt->lazy_type;
    rt->lazy_type = 0;
    ll tag = rt->tag;
    rt->tag = 0;
    if(rt->lc)
        setup_tag(rt->lc, type, tag);
    if(rt->rc)
        setup_tag(rt->rc, type, tag);
}

void setup_tag(Node *rt, int type, ll val)
{
    if(rt->lazy_type == 1 && type == 1)
    {
        rt->tag += val;
        return;
    }
    if(type == 1)
        push(rt);
    rt->lazy_type = type;
    rt->tag = val;
}

void update(Node *rt, int l, int r, int tpye, ll val)
{
    if(rt->l == l && rt->r == r)
    {
        setup_tag(rt, tpye, val);
        push(rt);
        return;
    }
    push(rt);
    int mid = (rt->l + rt->r) >> 1;
    if(r <= mid)
        update(rt->lc, l, r, tpye, val);
    else if(l > mid)
        update(rt->rc, l, r, tpye, val);
    else
    {
        update(rt->lc, l, mid, tpye, val);
        update(rt->rc, mid + 1, r, tpye, val);
    }
    if(rt->lc->tag)
        push(rt->lc);
    if(rt->rc->tag)
        push(rt->rc);
    rt->sum = rt->lc->sum + rt->rc->sum;
}

ll query(Node *rt, int l, int r)
{
    push(rt);
    if(rt->l == l && rt->r == r)
        return rt->sum;
    int mid = (rt->l + rt->r) >> 1;
    if(r <= mid)
        return query(rt->lc, l, r);
    else if(l > mid)
        return query(rt->rc, l, r);
    else
        return query(rt->lc, l, mid) + query(rt->rc, mid + 1, r);
}