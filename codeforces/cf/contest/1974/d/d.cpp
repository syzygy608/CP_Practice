#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <sstream>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <bitset>
#include <vector>
#include <utility>
#include <cassert>

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

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int l = 0, r = 0, u = 0, d = 0;
    for(auto i: s)
    {
        if(i == 'N')
            ++u;
        else if(i == 'S')
            ++d;
        else if(i == 'E')
            ++r;
        else
            ++l;
    }
    if(u % 2 == 0 && d % 2 != 0)
        cout << "NO\n";
    else if(d % 2 == 0 && u % 2 != 0)
        cout << "NO\n";
    else if(l % 2 == 0 && r % 2 != 0)
        cout << "NO\n";
    else if(r % 2 == 0 && l % 2 != 0)
        cout << "NO\n";
    else
    {
        string ans;
        int cnt[2][4] = {
            {u / 2, d / 2, l / 2, r / 2},
            {u / 2, d / 2, l / 2, r / 2}
        };
        if(u % 2 == 1 && d % 2 == 1)
        {
            if(cnt[0][0] + cnt[0][1] + cnt[0][2] + cnt[0][3] == 0)
            {
                cnt[0][0]++;
                cnt[0][1]++;
            }
            else
            {
                cnt[1][0]++;
                cnt[1][1]++;
            }
        }
        if(l % 2 == 1 && r % 2 == 1)
        {
            if(cnt[0][0] + cnt[0][1] + cnt[0][2] + cnt[0][3] == 0)
            {
                cnt[0][2]++;
                cnt[0][3]++;
            }
            else
            {
                cnt[1][2]++;
                cnt[1][3]++;
            }
        }
        for(int i = 0; i < n; ++i)
        {
            if(s[i] == 'N' && cnt[0][0] > 0)
            {
                --cnt[0][0];
                ans += 'R';
            }
            else if(s[i] == 'S' && cnt[0][1] > 0)
            {
                --cnt[0][1];
                ans += 'R';
            }
            else if(s[i] == 'E' && cnt[0][3] > 0)
            {
                --cnt[0][3];
                ans += 'R';
            }
            else if(s[i] == 'W' && cnt[0][2] > 0)
            {
                --cnt[0][2];
                ans += 'R';
            }
            else if(s[i] == 'N' && cnt[1][0] > 0)
            {
                --cnt[1][0];
                ans += 'H';
            }
            else if(s[i] == 'S' && cnt[1][1] > 0)
            {
                --cnt[1][1];
                ans += 'H';
            }
            else if(s[i] == 'E' && cnt[1][3] > 0)
            {
                --cnt[1][3];
                ans += 'H';
            }
            else if(s[i] == 'W' && cnt[1][2] > 0)
            {
                --cnt[1][2];
                ans += 'H';
            }
        }
        if(ans.find('H') == string::npos || ans.find('R') == string::npos)
            cout << "NO\n";
        else
            cout << ans << '\n';
    }
}

int main()
{
    IO;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
