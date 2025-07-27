#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define all(x) (x).begin(), (x).end()
#define F first
#define S second

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt[2]{};
    for(char c: s)
    {
        if(c == '_')
            cnt[0]++;
        else
            cnt[1]++;
    }
    i64 a = cnt[1] / 2;
    i64 b = cnt[1] - a;
    cout << a * b * cnt[0] << '\n';
}

int main()
{
    (cin.tie(0))->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}