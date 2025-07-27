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
    vector<int> v(n);
    int cnt[9] = {3, 1, 2, 1, 0, 1};
    for(int i = 0; i < n; ++i)
        cin >> v[i];
    for(int i = 0; i < n; ++i)
    {
        if(cnt[v[i]])
            cnt[v[i]]--;
        bool f = true;
        for(int j = 0; j < 6; ++j)
        {
            if(cnt[j])
            {
                f = false;
                break;
            }
        }
        if(f)
        {
            cout << i + 1 << '\n';
            return;
        }
    }
    cout << "0\n";
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