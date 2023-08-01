#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define _ << ' ' << 
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define IO (*cin.tie(0)).sync_with_stdio(0);

using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;

struct E
{
    int l, r, id;
    bool operator <(const E& b)
    {
        if(l != b.l)
            return l < b.l;
        return r > b.r;
    }
};

int main()
{
    IO
    ll n, m;
    cin >> n >> m;
    vector<E> v(n);
    for(int i = 0; i < n; ++i)
    {
        cin >> v[i].l >> v[i].r;
        v[i].id = i;
    }
    sort(all(v));
    bool flag = true;
    if(v[0].l != 1)
        flag = false;
    ll bound = v[0].r; 
    vector<int> ans;
    ans.push_back(v[0].id + 1);
    for(int i = 1; i < n; ++i)
    {
        if(v[i].l > bound + 1)
        {
            flag = false;
            break;
        }
        pair<ll, int> cur = {bound, i};
        while(i < n && v[i].l <= bound + 1)
        {
            cur = max(cur, {v[i].r, v[i].id});
            i++;
        }
        if(cur.F > bound)
        {
            bound = cur.F;
            ans.push_back(cur.S + 1);
        }
        i--;
    }
    if(bound != m)
        flag = false;
    if(!flag)
    {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n" << ans.size() << '\n';
    for(int i = 0; i < ans.size(); ++i)
        cout << ans[i] << " \n"[i == ans.size() - 1];
    return 0;
}