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
    int n, q;
    cin >> n >> q;
    vector<array<int, 26>> p(n + 1);
    string a, b;
    cin >> a;
    cin >> b;
    for(int i = 0; i < n; i++)
    {
        p[i + 1] = p[i];
        p[i + 1][a[i] - 'a']++;
        p[i + 1][b[i] - 'a']--;
    }
    while(q--)
    {
        int l, r;
        cin >> l >> r;
        int ans = 0;
        for(int i = 0; i < 26; i++)
            ans += max(0, p[r][i] - p[l - 1][i]);
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
