#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define _ << ' ' <<
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define IO (*cin.tie(0)).sync_with_stdio(0);

using namespace std;
using ll = long long;
const int maxn = 1e5 + 5;

int main()
{
    IO
    ll n, m;
    cin >> n >> m;
    cout << (n * (n + 1) / 2) * (m * (m + 1) / 2) << '\n'; 
    return 0;
}