#include <bits/stdc++.h>

#define X first
#define Y second
#define all(x) ((x).begin(), (x).end())
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;

void sol()
{
    int n, m;
    cin >> n >> m;
    int left = n - 2 * m;
    ll ans = 1, sum = 0;
    auto calc = [&](ll x) -> ll
    {
        return (x * (x + 1)) / 2;
    };
    for(int i = 0; i < m; ++i)
    {
        ans = (ans * calc(sum + 1)) % MOD;
        sum += 2;
    }
    for(int i = 0; i < left; ++i)
    {
        ans = (ans * (sum + 1)) % MOD;
        sum++;
    }
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)
        sol();
}

