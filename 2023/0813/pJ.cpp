#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define _ << ' ' <<
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define IO (*cin.tie(0)).sync_with_stdio(0);

using namespace std;
using ll = long long;
const int maxn = 5e3 + 5;
bool v[maxn][maxn];
int main()
{
    IO
    int t;
    cin >> t;
    while(t--)
    {
        fill(v[0], v[maxn], false);
        int n, m;
        cin >> n >> m;
        int ans = m;
        for(int i = 0; i < m; ++i)
        {
            string s;
            cin >> s;
            for(int j = 0; j < n; ++j)
                if(s[j] == '1')
                    v[i][j] = true;
        }
        bool flag = false;
        for(int i = 0; i < (1 << m); ++i)
        {
            bool state[n] = {};
            for(int j = 0; j < m; ++j)
                if(i & (1 << j))
                    for(int k = 0; k < n; ++k)
                        state[k] |= v[j][k];
            int cnt = 0;
            for(int j = 0; j < n; ++j)
                if(state[j])
                    ++cnt;
            if(cnt == n)
            {
                flag = true;
                ans = min(ans, __builtin_popcount(i));
            }
        }
        cout << ((flag) ? ans : -1) << '\n';
    }
    return 0;
}
