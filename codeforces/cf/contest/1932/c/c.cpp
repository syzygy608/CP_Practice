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
    int n, m;
    cin >> n >> m;
    deque<pair<int, int>> v(n);
    for(int i = 0; i < n; i++)
    {
        cin >> v[i].F;
        v[i].S = i;
    }
    deque<pair<int, int>> v2 = v;
    string s;
    cin >> s;
    for(int i = 0; i < sz(s) - 1; i++)
    {
        if(s[i] == 'L')
            v.pop_front();
        else
            v.pop_back();
    }
    vector<ll> ans;
    ans.push_back(v[0].F % m);
    int l = v[0].S, r = v[0].S;
    for(int i = sz(s) - 2; i >= 0; --i)
    {
        if(s[i] == 'L')
            ans.push_back((v2[--l].F * ans.back()) % m);
        else
            ans.push_back((v2[++r].F * ans.back()) % m);
    }
    reverse(all(ans));
    for(auto i : ans)
        cout << i << ' ';
    cout << '\n';
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
