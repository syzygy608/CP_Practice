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

vector<int> adj[maxn];

void solve()
{
    int n;
    cin >> n;
    vector<string> v(n);
    for(int i = 0; i < n; ++i)
        cin >> v[i];
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            if(v[i][j] == '1')
                adj[i].pb(j);
    vector<int> vis(n, 0);
    vector<int> ans;
    vis[0] = true;
    queue<int> q;
    q.push(0);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        ans.pb(u);
        for(auto i: adj[u])
            if(!vis[i])
                vis[i] = true, q.push(i);
    }
    bool ok = true;
    for(int i = 0; i < n; ++i)
        if(!vis[i])
            ok = false;
    if(ok)
    {
        reverse(all(ans));
        for(auto i: ans)
            cout << i << ' ';
    }
    else
        cout << "impossible\n";
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
