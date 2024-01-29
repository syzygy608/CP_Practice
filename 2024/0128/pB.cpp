#ifndef Miru
#define Miru
#include Miru __FILE__ Miru

void solve()
{
    int n;
    cin >> n;
    cout << n * (n - 2) << '\n';
}

int main()
{
    IO;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}

#else 

#include <bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define _ << ' ' << 
#define sz(a) ((int)(a).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
typedef long long ll;

#ifdef local
#define IO void()
#else
#define IO (*cin.tie(0)).sync_with_stdio(0);
#endif
#endif