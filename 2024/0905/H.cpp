#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    (cin.tie(0))->sync_with_stdio(0);
    int n, m, k, l;
    cin >> n >> m >> k >> l;
    k = n - k + 1;
    l = m - l + 1;
    vector<vector<ll>> v(n + 1, vector<ll>(m + 1, 0));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            int x;
            cin >> x;
            v[i][j] = v[i - 1][j] + v[i][j - 1] - v[i - 1][j - 1] + x;
        }
    }
    ll ans = 0;
    for(int i = k; i <= n; i++){
        for(int j = l; j <= m; j++){
            ll ret = abs(v[i][j] - v[i - k][j] - v[i][j - l] + v[i - k][j - l]);
            ans += ret;
        }
    }
    cout << ans << '\n';
}