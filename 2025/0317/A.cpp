#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define all(x) (x).begin(), (x).end()
#define F first
#define S second

void solve()
{
    i64 n, k;
    cin >> n >> k;
    if(n % 2 == 0)
        cout << n / (k - 1) + (n % (k - 1) != 0) << '\n';
    else
    {
        if((n - k) % 2 == 0)
        {
            n -= k;
            cout << 1 + n / (k - 1) + (n % (k - 1) != 0) << '\n';
        }
        else
        {
            if(n <= 2 * k)
                cout << 2 << '\n';
            else
            {
                n -= 2 * k;
                cout << 2 + n / (k - 1) + (n % (k - 1) != 0) << '\n';
            }
        }
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