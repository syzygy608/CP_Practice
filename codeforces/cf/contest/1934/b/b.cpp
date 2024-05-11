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

int tri[] = {15, 10, 6, 3, 1};
int dp[maxn];

int memo(int n)
{
    memset(dp, 0x3f, sizeof dp);
    dp[0] = 0;
    for(int i = 1; i <= n; ++i)
        for(int j = 0; j < 5; ++j)
            if(i >= tri[j])
                dp[i] = min(dp[i], dp[i - tri[j]] + 1);
    return dp[n];
}

void solve()
{
    int n;
    cin >> n;;
    // 一個整數可以被三個三角形數表示
    for(int i = 0; i < 5; ++i)
    {
        if(n >= tri[i])
        {
            int ret = n / tri[i] - 1; 
            n %= tri[i];
            n += tri[i];
            ret += memo(n);
            cout << ret << '\n';
            break;
        }
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
