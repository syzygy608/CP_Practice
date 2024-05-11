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
    vector<array<int, 2>> v(n + 1);
    for(int i = 1; i <= n; ++i)
        v[i][0] = v[i][1] = i; // [l, r]
    int highest = 1, count = 0;
    vector<int> cnt(n + 1, 0), pos(n + 1, 0), sop(n + 1, 0);
    for(int i = 1; i <= n; ++i)
    {
        pos[i] = i; // Pos[i] 位置元素是 i
        sop[i] = i; // i 在 sop[i] 位置
    }
    for(int i = 0; i < m; ++i)
    {
        int x;
        cin >> x;
        cnt[x]++;
        if(cnt[x] > count)
        {
            // 交換 x 和 pos[sop[x] - 1]
            int pos_x = sop[x]; // x 在 pos_x 位置
            int pos_pre_x = sop[x] - 1; // x 的前一個位置
            int who_pre_x = pos[pos_pre_x]; // x 的前一個位置的元素
            swap(pos[pos_x], pos[pos_pre_x]);
            swap(sop[x], sop[who_pre_x]);
            v[who_pre_x][1] = max(v[who_pre_x][1], v[x][1]);
            v[x][0] = min(v[x][0], v[who_pre_x][0]);
            highest = x;
            count = cnt[x];
        }
        else if(cnt[x] == highest)
            count++;
    }
    for(int i = 1; i <= n; i++)
        cout << v[i][0] _ v[i][1] << '\n';
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
