#include <iostream>
#include <vector>
#include <utility>
#include <cstring>
#include <set>

using namespace std;
const int maxn = 1e5 + 5;
int p[maxn];

int fin(int x)
{
    return (p[x] < 0) ? x : p[x] = fin(p[x]);
}

bool unio(int a, int b)
{
    int px = fin(a), py = fin(b);
    if(px == py)
        return false;
    p[py] += p[px];
    p[px] = py;
    return true;
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, int>> ed(m), brk(k);
    set<pair<int, int>> st;
    for(auto &el: ed)
        cin >> el.first >> el.second;
    for(auto &el: brk)
    {
        cin >> el.first >> el.second;
        st.insert(el);
    }
    memset(p, -1, sizeof(p));
    int com = n;
    for(auto el: ed)
        if(st.find(el) == st.end() && st.find(make_pair(el.second, el.first)) == st.end())
            if(unio(el.first, el.second))
                com--;
    vector<int> ans;
    ans.push_back(com);
    for(int i = brk.size() - 1; i >= 0; --i)
    {
        if(unio(brk[i].first, brk[i].second))
            com--;
        ans.push_back(com);
    }
    for(int i = ans.size() - 2; i >= 0; --i)
        cout << ans[i] << " \n"[i == 0];
}