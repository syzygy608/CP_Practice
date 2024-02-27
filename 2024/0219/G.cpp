#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int maxn = 1e5 + 5;

vector<int> G[maxn];
char c[maxn];
int ans = 0;

void dfs(int i, int par)
{
    int rets = 0, retp = 0;
    for(auto j : G[i])
    {
        if(j == par)
            continue;
        dfs(j, i);
        if(c[j] == 'S')
            rets++;
        else if(c[j] == 'P')
            retp++;
    }
    if(c[i] == 'S')
        ans += retp;
    if(c[i] == 'P')
        ans += rets;
    if(c[i] == 'C')
    {
        if(retp > rets)
        {
            c[i] = 'P';
            ans += rets;
        }
        else
        {
            c[i] = 'S';
            ans += retp;
        }
    }
}

void sol()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        G[i].clear();
    for(int i = 2; i <= n; i++)
    {
        int x;
        cin >> x;
        G[x].push_back(i);
        G[i].push_back(x);
    }
    for(int i = 1; i <= n; i++)
        cin >> c[i];
    dfs(1, 0);
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--)
        sol();
    return 0;
}