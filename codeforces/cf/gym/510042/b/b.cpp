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
ll ans = 1ll<<60;
vector<ll> cnt;
int n, k;

void valid(ll x)
{
    int pr = 0, l = 0, r = k - 1;
    while(l <= r)
    {
        pr++;
        if(l == r)
            break;
        if(cnt[l] + cnt[r] <= x)
            l++, r--;
        else
            r--;
    }
    ans = min(ans, pr * x);
}

void solve()
{
    cin >> n >> k;
    cnt.resize(k);
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        x--;
        cnt[x]++;
    }
    sort(all(cnt));
    for(ll i = cnt[k - 1]; i <= cnt[k - 1] + cnt[max(k - 2, 0)]; ++i)
        valid(i);
    cout << ans << '\n';
}

int main()
{
    IO;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}
