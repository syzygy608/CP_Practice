#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define AnNinMiRu (*cin.tie(0)).sync_with_stdio(0);
#define eb emplace_back
#define X first
#define Y second
#define _ << ' ' <<
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(x) ((int)(x).size())

const int maxn = 2e5 + 5;

void sol()
{
    char s[maxn];
    cin >> s;
    char *p = s;
    vector<int> pos;
    while((p = strstr(p, "happiness")))
    {
        pos.eb(p - s);
        p += 9;
    }
    if(sz(pos) > 2)
        cout << "NO\n";
    else if(sz(pos) == 0)
    {
        string t = s;
        string r = t;
        for(int i = 1; i < sz(t); ++i)
        {
            swap(r[0], r[i]);
            if(r.find("happiness") == string::npos)
            {
                cout << "YES\n";
                cout << 1 << ' ' << i + 1 << '\n';
                return;
            }
            swap(r[0], r[i]);
        }
    }
    else if(sz(pos) == 2)
    {
        cout << "YES\n";
        cout << pos[0] + 1 << ' ' << pos[1] + 2 << '\n';
    }
    else
    {
        cout << "YES\n";
        cout << pos[0] + 1 << ' ' << pos[0] + 2 << '\n';
    }
}

signed main()
{
    AnNinMiRu
    int t = 1;
    // cin >> t;
    while(t--)
        sol();
    return 0;
}