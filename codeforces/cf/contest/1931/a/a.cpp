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

map<int, string> mp;

void build()
{
    for(char i = 'a'; i <= 'z'; ++i)
    {
        for(char j = 'a'; j <= 'z'; ++j)
        {
            for(char k = 'a'; k <= 'z'; ++k)
            {
                string s = "";
                s += i;
                s += j;
                s += k;
                int num = i + j + k - 3 * ('a' - 1);
                if(mp.find(num) == mp.end())
                    mp[num] = s;
            }
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    cout << mp[n] << '\n';
}

int main()
{
    build();
    IO;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
