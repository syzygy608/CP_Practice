#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
const int INF = 2e9;
struct info
{
    int t, p;
    ll v;
    info(int t, int p, ll v) : t(t), p(p), v(v) {}
};
vector<int> arr;
vector<ll> ans;
vector<info> v;
int timer, askid;
ll cur = 0;

void cdq(int l, int r)
{
    if(l == r)
        return;
    int mid = (l + r) / 2;
    cdq(l, mid);
    cdq(mid + 1, r);
    vector<info> tmp;
    int pl = l, pr = mid + 1;
    while(pl <= mid && pr <= r)
    {
        if(v[pl].p <= v[pr].p)
        {
            tmp.push_back(v[pl]);
            if(abs(v[pl].v) <= 1e9)
                cur += v[pl].v;
            pl++;
        }
        else
        {
            tmp.push_back(v[pr]);
            if(v[pr].v >= INF)
                ans[v[pr].v - INF] += cur;
            else if(v[pr].v <= -INF)
                ans[-(v[pr].v + INF)] -= cur;
            pr++;
        }
    }
    while(pl <= mid)
        tmp.push_back(v[pl++]);
    while(pr <= r)
    {
        tmp.push_back(v[pr]);
        if(v[pr].v >= INF)
            ans[v[pr].v - INF] += cur;
        else if(v[pr].v <= -INF)
            ans[-(v[pr].v + INF)] -= cur;
        pr++;
    }
    cur = 0;
    for(int i = l, j = 0; i <= r; i++, j++)
        v[i] = tmp[j];
}

int main()
{
    (cin.tie(0))->sync_with_stdio(0);
    int n, q;
    cin >> n >> q;
    arr.assign(n + 1, 0);
    for(int i = 1; i <= n; ++i)
    {
        cin >> arr[i];
        v.emplace_back(info(++timer, i, arr[i]));
    }
    while(q--)
    {
        int op, a, b;
        cin >> op >> a >> b;
        if(op == 1)
        {
            v.emplace_back(info(++timer, a, b - arr[a]));
            arr[a] = b;
        }
        else
        {
            v.emplace_back(info(++timer, b, INF + askid));
            v.emplace_back(info(timer, a - 1, -INF - askid));
            askid++;
            ans.push_back(0);
        }
    }
    cdq(0, (int)v.size() - 1);
    for(ll i: ans)
        cout << i << '\n';
    return 0;
}