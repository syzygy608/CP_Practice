#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

struct DSU
{
    int n;
    vector<int> par, siz;
    DSU(int _n)
    {
        n = _n;
        par.resize(n);
        iota(par.begin(), par.end(), 0);
        siz.assign(n, 1);
    }
    int _find(int x)
    {
        return par[x] = (par[x] == x ? x : _find(par[x]));
    }
    bool _union(int x, int y)
    {
        int px = _find(x), py = _find(y);
        if(px == py)
            return false;
        if(siz[py] > siz[px])
            swap(px, py);
        siz[px] += siz[py];
        par[py] = px;
        return true;   
    }
};


void sol()
{
    int n, d;
    cin >> n >> d;
    DSU dsu(n);
    int free_op = 0;
    set<pair<int, int>> s1, s2;
    int ans = 1;
    s1.insert({-1, 0});
    for(int i = 1; i < n; ++i)
        s2.insert({-1, i});
    for(int i = 0, u, v; i < d; ++i)
    {
        cin >> u >> v;
        u--, v--;
        int pu = dsu._find(u);
        int pv = dsu._find(v);
        if(pu != pv)
        {
            // 有用的邊
            bool flag1 = false, flag2 = false;
            if(s1.size() && s1.find({-dsu.siz[pu], pu}) != s1.end() && s1.find({-dsu.siz[pv], pv}) != s1.end())
            {
                // 兩個都在範圍內
                flag1 = flag2 = true;
            }
            else if(s1.size() && s1.find({-dsu.siz[pu], pu}) != s1.end())
                flag1 = true;
            else if(s1.size() && s1.find({-dsu.siz[pv], pv}) != s1.end())
                flag2 = true;
            if(flag1)
            {
                s1.erase({-dsu.siz[pu], pu});
                ans -= dsu.siz[pu];
            }
            else
                s2.erase({-dsu.siz[pu], pu});
            if(flag2)
            {
                s1.erase({-dsu.siz[pv], pv});
                ans -= dsu.siz[pv];
            }
            else
                s2.erase({-dsu.siz[pv], pv});
            dsu._union(pu, pv);
            pu = dsu._find(u);
            if(flag1 && flag2)
            {
                // 原本都在 s1
                s1.insert({-dsu.siz[pu], pu});
                ans += dsu.siz[pu];
                if(s1.size() <= free_op && s2.size())
                {
                    auto it = s2.begin();
                    ans += -it->first;
                    s1.insert({it->first, it->second});
                    s2.erase(it);
                }
            }
            else if(!flag1 && !flag2)
            {
                // 原本都不在 s1
                if(s1.size() && dsu.siz[pu] > -s1.rbegin()->first)
                {
                    ans += dsu.siz[pu];
                    s1.insert({-dsu.siz[pu], pu});
                }
                if(s1.size() > free_op + 1)
                {
                    auto it = prev(s1.end());
                    ans -= -it->first;
                    s2.insert({it->first, it->second});
                    s1.erase(it);
                }
            }
            else if(s1.empty() || dsu.siz[pu] > -s1.rbegin()->first)
            {
                ans += dsu.siz[pu];
                s1.insert({-dsu.siz[pu], pu});
            } else {
                s2.insert({-dsu.siz[pu], pu});
            }
        }
        else
        {
            free_op++;
            if(s1.size() < free_op + 1 && s2.size())
            {
                auto it = s2.begin();
                ans += -it->first;
                s1.insert({it->first, it->second});
                s2.erase(it);
            }
        }
        cout << ans - 1 << '\n';
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
        sol();
    return 0;
}