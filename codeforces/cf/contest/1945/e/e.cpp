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
    int n, x;
    cin >> n >> x;
    vector<int> v(n + 1);
    int idx = -1;
    for(int i = 1; i <= n; ++i)
    {
        cin >> v[i];
        if(v[i] == x)
            idx = i;
    }
    int l = 1, r = n + 1, mid;
    while(r - l > 1)
    {
        mid = (l + r) / 2;
        if(v[mid] <= x)
            l = mid;
        else
            r = mid;
    }
    cout << "1\n" << l _ idx << '\n';
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
