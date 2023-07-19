#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
int arr[200005];

struct Segment
{
    vector<ll> data;
    int type;
    Segment(int n, int _type)
    {
        type = _type;
        data.assign((n + 1) << 2, 0);
        build(1, 1, n);
    }
    void build(int id, int l, int r)
    {
        if(l == r)
        {
            data[id] = arr[l] + type * l;
            return;
        }
        int mid = (l + r) / 2;
        build(id << 1, l, mid);
        build(id << 1 | 1, mid + 1, r);
        data[id] = min(data[id << 1], data[id << 1 | 1]);
    }
    void update(int id, int l, int r, int pos, int val)
    {
        if(l == r)
        {
            data[id] = val + type * pos;
            return;
        }
        int mid = (l + r) / 2;
        if(pos <= mid)
            update(id << 1, l, mid, pos, val);
        else
            update(id << 1 | 1, mid + 1, r, pos, val);
        data[id] = min(data[id << 1], data[id << 1 | 1]);
    }
    ll query(int id, int l, int r, int ql, int qr)
    {
        if(ql <= l && r <= qr)
            return data[id];
        int mid = (l + r) / 2;
        ll ans = 1ll << 60;
        if(ql <= mid)
            ans = min(ans, query(id << 1, l, mid, ql, qr));
        if(qr > mid)
            ans = min(ans, query(id << 1 | 1, mid + 1, r, ql, qr));
        return ans;
    }
};

int main()
{
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; ++i)
        cin >> arr[i];
    Segment down(n, -1), up(n, 1);
    for(int i = 0; i < q; ++i)
    {
        int op, x, y;
        cin >> op;
        if(op == 1)
        {
            cin >> x >> y;
            down.update(1, 1, n, x, y);
            up.update(1, 1, n, x, y);
        }
        else
        {
            cin >> x;
            ll ans = 1ll << 60;
            ans = min(ans, down.query(1, 1, n, 1, x) + x);
            ans = min(ans, up.query(1, 1, n, x, n) - x);
            cout << ans << '\n';
        }
    }
}
