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
    int ans = 0;
    for(int i = 0; i <= 31; ++i)
    {
        if((1 << i) > n)
            break;
        ans = (1 << i);
    }
    cout << ans << '\n';

    // for(int i = 1; i <= 10; ++i)
    // {
    //     vector<int> v(i);
    //     iota(all(v), 1);
    //     for(int j = 2; j <= i; ++j)
    //     {
    //         for(int k = j - 1; k >= 1; --k)
    //         {
    //             if(j % k == 0)
    //             {
    //                 swap(v[j - 1], v[k - 1]);
    //                 break;
    //             }
    //         }
    //     }
    //     for(auto x : v)
    //         cout << x << ' ';
    //     cout << '\n';
    // }
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
