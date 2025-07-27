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
    int n;
    cin >> n;
    vector<int> v(n), cnt(n + 1);
    for(int i = 0; i < n; ++i)
    {
        cin >> v[i];
        cnt[v[i]]++;
    }
    if(!cnt[0])
        cout << "1\n1 " << n << '\n';
    else
    {
        if(v[0])
            cout << "2\n2 " << n << "\n1 2\n";
        else if(v[n - 1])
            cout << "2\n1 " << n - 1 << "\n1 2\n";
        else
            cout << "3\n1 " << n - 2 << "\n2 3\n1 2\n";
    }
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