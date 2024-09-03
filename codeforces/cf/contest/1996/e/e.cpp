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
const int mod = 1e9 + 7;

void solve()
{
    string s;
    cin >> s;
    ll ans = 0;
    vector<int> pre(sz(s) + 1);
    for(int i = 0; i < sz(s); i++)
    {
        pre[i + 1] = pre[i];
        pre[i + 1] += (s[i] == '1' ? 1 : -1);
    }
    vector<ll> cnt(sz(s) * 2 + 1);
    for(int i = 0; i <= sz(s); ++i)
    {
        int cur = pre[i] + sz(s);
        ans = (ans + (cnt[cur] % mod) * ((sz(s) - i + 1LL) % mod) + mod) % mod;
        cnt[cur] = (cnt[cur] + i + 1) % mod;
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
