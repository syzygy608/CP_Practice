#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define eb emplace_back
using namespace std;
using ll = long long;
const int INF = numeric_limits<int>::max() / 2;
const ll LINF = numeric_limits<ll>::max() / 2;

void solve()
{
    int a, b;
    cin >> a >> b;
    vector<int> prefix(2025, 0);
    for(int i = 2022; i <= 2024; ++i)
        prefix[i] = prefix[i - 1] + 5;
    int q = prefix[b] - prefix[a - 1];
    if(!q)
        cout << "Too Early!!!\n";
    else
        cout << q << '\n';
}

int main()
{
    (*cin.tie(0)).sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}