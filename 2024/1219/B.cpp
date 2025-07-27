#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define eb emplace_back
using namespace std;
using ll = long long;
const int INF = numeric_limits<int>::max() / 2;
const ll LINF = numeric_limits<ll>::max() / 2;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    iota(all(v), 1);
    int L = 0, R = n - 1;
    for(int i = 0; i < n / k; ++i)
    {
        for(int j = 0; j < k; ++j)
        {
            if(j == k - 1)
                cout << v[L++];
            else
                cout << v[R--];
            cout << ' ';
        }
    }
    for(int i = 0; i < (n % k); ++i)
    {
        if(!i)
            cout << v[L++];
        else
            cout << v[R--];
        cout << ' ';
    }
    cout << '\n';
}

int main()
{
    (*cin.tie(0)).sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}