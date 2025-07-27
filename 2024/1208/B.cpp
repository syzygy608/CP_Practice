#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define eb emplace_back
using namespace std;
using ll = long long;
const int INF = numeric_limits<int>::max() / 2;
const ll LINF = numeric_limits<ll>::max() / 2;

vector<ll> table;

void build()
{
    table.resize(20);
    table[1] = 1;
    for(int i = 2; i < 18; ++i)
        table[i] = (table[i - 1] + 1) * 2;
    // 1, 4, 10, 22,
}

void solve()
{
    int n;
    cin >> n;
    ll L = 1, R = 18, ans = 0;
    while(L <= R)
    {
        ll mid = (L + R) / 2;
        if(table[mid] <= n)
        {
            ans = mid;
            L = mid + 1;
        }
        else
            R = mid - 1;
    }
    if(table[ans] != n)
        ans++;
    cout << ans << '\n';
}

int main()
{
    (*cin.tie(0)).sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    build();
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}