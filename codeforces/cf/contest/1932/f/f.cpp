#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define _ << ' ' << 
#define sz(a) ((int)(a).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define IO (*cin.tie(0)).sync_with_stdio(0);

using namespace std;
typedef long long ll;
const int maxn = 1e6 + 5;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> v;
    vector<tuple<int, int, int>> arr;
    for(int i = 0; i < m; ++i)
    {
        int x, y;
        cin >> x >> y;
        v.pb({x, i});
        v.pb({-y, i});
        arr.push_back({x, y, i});
    }
    sort(all(arr), [](tuple<int, int, int> a, tuple<int, int, int> b){
        return get<1>(a) < get<1>(b);
    });
    set<int> select;
    int now = 0;
    for(auto [x, y, i] : arr)
    {
        if(now < x)
        {
            select.insert(i);
            now = y;
        }
    }
    int ans = 0, cnt = 0, mx = 0;
    set<int> interval;
    sort(all(v), [](pair<int, int> a, pair<int, int> b){
        return abs(a.F) != abs(b.F) ? abs(a.F) < abs(b.F) : a.F < b.F;
    });
    for(auto i: v)
    {
        if(i.F > 0)
        {
            cnt++;
            if(select.count(i.S))
                interval.insert(i.S);
        }
        else
        {
            cnt--;
            if(select.count(i.S))
                interval.erase(i.S);
        }
        if(sz(interval))
            mx = max(mx, cnt);
        if(!sz(interval))
        {
            cerr << mx << '\n';
            ans += mx;
            mx = 0;
        }
    }
    cerr << ans _ mx << '\n';
    if(mx)
        ans += mx;
    cout << ans << '\n';
}

int main()
{
    IO;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
