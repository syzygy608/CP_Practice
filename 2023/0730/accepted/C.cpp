#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define _ << ' ' << 
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define IO (*cin.tie(0)).sync_with_stdio(0);

using namespace std;
typedef long long ll;
const int maxn = 2e7 + 5;
bitset<maxn> vis;
int main()
{
    IO
    ll p, n;
    cin >> p >> n;
    n = min(n, 2 * p);
    ll tmp = 0;
    for(int i = 0; i <= n; ++i)
    {
        tmp += i;
        vis.set(tmp % p);
    }
    cout << vis.count() << '\n';
    return 0;
}