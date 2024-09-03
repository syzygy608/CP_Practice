#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void sol()
{
    int n, m, E;
    cin >> n >> m >> E;
    map<int, int> cnt;
    for(int i = 0, u, v; i < n + m; ++i)
    {
        cin >> u >> v;
        cnt[u]++;
        cnt[v + 1]--;
    }
    int last_idx = 0, sum = 0;
    for(auto i: cnt)
    {
        if(sum == 2)
            E -= i.first - last_idx - 1;
        sum += i.second;
        last_idx = i.first;
    }
    cout << max(-1, E) << '\n';
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)
        sol();
    return 0;
}
