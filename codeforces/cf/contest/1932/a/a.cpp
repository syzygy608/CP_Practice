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
    char last = '!';
    string s;
    cin >> s;
    int ans = 0;
    for(int i = 0; i < n; ++i)
    {
        char c = s[i];
        if(c == last && last == '*')
            break;
        if(c == '@')
            ans++;
        last = c;
    }
    cout << ans << '\n';

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
