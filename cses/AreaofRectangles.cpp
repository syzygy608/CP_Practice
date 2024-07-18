#include <iostream>
#include <vector>
#include <algorithm>
#include <array>

using namespace std;
using ll = long long;

struct SegmentTree
{
    struct Node
    {
        ll num, union_num;
        Node() : num(0), union_num(0) {}
    };
    vector<Node> tree;
    int n;
    SegmentTree(int n) : n(n)
    {
        tree.resize(2 * n);
    }
    int id(int l, int r)
    {
        return l + r | l != r;
    }
    void pull(int l, int r)
    {
        int m = (l + r) >> 1;
        if(tree[id(l, r)].num)
            tree[id(l, r)].union_num = r - l;
        else if(r - l != 1)
            tree[id(l, r)].union_num = tree[id(l, m)].union_num + tree[id(m + 1, r)].union_num;
        else
            tree[id(l, r)].union_num = 0;
    }
    void build(int l, int r)
    {
        if(r - l == 1)
            return;
        int m = (l + r) >> 1;
        build(l, m);
        build(m, r);
        pull(l, r);
    }
    void update(int l, int r, int ql, int qr, int val)
    {
        if(ql >= r || qr <= l)
            return;
        if(ql <= l && r <= qr)
        {
            tree[id(l, r)].num += val;
            pull(l, r);
            return;
        }
        int m = (l + r) >> 1;
        update(l, m, ql, qr, val);
        update(m, r, ql, qr, val);
        pull(l, r);
    }
};

int main()
{
    int n;
    cin >> n;
    vector<array<int, 3>> rec;
    for(int i = 0; i < n; ++i)  
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1 += 1e6 + 1;
        y1 += 1e6 + 1;
        x2 += 1e6 + 1;
        y2 += 1e6 + 1;
        rec.push_back({x1, y1, y2});
        rec.push_back({-x2, y1, y2});
    }
    sort(rec.begin(), rec.end(), [](const array<int, 3> &a, const array<int, 3> &b)
    {
        if(abs(a[0]) == abs(b[0]))
            return a[0] < b[0];
        return abs(a[0]) < abs(b[0]);
    });
    int cur_x = abs(rec[0][0]);
    ll ans = 0;
    SegmentTree st(2000001);
    st.build(1, 2000001);
    for(auto &i : rec)
    {
        cerr << st.tree[st.id(1, st.n)].union_num << "\n";
        ans += st.tree[st.id(1, st.n)].union_num * (abs(i[0]) - cur_x);
        if(i[0] > 0)
            st.update(1, 2000001, i[1], i[2], 1);
        else
            st.update(1, 2000001, i[1], i[2], -1);
        cur_x = abs(i[0]);
    }
    cout << ans << "\n";
}