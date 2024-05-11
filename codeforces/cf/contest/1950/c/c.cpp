#include <bits/stdc++.h>

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
    int h, m;
    char c;
    scanf("%d%c%d", &h, &c, &m);
    int sum = h * 60 + m;
    if(sum < 60 * 12)
    {
        if(h == 0)
            h = 12;
        printf("%02d%c%02d AM\n", h, c, m);
    }
    else
    {
        if(h != 12)
        {
            sum -= 60 * 12;
            h = sum / 60;
            m = sum % 60;
        }
        printf("%02d%c%02d PM\n", h, c, m);
    }
}

int main()
{
    // IO;
    int t = 1;
    // cin >> t;
    scanf("%d", &t);
    while(t--)
        solve();
    return 0;
}
