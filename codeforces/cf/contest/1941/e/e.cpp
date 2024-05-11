#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define _ << ' ' << 
#define sz(a) ((int)(a).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define IO (*cin.tie(0)).sync_with_stdio(0);

using namespace std;
typedef long long ll;
const int maxn = 2e5 + 5;

struct SegmentTree
{
    struct Node
    {
        ll mn;
        Node() : mn(0) {}
    };
    vector<Node> nodes;
    void init(int n)
    {
        nodes.resize(n << 2);
    }
    void build(int i, int l, int r, vector<ll> &a)
    {
        if(l == r)
        {
            nodes[i].mn = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(i << 1, l, mid, a);
        build(i << 1 | 1, mid + 1, r, a);
        nodes[i].mn = min(nodes[i << 1].mn, nodes[i << 1 | 1].mn);
    }
    void update(int i, int l, int r, int x, ll v)
    {
        if(l == r)
        {
            nodes[i].mn = v;
            return;
        }
        int mid = (l + r) >> 1;
        if(x <= mid)
            update(i << 1, l, mid, x, v);
        else
            update(i << 1 | 1, mid + 1, r, x, v);
        nodes[i].mn = min(nodes[i << 1].mn, nodes[i << 1 | 1].mn);
    }
    ll query(int i, int l, int r, int ql, int qr)
    {
        if(ql <= l && r <= qr)
            return nodes[i].mn;
        int mid = (l + r) >> 1;
        ll ret = 9e18;
        if(ql <= mid)
            ret = min(ret, query(i << 1, l, mid, ql, qr));
        if(qr > mid)
            ret = min(ret, query(i << 1 | 1, mid + 1, r, ql, qr));
        return ret;
    }
};

void solve()
{
    int n, m, k, d;
    cin >> n >> m >> k >> d;
    vector<vector<int>> mp(n + 1, vector<int>(m + 1));
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            cin >> mp[i][j];
    vector<ll> dp(m + 1, 9e18);
    ll ans = 9e18;
    SegmentTree st;
    for(int i = 1; i + k - 1 <= n; ++i)
    {
        // 枚舉每 k 個列
        for(int j = 0; j < k; ++j)
        {
            for(int l = 2; l <= m - 1; ++l)
            {
                if(!j)
                    dp[l] = mp[i + j][l] + 1; // 第一列，答案最好就是自己
                else
                {
                    int mn = st.query(1, 1, m, max(2, l - d), l);
                    dp[l] = min(dp[l], mn + mp[i + j][l] + 1ll); // 答案是最小值加上自己
                }
            }
            st.init(m + 1);
            st.build(1, 1, m, dp); // 更新線段樹
        }
        // 最後一列的答案是最小值
        for(int l = 2; l <= m - 1; ++l)
        {
            ans = min(ans, dp[l]);
            cerr << dp[l] << ' ';
        }
        fill(all(dp), 9e18);
    }
    // 最左跟最右一定要蓋，所以答案要加 2
    cout << ans + 2 << '\n';
}

int main()
{
    IO;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
