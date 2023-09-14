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
const int maxn = 1e5 + 5;

bool ok(int val, vector<int> &v, int dis)
{
    int t = 0, cnt = 0;
    for(int i = 0; i < val; ++i)
    {
        if(t + v[i] <= dis)
        {
            cnt++;
            t++;
        }
    }
    return cnt == val;
}

void sol()
{
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    vector<int> v(m);
    for(int &i: v)
        cin >> i;
    sort(rall(v));
    int ans = 0;
    int dis = 0;
    if(a < b)
        dis = b - 1;
    else
        dis = n - b;
    int now = 1;
    for(int i = 0; i < m; ++i)
    {
        if(now + v[i] <= dis)
        {
            now++;
            ans++;
        }
    }
    ans = min(ans, abs(b - a) - 1);
    cout << ans << '\n';
}

int main()
{
    IO
    int t;
    cin >> t;
    while(t--)
        sol();
    return 0;
}

/*
3
8
1 2 7 3 2 1 2 3
1 2 3 2 1 1 2
2
2 1
1
7
4 1 5 2 6 3 7
1 1 2 2 3 3
*/ 