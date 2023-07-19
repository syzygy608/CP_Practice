#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
int arr[200005];

struct Segment
{
    struct Node
    {
        ll sum, pref, suf, ans;
        void Merge(Node a, Node b)
        {
            pref = max(a.pref, a.sum + b.pref);
            suf = max(a.suf + b.sum, b.suf);
            sum = a.sum + b.sum;
            ans = max(a.ans, max(b.ans, a.suf + b.pref));
        }
    };
    vector<Node> data;
    Segment(int n)
    {
        data.resize((n + 1) << 2);
        build(1, 1, n);
    }
    void build(int id, int l, int r)
    {
        if(l == r)
        {
            data[id].ans = data[id].pref = data[id].suf = max(0, arr[l]);
            data[id].sum = arr[l];
            return;
        }
        int mid = (l + r) / 2;
        build(id << 1, l, mid);
        build(id << 1 | 1, mid + 1, r);
        data[id].Merge(data[id << 1], data[id << 1 | 1]);
    }
    void update(int id, int l, int r, int pos, int val)
    {
        if(l == r)
        {
            data[id].ans = data[id].pref = data[id].suf = max(0, val);
            data[id].sum = val;
            return;
        }
        int mid = (l + r) / 2;
        if(pos <= mid)
            update(id << 1, l, mid, pos, val);
        else
            update(id << 1 | 1, mid + 1, r, pos, val);
        data[id].Merge(data[id << 1], data[id << 1 | 1]);
    }
};

int main()
{
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; ++i)
        cin >> arr[i];
    Segment seg(n);
    for(int i = 0, l, r; i < q; ++i)
    {
        cin >> l >> r;
        seg.update(1, 1, n, l, r);
        cout << seg.data[1].ans << '\n';
    }
}
