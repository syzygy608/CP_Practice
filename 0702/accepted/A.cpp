#include <bits/stdc++.h>

#define IO (cin.tie(0))->sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define _ << ' ' <<
using namespace std;
typedef long long ll;
const int mxn = 1e4 + 5;
const int mod = 1e9 + 7;
const int inf32 = 1 << 30;
const ll inf64 = 1ll << 60;
int p[mxn];
int n, m, k;
vector<array<int, 3>> g;

int search(int x)
{
    return (p[x] < 0) ? x : p[x] = search(p[x]);
}

bool merge(int x, int y)
{
    int px = search(x), py = search(y);
    if(px == py)
        return false;
    p[py] += p[px];
    p[px] = py;
    return true; 
}

bool check(int i, int j)
{
    bool ok = (g[j][0] - g[i][0]) * (g[j][0] - g[i][0]) + (g[j][1] - g[i][1]) * (g[j][1] - g[i][1]) <= (g[j][2] + g[i][2]) * ((g[j][2] + g[i][2]));
    return ok;
}

int main()
{
    IO
    cin >> m >> n >> k;
    memset(p, -1, sizeof(p));
    for(int i = 0, x, y, s; i < k; ++i)
    {
        cin >> x >> y >> s;
        g.push_back({x, y, s});
    }
    for(int i = 0; i < k; ++i)
    {
        for(int j = i + 1; j < k; ++j)
            if(check(i, j))
                merge(i, j);
        if(g[i][0] + g[i][2] >= m)
            merge(i, k);
        if(g[i][0] - g[i][2] <= 0)
            merge(i, k + 1);
        if(g[i][1] + g[i][2] >= n)
            merge(i, k + 2);
        if(g[i][1] - g[i][2] <= 0)
            merge(i, k + 3);
    }
    bool ans = true;
    for(int i = 0; i < k; ++i)
    {
        if(search(k) == search(k + 1))
        {
            //cerr << 1;
            ans = false;
        }
        if(search(k + 1) == search(k + 3))
        {
            //cerr << 2;
            ans = false;
        }
        if(search(k + 3) == search(k + 2))
        {
            //cerr << 3;
            ans = false;
        }
        if(search(k) == search(k + 2))
        {
            //cerr << 4;
            ans = false;
        }
    }
    if(ans)
        puts("S");
    else
        puts("N");
    return 0;
}