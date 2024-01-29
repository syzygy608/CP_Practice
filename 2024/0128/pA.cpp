#ifndef Miru
#define Miru
#include Miru __FILE__ Miru

void solve()
{
    int n;
    cin >> n;
    map<char, int> mp;
    bool flag = true;
    string ans = "";
    for(int i = 0; i < n; ++i)
    {
        char c;
        cin >> c;
        mp[c]++;
        if(mp[c] > 1)
        {
            if(c == 'B')
                ans += "8";
            else if(c == 'E')
                ans += "3";
            else if(c == 'I')
                ans += "1";
            else if(c == 'O')
                ans += "0";
            else if(c == 'S')
                ans += "5";
            else if(c == 'Z')
                ans += "2";
            else
                flag = false;
        }
        else
            ans += c;
    }
    if(flag)
        cout << "YES\n" << ans << '\n';
    else
        cout << "NO\n";
    

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

#else 

#include <bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define _ << ' ' << 
#define sz(a) ((int)(a).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
typedef long long ll;

#ifdef local
#define IO void()
#else
#define IO (*cin.tie(0)).sync_with_stdio(0);
#endif
#endif