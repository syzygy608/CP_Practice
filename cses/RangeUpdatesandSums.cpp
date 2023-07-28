#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
const int maxn = 1e3 + 5;

struct SegmentTree
{
    struct Node
    {
        ll val;
        ll add_tag, set_tag;

        Node(): val(0), add_tag(0), set_tag(0) {}
        Node operator + (const Node &rhs) const
        {
            Node ret;
            ret.val = val + rhs.val;
            return ret;
        }
    };
    int inline id(int l, int r)
    {
        return (l + r) | (l != r);
    }
    int n;
    vector<Node> tree;
    SegmentTree(int n): n(n), tree(n << 1){}
    void push_up(int l, int r)
    {
        int mid = (l + r) >> 1;
        tree[id(l, r)] = tree[id(l, mid)] + tree[id(mid + 1, r)];
    }
    void pull_down(int l, int r)
    {
        int mid = (l + r) >> 1;
        if(tree[id(l, r)].set_tag)
        {
            tree[id(l, mid)].set_tag = tree[id(mid + 1, r)].set_tag = tree[id(l, r)].set_tag;
            tree[id(l, mid)].val = tree[id(mid + 1, r)].val = tree[id(l, r)].set_tag * (mid - l + 1);
            tree[id(l, mid)].add_tag = tree[id(mid + 1, r)].add_tag = 0;
            tree[id(l, r)].set_tag = 0;
        }
        else if(tree[id(l, r)].add_tag)
        {
            if(tree[id(l, mid)].set_tag)
                tree[id(l, mid)].add_tag += tree[id(l, r)].add_tag;
            else
            {
                tree[id(l, mid)].set_tag += tree[id(l, r)].add_tag;
                tree[id(l, mid)].add_tag = 0;
            }
            if(tree[id(mid + 1, r)].set_tag)
                tree[id(mid + 1, r)].add_tag += tree[id(l, r)].add_tag;
            else
            {
                tree[id(mid + 1, r)].set_tag += tree[id(l, r)].add_tag;
                tree[id(mid + 1, r)].add_tag = 0;
            }
            tree[id(l, mid)].val += tree[id(l, r)].add_tag * (mid - l + 1);
            tree[id(mid + 1, r)].val += tree[id(l, r)].add_tag * (r - mid);
            tree[id(l, r)].add_tag = 0;
        }
    }
    void build(int l, int r, vector<int> &a)
    {
        tree[id(l, r)].set_tag = tree[id(l, r)].add_tag = 0;
        if(l == r)
        {
            tree[id(l, r)].val = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(l, mid, a);
        build(mid + 1, r, a);
        push_up(l, r);
    }
    void update1(int l, int r, int ql, int qr, int val)
    {
        if(ql <= l && r <= qr)
        {
            tree[id(l, r)].val += val * (r - l + 1);
            if(tree[id(l, r)].set_tag)
                tree[id(l, r)].set_tag += val;
            else
                tree[id(l, r)].add_tag += val;
            return;
        }
        pull_down(l, r);
        int mid = (l + r) >> 1;
        if(ql <= mid)
            update1(l, mid, ql, qr, val);
        if(qr > mid)
            update1(mid + 1, r, ql, qr, val);
        push_up(l, r);
    }
    void update2(int l, int r, int ql, int qr, int val)
    {
        if(ql <= l && r <= qr)
        {
            tree[id(l, r)].val = val * (r - l + 1);
            tree[id(l, r)].set_tag = val;
            tree[id(l, r)].add_tag = 0;
            return;
        }
        pull_down(l, r);
        int mid = (l + r) >> 1;
        if(ql <= mid)
            update1(l, mid, ql, qr, val);
        if(qr > mid)
            update1(mid + 1, r, ql, qr, val);
        push_up(l, r);
    }
    Node query(int l, int r, int ql, int qr)
    {
        if(ql <= l && r <= qr)
            return tree[id(l, r)];
        pull_down(l, r);
        int mid = (l + r) >> 1;
        Node ret;
        if(ql <= mid)
            ret = ret + query(l, mid, ql, qr);
        if(qr > mid)
            ret = ret + query(mid + 1, r, ql, qr);
        return ret;
    }
};

int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    SegmentTree st(n);
    st.build(1, n, a);
    while(q--)
    {
        int op, l, r, val;
        cin >> op >> l >> r;
        if(op == 1)
        {
            cin >> val;
            st.update1(1, n, l, r, val);
        }
        else if(op == 2)
        {
            cin >> val;
            st.update2(1, n, l, r, val);
        }
        else
            cout << st.query(1, n, l, r).val << '\n';
    }
}