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
    string v[2];
    cin >> v[0] >> v[1];
    int pos = n - 1;
    for(int i = 0; i < n - 1; ++i)
    {
        if(v[0][i + 1] == '1' && v[1][i] == '0')
        {
            pos = i;
            break;
        }
    }
    string ans = v[0].substr(0, pos + 1) + v[1].substr(pos);
    cout << ans << '\n';
    int cnt = 1;
    for(int i = pos; i > 0; --i)
    {
        if(v[0][i] == v[1][i - 1])
            ++cnt;
        else
            break;
    }
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
