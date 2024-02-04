#include <bits/stdc++.h>

#define IO (cin.tie(0))->sync_with_stdio(0);
#define F first
#define S second
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define _ << ' ' <<

using namespace std;
using ll = long long;

const int maxn = 1e5 + 5;

void sol()
{
    int n, s, mx = 0;
    cin >> n >> s;
    for(int i = 0, num; i < n; ++i)
    {
        cin >> num;
        mx = max(mx, num);
    }
    cout << (mx * s + 999) / 1000 << '\n';
}

int main()
{
    IO
    int t = 1;
    // cin >> t;
    while(t--)
        sol();
    return 0;
}
