#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define eb emplace_back
using namespace std;
using ll = long long;
const int INF = numeric_limits<int>::max() / 2;
const ll LINF = numeric_limits<ll>::max() / 2;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(auto &i: v)
        cin >> i;
    vector<int> cnt(k);
    map<int, vector<int>> mp;
    for(int i = 0; i < n; ++i)
    {
        cnt[v[i] % k]++;
        mp[v[i] % k].eb(i + 1);
    }
    for(int i = 0; i < k; ++i)
    {
        if(cnt[i] == 1)
        {
            cout << "YES\n";
            cout << mp[i].front() << '\n';
            return;
        }
    }
    cout << "NO\n";
}

int main()
{
    (*cin.tie(0)).sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}