#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define all(x) (x).begin(), (x).end()
#define F first
#define S second

void solve()
{
    int x;
    cin >> x;
    int cnt[32]{}, high = 0;
    for(int i = 0; i < 32; ++i)
        if(x >> i & 1)
            cnt[i]++, high = i;
    int one = count(cnt, cnt + high, 0), zero = count(cnt, cnt + high, 1);
    if(one == 0 || zero == 0)
        cout << "-1\n";
    else
    {
        int y = (x ^ ((1<<(high+1)) - 1)) + (x & (-x));
        cout << y << '\n';
        // cerr << x << ' ' << y << ' ' << (x ^ y) << '\n';
    }
}

int main()
{
    (cin.tie(0))->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}