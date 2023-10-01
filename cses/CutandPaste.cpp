#include <bits/stdc++.h>

using namespace std;

mt19937 mtrd(chrono::steady_clock::now().time_since_epoch().count());
struct Treap
{
    char key;
    int pri, sz;
    Treap *l, *r;
    Treap(){}
    Treap(char c): key(c), pri(mtrd()), sz(1), l(NULL), r(NULL) {}
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

void pull(Treap *t)
{
    t->sz = 1 + getSz(t->l) + getSz(t->r);
}

void split(Treap *t, Treap *&a, Treap *&b, int k)
{
    if(!t)
        a = b = NULL;
    else if(getSz(t->l) + 1 <= k)
    {
        a = t;
        split(t->r, a->r, b, k - getSz(t->l) - 1);
        pull(a);
    }
    else
    {
        b = t;
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
        a->r = merge(a->r, b);
        pull(a);
        return a;
    }
    else
    {
        b->l = merge(a, b->l);
        pull(b);
        return b;
    }
}

void cutAndPaste(Treap *&t, int l, int r)
{
    Treap *a, *b, *c;
    split(t, a, b, l - 1);
    split(b, b, c, r - l + 1);
    t = merge(merge(a, c), b);
}

void output(Treap *t)
{
    if(!t)
        return;
    output(t->l);
    cout << t->key;
    output(t->r);
}

int main()
{
    root = NULL;
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n; ++i)
    {
        char x;
        cin >> x;
        root = merge(root, new Treap(x));
    }
    while(q--)
    {
        int l, r;
        cin >> l >> r;
        cutAndPaste(root, l, r);
    }
    output(root);
    return 0;
}