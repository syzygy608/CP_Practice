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
const int maxn = 1e5 + 5;

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for(auto &x : v)
        cin >> x;
    vector<ll> prefix(n + 1), sum(n + 1);
    for(int i = 0; i < n; ++i)
    {
        prefix[i + 1] = prefix[i] + (v[i] == 1);
        sum[i + 1] = sum[i] + v[i];
    }
    while(q--)
    {
        int l, r;
        cin >> l >> r;
        if(l == r)
        {
            cout << "NO\n";
            continue;
        }
        int no_one = prefix[r] - prefix[l - 1]; // 原本有多少個 1
        int can_be_one = r - l + 1 - no_one; // 剩下的貪心的全部變成 1
        ll can_used_sum = sum[r] - sum[l - 1] - can_be_one; // 還有多少可以用
        if(can_used_sum >= no_one * 2)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
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
