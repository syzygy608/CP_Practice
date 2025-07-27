#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define eb emplace_back
using namespace std;
using ll = long long;
const int INF = numeric_limits<int>::max() / 2;
const ll LINF = numeric_limits<ll>::max() / 2;
const double EPS = 1e-12;


void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, int>> v;
    for(int i = 0, x; i < n; ++i)
    {
        cin >> x;
        if(v.empty() || x <= v.back().first)
            v.eb(x, 1);
        else
        {
            v.back().first = x;
            v.back().second++;
        }
    }
    if(k < v.size() || k > n)
        cout << "-1\n";
    else
    {
        int idx = 1;
        int share = k - (int)v.size();
        for(auto &i: v)
        {
            bool f = false;
            cout << idx << ' ';
            i.second--;
            while(share > 0 && i.second > 0)
            {
                cout << ++idx << ' ';
                share--;
                i.second--;
            }
            while(i.second > 0)
            {
                cout << idx << ' ';
                i.second--;
            }
            idx++;
        }
    }
}
int main()
{
    cin.exceptions(cin.failbit);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}