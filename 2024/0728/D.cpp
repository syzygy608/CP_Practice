#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void sol()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    map<int, int> cnt;
    i64 ans = 0;
    for(int i = 0; i < n; ++i)
    {
        cin >> v[i];
        ans += cnt[v[i] ^ k];
        cnt[v[i]]++;
    }
    cout << ans << '\n';
    
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
        sol();
    return 0;
}
