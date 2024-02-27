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
    char trump;
    cin >> trump;
    vector<pair<int, char>> normal, trumps;
    for(int i = 0; i < 2 * n; ++i)
    {
        char c;
        int x;
        cin >> x >> c;
        if(c == trump)
            trumps.pb({x, c});
        else
            normal.pb({x, c});
    }
    sort(all(trumps));
    if(trumps.size() >= n)
    {
        while(sz(trumps) && sz(normal))
        {
            auto a = trumps.back();
            trumps.pop_back();
            auto b = normal.back();
            normal.pop_back();
            cout << b.F << b.S << ' ' << a.F << a.S << '\n';
        }
        while(sz(trumps) > 1)
        {
            auto a = trumps.back();
            trumps.pop_back();
            auto b = trumps.back();
            trumps.pop_back();
            cout << b.F << b.S << ' ' << a.F << a.S << '\n';
        }
    }
    else
    {
        vector<pair<int, char>> types_cards[4];
        for(auto i : normal)
        {
            if(i.S == 'C')
                types_cards[0].pb(i);
            else if(i.S == 'D')
                types_cards[1].pb(i);
            else if(i.S == 'H')
                types_cards[2].pb(i);
            else
                types_cards[3].pb(i);
        }
        for(int i = 0; i < 4; ++i)
            sort(all(types_cards[i]), greater<pair<int, char>>());
        vector<pair<pair<int, char>, pair<int, char>>> ans;
        for(int i = 0; i < 4; ++i)
        {
            while(sz(types_cards[i]) > 1)
            {
                auto a = types_cards[i].back();
                types_cards[i].pop_back();
                auto b = types_cards[i].back();
                types_cards[i].pop_back();
                ans.pb({a, b});
            }
        }
        while(sz(trumps) && sz(ans) < n && (sz(types_cards[0]) || sz(types_cards[1]) || sz(types_cards[2]) || sz(types_cards[3])))
        {
            auto a = trumps.back();
            trumps.pop_back();
            for(int i = 0; i < 4; ++i)
            {
                if(sz(types_cards[i]))
                {
                    auto b = types_cards[i].back();
                    types_cards[i].pop_back();
                    ans.pb({b, a});
                    break;
                }
            }
        }
        
        while(sz(trumps) > 1 && sz(ans) < n)
        {
            auto a = trumps.back();
            trumps.pop_back();
            auto b = trumps.back();
            trumps.pop_back();
            ans.pb({b, a});
        }
        if(sz(ans) < n)
        {
            cout << "IMPOSSIBLE\n";
            return;
        }
        for(auto i : ans)
            cout << i.F.F << i.F.S << ' ' << i.S.F << i.S.S << '\n';
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
