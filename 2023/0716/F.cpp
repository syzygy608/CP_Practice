#include <bits/stdc++.h>

#define IO (cin.tie(0))->sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define _ << ' ' <<
using namespace std;
typedef long long ll;
const int mxn = 1e5 + 5;
const int mod = 1e9 + 7;
const int inf32 = 1 << 30;
const ll inf64 = 1ll << 60;

const int maxn = 405;
int p[maxn];

int find(int x)
{
    return p[x] < 0 ? x : p[x] = find(p[x]);
}

bool unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if(x == y)
        return false;
    if(p[x] > p[y])
        swap(x, y);
    p[x] += p[y];
    p[y] = x;
    return true;
}


int main()
{
    IO
    int n;
    cin >> n;
    memset(p, -1, sizeof(int) * (n + 1));
    string s[n];
    for(int i = 0; i < n; ++i)
    {
        cin >> s[i];
        while(1)
        {
            int pos = s[i].find("u");
            if(pos == string::npos)
                break;
            s[i].replace(pos, 1, "oo");
        }
        while(1)
        {
            int pos = s[i].find("kh");
            if(pos == string::npos)
                break;
            s[i].replace(pos, 2, "h");
        }
    }
    int ans = n;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            if(s[i] == s[j] && unite(i, j))
                --ans;
    cout << ans << '\n';
    return 0;
}