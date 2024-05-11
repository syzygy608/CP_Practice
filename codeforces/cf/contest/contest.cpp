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
    int n, m;
    cin >> n >> m;
    string s1, s2;
    cin >> s1 >> s2;
    int cnt1[2] = {0}, cnt2[2] = {0};
    int l = 0, r = 0, ans = 0;
    while(l < n)
    {
        // cerr << l _ r << '\n';
        cnt1[s1[l] - '0']++;
        while(r < m && (cnt2[0] < cnt1[0] || cnt2[1] < cnt1[1]))
        {
            cnt2[s2[r] - '0']++;
            r++;
        }
        if(cnt2[0] >= cnt1[0] && cnt2[1] >= cnt1[1])
        {
            ans = max(ans, l + 1);
            cnt1[0] = cnt1[1] = 0;
            cnt2[0] = cnt2[1] = 0;
        }
        l++;
    }
    cout << ans << '\n';
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
