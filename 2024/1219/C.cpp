#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define eb emplace_back
using namespace std;
using ll = long long;
const int INF = numeric_limits<int>::max() / 2;
const ll LINF = numeric_limits<ll>::max() / 2;

void solve()
{
    string s;
    cin >> s;
    int L = -1, n = s.size();
    for(int i = 0; i < n; ++i)
    {
        if(s[i] == '1')
        {
            L = i;
            break;
        }
    }

    int R = -1;
    for(int i = L; i < n; ++i)
    {
        if(s[i] == '0')
        {
            R = i;
            break;
        }
    }
    int len = n - R, ansL = 0, ansR = 0;
    string ans = s;
    for(int i = 0; i <= n - len; ++i)
    {
        string t = s;
        for(int j = 0; j < len; ++j)
        {
            if(s[i + len - j - 1] == s[n - j - 1])
                t[n - j - 1] = '0';
            else
                t[n - j - 1] = '1';
        }
        if(t > ans)
        {
            ans = t;
            ansL = i;
            ansR = i + len - 1;
        }
    }
    cout << L + 1 << ' ' << n << ' ' << ansL + 1 << ' ' << ansR + 1 << '\n';
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