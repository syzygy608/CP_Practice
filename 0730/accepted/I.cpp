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
const int maxn = 1e5 + 5;

ll sol(ll a, ll b)
{
    if(b >= a)
        return a;
    if(a <= 2ll * b)
        return (a - b) * 3ll + b;
    return 4ll * (a - b) + sol(a - 2ll * b, b);
}

int main()
{
    IO
    ll a, b;
    cin >> a >> b;
    cout << sol(a, b) - b << '\n';
    return 0;
}