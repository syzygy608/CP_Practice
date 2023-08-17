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
    int t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        // ll ans = 0;
        // int b = -1;
        // for(int i = n + 1; i <= 10'000'000; ++i)
        // {
        //     if((i * n) % (i - n) == 0)
        //     {
        //         ll tmp = (i * n) / (i - n); // a ^ b;
        //         tmp ^= i;
        //         if(tmp > ans)
        //         {
        //             ans = tmp;
        //             b = i;
        //         }
        //     }
        // }
        // cout << b << ' ';
        // cout << ans << '\n';
        ll b = n + 1;
        ll axorb = b * n;
        cout << (axorb ^ b) << '\n';
    }
    return 0;
}
