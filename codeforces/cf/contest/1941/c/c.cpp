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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    // mapie 
    const char *c = s.c_str();
    char *ptr = (char *)c;
    while((ptr = strstr(ptr, "mapie")) != NULL)
    {
        ans++;
        cerr << ptr[2];
        ptr[2] = '!';
        ptr += 4;
    }
    ptr = (char *)c;
    while((ptr = strstr(ptr, "map")) != NULL)
    {
        ans++;
        ptr[1] = '!';
        ptr += 2;
    }
    ptr = (char *)c;
    while((ptr = strstr(ptr, "pie")) != NULL)
    {
        ans++;
        ptr[1] = '!';
        ptr += 2;
    }
    cout << ans << '\n';
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
