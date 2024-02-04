#include <bits/stdc++.h>

#define IO (cin.tie(0))->sync_with_stdio(0);
#define F first
#define S second
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define _ << ' ' <<

using namespace std;
using ll = long long;

const int maxn = 1e5 + 5;

void sol()
{
    int k;
    string s1, s2;
    cin >> k >> s1 >> s2;
    int same = 0, diff = 0;
    for(int i = 0; i < sz(s1); ++i)
    {
        if(s1[i] == s2[i])
            same++;
        else
            diff++;
    }
    cout << min(same, k) + min(sz(s1) - same, sz(s1) - k) << '\n';   
}

int main()
{
    IO
    int t = 1;
    // cin >> t;
    while(t--)
        sol();
    return 0;
}
