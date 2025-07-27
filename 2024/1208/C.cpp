#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define eb emplace_back
using namespace std;
using ll = long long;
const int INF = numeric_limits<int>::max() / 2;
const ll LINF = numeric_limits<ll>::max() / 2;

void solve()
{
    // ll n, k;
    // cin >> n >> k;
    // 1, 2, 4, 8, 16, 32, 64, 128
    // 1, 4, 10, 20, 35, 56, 84, 120
    /*
        4 2 3 1
        -       4
        ---     2
        -----   2
        ------- 1
          -     2
          ---   2
          ----- 1
            -   3
            --- 1
              - 1
        4 6 6 4 
    */
    int n = 4;
    vector<int> p(n);
    iota(all(p), 1);
    do
    {
        int s = 0;
        for(int i = 0; i < n; ++i)
        {
            int mn = n + 1;
            for(int j = i; j < n; ++j)
            {
                mn = min(mn, p[j]);
                s += mn;
            }
            cout << p[i] << " ";
        }
        cout << ": " << s << '\n';
    }while(next_permutation(all(p)));
}

int main()
{
    (*cin.tie(0)).sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}