#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int N = 2e5 + 5;

struct Node
{
    int L, R;
    i64 val;
    Node *lc, *rc;
    void pull()
    {
        val = min(lc->val, rc->val);
    }
};

i64 arr[N];
void build(Node *r, int L, int R)
{
    r->L = L, r->R = R;
    if(L == R)
    {
        r->val = arr[L];
        return;
    }
    int M = (L + R) / 2;
    build(r->lc = new Node(), L, M);
    build(r->rc = new Node(), M + 1, R);
    r->pull();
}

i64 query(Node *r, int ql, int qr, i64 val)
{
    if(r->val > val)
        return 1ll<<60;
    if(r->L == r->R)
        return r->val;
    int M = (r->L + r->R) / 2;
    i64 ret = 1ll<<60;
    if(r->lc->val <= val && M >= ql)
        ret = min(ret, query(r->lc, ql, qr, val));
    if(ret == 1ll<<60 && qr > M)
        ret = min(ret, query(r->rc, ql, qr, val));
    return ret;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; ++i)
        cin >> arr[i];
    Node *root = new Node();
    build(root, 1, n);
    for(int i = 0; i < q; ++i)
    {
        i64 v, l, r;
        cin >> v >> l >> r;
        // cerr << i << '\n';
        while(true)
        {
            i64 ret = query(root, l, r, v);
            if(ret == 1ll<<60)
                break;
            // cerr << "get: " << ret << '\n';
            v %= ret;
        }
        cout << v << '\n';
    }
    return 0;
}