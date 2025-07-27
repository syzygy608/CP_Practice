#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using i64 = long long;
#define all(x) (x).begin(), (x).end()
#define F first
#define S second

int query(int a, int b, int c)
{
    cout << "? " << a << ' ' << b << ' ' << c << endl;
    int res;
    cin >> res;
    return res;
}

mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
void solve()
{
    int n;
    cin >> n;
    int a[3] = {1, 2, 3}, res;
    while(res = query(a[0], a[1], a[2]))
        a[rng() % 3] = res;
    cout << "! " << a[0] << ' ' << a[1] << ' ' << a[2] << '\n';
 }

int main()
{
    // (cin.tie(0))->sync_with_stdio(0);
    // cin.exceptions(cin.failbit);
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}