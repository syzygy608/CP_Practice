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
    string a, b;
    cin >> a >> b;
    vector<pair<char, int>> v1, v2;
    for(char c: a)
    {
        if(v1.empty() || c != v1.back().F)
            v1.emplace_back(c, 1);
        else
            v1.back().S++;
    }
    for(char c: b)
    {
        if(v2.empty() || c != v2.back().F)
            v2.emplace_back(c, 1);
        else
            v2.back().S++;
    }
    if(v1.size() != v2.size())
        cout << "NO\n";
    else
    {
        for(int i = 0; i < (int)v1.size(); ++i)
        {
            if(v1[i].F != v2[i].F || v2[i].S < v1[i].S || v2[i].S > 2 * v1[i].S)
            {
                cout << "NO\n";
                return;
            }
        }
        cout << "YES\n";
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