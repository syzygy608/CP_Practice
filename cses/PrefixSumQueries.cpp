#include <iostream>

using namespace std;
typedef long long ll;
const int maxn = 2e5 + 5;

struct Node
{
    ll sum, pref;
}seg[maxn << 2];
int arr[maxn];

void merge(Node &a, Node b, Node c)
{
    a.sum = b.sum + c.sum;
    a.pref = max(b.pref, b.sum + c.pref);
}

void build(int idx, int l, int r)
{
    if(l == r)
    {
        seg[idx].sum = arr[l];
        seg[idx].pref = max(0, arr[l]);
        return;
    }
    int mid = (l + r) / 2;
    build(idx << 1, l, mid);
    build(idx << 1 | 1, mid + 1, r);
    merge(seg[idx], seg[idx << 1], seg[idx << 1 | 1]);
}

void update(int idx, int l, int r, int pos, int val)
{
    if(l == r)
    {
        seg[idx].sum = val;
        seg[idx].pref = max(0, val);
        return;
    }
    int mid = (l + r) / 2;
    if(pos <= mid)
        update(idx << 1, l, mid, pos, val);
    else
        update(idx << 1 | 1, mid + 1, r, pos, val);
    merge(seg[idx], seg[idx << 1], seg[idx << 1 | 1]);
}

Node query(int idx, int l, int r, int ql, int qr)
{ 
    if(ql <= l && r <= qr)
        return seg[idx];
    int mid = (l + r) / 2;
    Node ans = {0, 0}, tmp1 = {0, 0}, tmp2 = {0, 0};
    if(ql <= mid)
        tmp1 = query(idx << 1, l, mid, ql, qr);
    if(qr > mid)
        tmp2 = query(idx << 1 | 1, mid + 1, r, ql, qr);
    merge(ans, tmp1, tmp2);
    return ans;
}
    
int main()
{
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; ++i)
        cin >> arr[i];
    build(1, 1, n);
    for(int i = 0; i < q; ++i)
    {
        int op, a, b;
        cin >> op >> a >> b;
        if(op == 1)
            update(1, 1, n, a, b);
        else
            cout << query(1, 1, n, a, b).pref << '\n';
    }
    return 0;
}