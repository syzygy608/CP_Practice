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
    int n;
    cin >> n;
    char c;
    vector<int> prefix(n + 1);
    for(int i = 1; i <= n; ++i)
    {
        cin >> c;
        if(c == '1')
            prefix[i] = prefix[i - 1] + 1;
        else
            prefix[i] = prefix[i - 1];
    }
    int ans = -1;
    for(int i = 0; i <= n; ++i)
    {
        // 切在 i 跟 i + 1 之間
        int left_zeros = i - prefix[i];
        int right_ones = prefix[n] - prefix[i];
        if(left_zeros >= (i + 1) / 2 && right_ones >= (n - i + 1) / 2 && abs(2 * i - n) < abs(2 * ans - n))
            ans = i;
    }
    cout << ans << '\n';
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
