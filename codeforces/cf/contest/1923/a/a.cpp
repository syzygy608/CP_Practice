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
    vector<int> v(n);
    for(auto &x : v)
        cin >> x;
    int l = -1, r = -1;
    for(int i = 0; i < n; ++i)
    {
        if(v[i])
        {
            l = i;
            break;
        }
    }
    for(int i = n - 1; i >= 0; --i)
    {
        if(v[i])
        {
            r = i;
            break;
        }
    }
    int cnt = 0;
    for(int i = l; i <= r; ++i)
        if(v[i] == 0)
            cnt++;
    cout << cnt << '\n';
    
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
