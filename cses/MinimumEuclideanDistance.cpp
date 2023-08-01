#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

#define X first
#define Y second
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using Pt = pair<ll, ll>;
vector<Pt> v;

ll dis(Pt a, Pt b)
{
    return (a.X - b.X) * (a.X - b.X) + (a.Y - b.Y) * (a.Y - b.Y);
}

ll sol(int l, int r)
{
    if(l == r)
        return INT64_MAX;
    int mid = (l + r) / 2;
    ll midx = v[mid].X;
    ll ret = min(sol(l, mid), sol(mid + 1, r));
    vector<Pt> t;
    
    t.assign(r - l + 1, {0, 0});
    merge(v.begin() + l, v.begin() + mid + 1, v.begin() + mid + 1, v.begin() + r + 1, t.begin(), [&](Pt a, Pt b)
    {
        return a.Y < b.Y;
    });
    for(int i = l; i <= r; ++i)
        v[i] = t[i - l];
    t.clear();
    for(int i = l; i <= r; ++i)
        if(abs(v[i].X - midx) * abs(v[i].X - midx) <= ret)
            t.push_back(v[i]);
    int len = t.size();
    for(int i = 0; i < len; ++i)
    {
        for(int j = i + 1; j < len; ++j)
        {
            ret = min(ret, dis(t[i], t[j]));
            if(abs(t[i].Y - t[j].Y) * abs(t[i].Y - t[j].Y) > ret)
                break;
        }
    }
    return ret;
}

int main()
{
    int n;
    cin >> n;
    v.assign(n, {0, 0});
    for(Pt &e: v)
        cin >> e.X >> e.Y;
    sort(all(v));
    cout << sol(0, n - 1) << '\n';
}