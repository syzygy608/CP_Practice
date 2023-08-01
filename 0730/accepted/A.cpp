#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define _ << ' ' << 
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define IO (*cin.tie(0)).sync_with_stdio(0);

using namespace std;
typedef long long ll;
const int maxn = 5e5 + 5;
map<int, int> vis;

int main()
{
    IO
    int n;
    cin >> n;
    vector<int> v(n + 1, 0), ans(n + 1, 1);
    for(int i = 1; i <= n; ++i)
        cin >> v[i];
    int cur = 1;
    for(int i = 1; i <= n; ++i)
    {
        while(cur <= n)
        {
            if(v[cur] > 0 && vis[-v[cur]] > 0)
                break;   
            vis[v[cur++]]++;
        }
        ans[i] = cur - i;
        vis[v[i]]--;
    }
    for(int i = 1; i <= n; ++i)
        cout << ans[i] << ' ';
    return 0;
}