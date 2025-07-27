#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
using i64 = long long;
#define all(x) (x).begin(), (x).end()
#define F first
#define S second

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> RBT;

void solve()
{
    // 2 1 1 4 3 3 1
    // 0 1 2 3 4 5 6
    // -1 0 1 2 3 5 6
    // -2 -1 0 2 3 5 6
    // -3 -1 0 2 3 5 6
    RBT t;
    int n, q;
    cin >> n >> q;
    vector<int> pos(n, -1);
    for(int i = 0, x; i < n; ++i)
    {
        cin >> x;
        x--;
        if(pos[x] == -1)
            pos[x] = i;
        t.insert(i);
    }
    int now = 0;
    for(int i = 0, x; i < q; ++i)
    {
        cin >> x;
        x--;
        int ans = t.order_of_key(pos[x]);
        // cout << "pos: " << pos[x] << '\n';
        cout << ans + 1 << '\n';
        t.erase(t.find_by_order(ans));
        pos[x] = --now;
        t.insert(pos[x]);
    }
}

int main()
{
    (cin.tie(0))->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}