#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define _ << ' ' <<
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define IO (*cin.tie(0)).sync_with_stdio(0);

using namespace std;
using ll = long long;
const int maxn = 1e6 + 5;

int parent[maxn], ans[maxn];

void make_set(int v)
{
    parent[v] = v;
}

void init(int n)
{
    for(int i = 0; i <= n; ++i)
        make_set(i);
}

int find_set(int v)
{
    return (parent[v] == v) ? v : parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b)
{
    int pa = find_set(a);
    int ppb = find_set(b);
    int mx = max(pa, ppb);
    parent[pa] = mx;
    parent[ppb] = mx;
}

int main()
{
    IO
    vector<array<int, 3>> v(1);
    vector<int> dis;
    int n;
    cin >> n;
    cin >> v[0][0] >> v[0][1] >> v[0][2];
    dis.pb(v[0][0]);
    dis.pb(v[0][1]);
    int mx = v[0][1], mn = v[0][0];
    for(int i = 0, l, r, c; i < n - 1; ++i)
    {
        cin >> l >> r >> c;
        mx = max(r, mx);
        mn = min(l, mn);
        v.push_back({l, r, c});
        dis.push_back(l);
        dis.push_back(r);
    }
    sort(all(dis));
    dis.resize(unique(all(dis)) - dis.begin());
    mx = lower_bound(all(dis), mx) - dis.begin() + 1;
    mn = lower_bound(all(dis), mn) - dis.begin() + 1;
    for(int i = 0; i < n; ++i)
    {
        v[i][0] = lower_bound(all(dis), v[i][0]) - dis.begin() + 1;
        v[i][1] = lower_bound(all(dis), v[i][1]) - dis.begin() + 1;
    }
    init(mx + 1);
    set<int> cnt;
    for(int i = n - 1; i >= 0; --i)
    {
        int l = v[i][0], r = v[i][1], c = v[i][2];
        for(int v = find_set(l); v <= r; v = find_set(v))
        {
            ans[v] = c;
            union_sets(v, v + 1);
        }
    }
    for(int i = mn; i <= mx; ++i)
        if(ans[i])
            cnt.insert(ans[i]);
    cout << cnt.size() << '\n';
    return 0;
}