#include <bits/stdc++.h>

#define IO (cin.tie(0))->sync_with_stdio(0);
#define F first
#define S second
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define _ << ' ' <<

using namespace std;
using ll = long long;

const int maxn = 1e5 + 5;

void sol()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for(auto &i: v)
        cin >> i.F >> i.S;
    for(int i = n; i >= 0; --i)
    {
        int cnt = 0;
        for(int j = 0; j < n; ++j)
            if(v[j].F <= i && i <= v[j].S)
                cnt++;
        if(cnt == i)
        {
            cout << i << '\n';
            return;
        }
    }
    cout << "-1\n";
}

int main()
{
    IO
    int t = 1;
    // cin >> t;
    while(t--)
        sol();
    return 0;
}
