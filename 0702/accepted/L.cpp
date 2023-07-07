#include <bits/stdc++.h>

#define IO (cin.tie(0))->sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define _ << ' ' <<
using namespace std;
typedef long long ll;
const int mxn = 1e5 + 5;
const int mod = 1e9 + 7;
const int inf32 = 1 << 30;
const ll inf64 = 1ll << 60;

ll fact(ll n)
{
    ll ret = 1;
    for(int i = 1; i <= n; ++i)
        ret *= i;
    return ret;
}

int main()
{
    IO
    /*
        if x % head, y % tail
        n ^ x * m ^ y
        代表要公平分類的話，就是把所有 n, m 組合分配給兩個人
        若該類有奇數個，多的要丟出來(答案+1)
        ans = sum (c^n_i % 2)
        n = 10^18 ..
        c^3_0 = 1
        c^3_1 = 3
        c^3_2 = 3 
        c^3_3 = 1  
    */
    ll n;
    cin >> n;
    /*
    for(int j = 2; j <= 10; ++j)
    {
        cout << j << ": ";
        int ans = 0;
        for(int i = 0; i <= j; ++i)
        {
            int tmp = (fact(j) / (fact(i) * fact(j - i))) % 2;
            ans += tmp;
        }
        int ans2 = 0;
        for(int i = 0; i < 60; ++i)
            if(j & (1ll << i))
                ans2++;
        cout << ans2 << ": " << ans;
        cout << '\n';
    }
    */
    // ans = 2 ^ ans2;
    ll ans2 = 0;
    for(ll i = 0; i < 60; ++i)
        if(n & (1ll << i))
            ans2++;
    cout << (1ll << ans2) << '\n';
    return 0;
}