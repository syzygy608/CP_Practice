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
    vector<string> s(n);
    vector<vector<int>> v(n);
    for(int i = 0; i < n; ++i)
        cin >> s[i];
    string t;
    cin >> t;
    int m = t.size(), res = 0;
    for(int i = 0; i < m; ++i)
    {
        bool f = false;
        for(int j = 0; j < n; ++j)
        {
            auto it = s[j].find(t[i]);
            if(it != string::npos)
            {
                f = true;
                // cout << it << '\n';
                if(v[j].empty() || v[j].back() + 1 != it)
                {
                    if(s[j].size() == 1)
                    {
                        res++;
                        continue;
                    }
                    if(it == 0)
                        v[j].push_back(0);
                    else
                    {
                        cout << "No\n";
                        return;
                    }
                }
                else
                {
                    v[j].back()++;
                    if(v[j].back() + 1 == s[j].size())
                    {
                        res++;
                        v[j].pop_back();
                    }
                }
                break;
            }
        }
        if(!f)
        {
            cout << "No\n";
            return;
        }
    }
    for(int i = 0; i < n; ++i)
    {
        if(!v[i].empty())
        {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n" << res + 1 << '\n';
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