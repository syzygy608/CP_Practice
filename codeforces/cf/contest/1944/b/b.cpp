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
const int maxn = 5e4 + 5;

void solve()
{
    /*
    n = 4
    1 1 2 2 3 3 4 4
    1 1 2 3 2 3 4 4
    
    */
    int n, k;
    cin >> n >> k;
    map<int, vector<int>> cnt1, cnt2;
    for(int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        cnt1[x].pb(i + 1);
    }
    for(int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        cnt2[x].pb(i + 1);
    }
    int check = 0, check2 = 0;
    for(int i = 1; i <= n; ++i)
        if(cnt1[i].size() == 1)
            check++;
    k *= 2;
    vector<pair<int, int>> v1, v2;
    int tmp = k;
    if(k <= check)
    {
        for(int i = 1; i <= n && k; ++i)
        {
            if(cnt1[i].size() == 1)
            {
                k--;
                v1.pb({cnt1[i][0], i});
                v2.pb({cnt2[i][0], i});
                cnt1[i].clear();
                cnt2[i].clear();
            }
        }
    }
    else
    {
        if((k - check) % 2 == 1)
            check--;
        int tmp = k - check;
        int tmp2 = k - check;
        for(int i = 1; i <= n && check; ++i)
        {
            if(cnt1[i].size() == 1)
            {
                check--;
                v1.pb({cnt1[i][0], i});
                v2.pb({cnt2[i][0], i});
                cnt1[i].clear();
                cnt2[i].clear();
            }
        }
        for(int i = 1; i <= n && tmp; ++i)
        {
            if(cnt1[i].size() == 2)
            {
                tmp -= 2;
                v1.pb({cnt1[i][0], i});
                v1.pb({cnt1[i][1], i});
                cnt1[i].clear();
            }
        }
        for(int i = 1; i <= n && tmp2; ++i)
        {
            if(cnt2[i].size() == 2)
            {
                tmp2 -= 2;
                v2.pb({cnt2[i][0], i});
                v2.pb({cnt2[i][1], i});
                cnt2[i].clear();
            }
        }
    }
    sort(all(v1));
    sort(all(v2));
    for(auto i: v1)
        cout << i.S << ' ';
    cout << '\n';
    for(auto i: v2)
        cout << i.S << ' ';
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
