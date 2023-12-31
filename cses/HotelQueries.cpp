#include <iostream>
#include <vector>

using namespace std;

const int maxn = 2e5 + 5;
struct Node
{
    int idx;
    int space;
    Node(int a = 0, int b = 0) : idx(a), space(b){}
};
Node segment[maxn << 2];
int n, m, arr[maxn];

Node merge(const Node a, const Node b)
{
    if(a.space > b.space)
        return a;
    else
        return b;
}

void build(int idx, int l, int r)
{
    if(l == r)
    {
        segment[idx].idx = l;
        segment[idx].space = arr[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(idx << 1, l, mid);
    build(idx << 1 | 1, mid + 1, r);
    segment[idx] = merge(segment[idx << 1], segment[idx << 1 | 1]);
}

Node query(int idx, int l, int r, int q)
{
    if(l == r)
    {
        Node tmp = segment[idx];
        segment[idx].space -= q;
        return tmp;
    }
    Node temp(0, 0);
    int mid = (l + r) >> 1;
    if(segment[idx << 1].space >= q)
        temp = merge(temp, query(idx << 1, l, mid, q));
    else
        temp = merge(temp, query(idx << 1 | 1, mid + 1, r, q));
    segment[idx] = merge(segment[idx << 1], segment[idx << 1 | 1]);
    return temp;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        cin >> arr[i];
    build(1, 1, n);
    for(int i = 0, num; i < m; ++i)
    {
        cin >> num;
        if(num > segment[1].space)
            cout << "0 ";
        else
        {
            Node q = query(1, 1, n, num);
            cout << q.idx << ' ';
        }
    }
    return 0;
}