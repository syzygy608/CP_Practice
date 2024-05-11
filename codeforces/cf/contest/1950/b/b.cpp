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
    int flag = 0;
    for(int i = 1; i <= (n << 1); ++i)
    {
        int flag2 = 0;
        for(int j = 1; j <= (n << 1); ++j)
        {
            if(!flag ^ flag2)
                cout << '#';
            else
                cout << '.';
            if(j % 2 == 0)
                flag2 ^= 1;
        }
        if(i % 2 == 0)
            flag ^= 1;
        cout << '\n';
    }
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
