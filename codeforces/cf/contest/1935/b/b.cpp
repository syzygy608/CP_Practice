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
const int maxn = 1e5 + 5;

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(int &x : v)
        cin >> x;
    map<int, vector<int>> cnt;
    for(int i = 0; i < n; i++)
        cnt[v[i]].pb(i);
    if(sz(cnt) == 1 || cnt.find(0) == cnt.end())
    {
        cout << n << '\n';
        for(int i = 1; i <= n; ++i)
            cout << i _ i << '\n';
    }
    else
    {
        int last = -1, target = -1;
        for(int i = 0; i < n; ++i)
        {
            if(sz(cnt[i]) < 2)
            {
                target = last;
                break;
            }
            last = i;
        }
        int idx = cnt[0][0];
        for(int i = 0; i <= target; ++i)
            idx = max(idx, cnt[i][0]); // 至少有 0 ~ target 的區間
        auto get_mex = [&](multiset<int> &s) -> int
        {
            for(int i = 0; i < n; ++i)
                if(s.find(i) == s.end())
                    return i;
            return n;
        };
        multiset<int> s1, s2;
        for(int i = 0; i <= idx; ++i)
            s1.insert(v[i]);
        for(int i = idx + 1; i < n; ++i)
            s2.insert(v[i]);
        if(get_mex(s1) == get_mex(s2))
        {
            cout << "2\n";
            cout << 1 _ idx + 1 << '\n';
            cout << idx + 2 _ n << '\n';
            return;
        }
        cout << "-1\n";
    }
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