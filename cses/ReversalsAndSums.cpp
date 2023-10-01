#include <bits/stdc++.h>

using namespace std;
using ll = long long;

mt19937 mtrd(chrono::steady_clock::now().time_since_epoch().count());
struct Treap
{
    int key;
    int pri, sz, tag;
    ll sum;
    Treap *l, *r;
    Treap(){}
    Treap(int c): key(c), pri(mtrd()), sz(1), tag(0), sum(c), l(NULL), r(NULL) {}
    void flip()
    {
        tag ^= 1;
        swap(l, r);
    }
    ~Treap()
    {
        if(l)
            delete l;
        if(r)
            delete r;
    }
} *root;

inline int getSz(Treap *t)
{
    return t?t->sz:0;
}

inline ll getSum(Treap *t)
{
    return t?t->sum:0;
}

void pull(Treap *t)
{
    t->sz = 1 + getSz(t->l) + getSz(t->r);
    t->sum = t->key + getSum(t->l) + getSum(t->r);
}

void push(Treap *t)
{
    for(auto ch : {t->l, t->r})
        if(ch && t->tag)
            ch->flip();
    t->tag = 0;
}

void split(Treap *t, Treap *&a, Treap *&b, int k)
{
    if(!t)
        a = b = NULL;
    else if(getSz(t->l) + 1 <= k)
    {
        a = t;
        push(a);
        split(t->r, a->r, b, k - getSz(t->l) - 1);
        pull(a);
    }
    else
    {
        b = t;
        push(b);
        split(t->l, a, b->l, k);
        pull(b);
    }
}

Treap* merge(Treap* a, Treap* b)
{
    if(!a || !b)
        return a ? a : b;
    if(a->pri > b->pri)
    {
        push(a);
        a->r = merge(a->r, b);
        pull(a);
        return a;
    }
    else
    {
        push(b);
        b->l = merge(a, b->l);
        pull(b);
        return b;
    }
}

void reverse(Treap *&t, int l, int r)
{
    Treap *a, *b, *c;
    split(t, a, b, l - 1);
    split(b, b, c, r - l + 1);
    b->flip();
    t = merge(merge(a, b), c);
}

void output(Treap *&t, int l, int r)
{
    Treap *a, *b, *c;
    push(t);
    split(t, a, b, l - 1);
    split(b, b, c, r - l + 1);
    cout << getSum(b) << '\n';
    t = merge(merge(a, b), c);
}

int main()
{
    root = NULL;
    int n, q;
    cin >> n >> q;
    for(int i = 0, x; i < n; ++i)
    {
        cin >> x;
        root = merge(root, new Treap(x));
    }
    while(q--)
    {
        int op, l, r;
        cin >> op >> l >> r;
        if(op == 1)
            reverse(root, l, r);
        else
            output(root, l, r);
    }
    return 0;
}