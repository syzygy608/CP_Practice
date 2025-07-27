#include <bits/stdc++.h>

#define sz(a) ((int)(a).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define IO (*cin.tie(0)).sync_with_stdio(0);
using namespace std;
using ll = long long;

ll ceilDiv(ll n, ll m)
{
    if(n >= 0)
        return (n + m - 1) / m;
    else
        return n / m;
}

ll floorDiv(ll n, ll m)
{
    if(n >= 0)
        return n / m;
    else 
        return (n - m + 1) / m;
}

void sol()
{
    
}

int main()
{
    IO
    cin.exceptions(cin.failbit);
    int n;
    cin >> n;
    string s;
    getline(cin, s);
    cout << s << '\n';
    return 0;
}