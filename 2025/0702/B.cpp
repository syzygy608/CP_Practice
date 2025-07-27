#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define all(x) (x).begin(), (x).end()
#define F first
#define S second

constexpr i64 MOD = 1e9 + 7;

template<class T>
static void cmn(T &a, T b) { a = (a <=> b > 0) ? b : a; }
template<class T>
static void cmx(T &a, T b) { a = (a <=> b < 0) ? b : a; }

void solve()
{
    int n, j, k;
    cin >> n >> j >> k;
    vector<int> v(n);
    int cnt = 0, gt = 0;
    for(int i = 0; i < n; ++i)
        cin >> v[i];
    for(int i = 0; i < n; ++i)
    {
        if(i == j - 1)
            continue;
        if(v[i] == v[j - 1])
            cnt++;
        else if(v[i] > v[j - 1])
            gt++;
    }
    if(!gt)
        cout << "YES\n";
    else if(k != 1)
        cout << "YES\n";
    else
        cout << "NO\n";
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