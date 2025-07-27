#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define eb emplace_back
using namespace std;
using ll = long long;
const int INF = numeric_limits<int>::max() / 2;
const ll LINF = numeric_limits<ll>::max() / 2;

template <class T>
void chmin(T &a, T b)
{
    if(a > b)
        a = b;
}

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> pre(n, n + 1), suf(n, n + 1);
    for(int i = 0; i < n; ++i)
    {
        if(s[i] == 'p')
            pre[i] = i + 1;
        if(s[i] == 's')
            suf[i] = n - i;
    }
    for(int i = n - 2; i >= 0; --i)
        chmin(pre[i], pre[i + 1]);
    for(int i = 1; i < n; ++i)
        chmin(suf[i], suf[i - 1]);
    for(int i = 0; i < n; ++i)
        chmin(pre[i], suf[i]);
    sort(all(pre));
    for(int i = 1; i <= n; ++i)
    {
        if(pre[i - 1] < i)
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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