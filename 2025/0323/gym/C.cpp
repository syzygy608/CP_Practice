#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define all(x) (x).begin(), (x).end()
#define F first
#define S second

constexpr i64 MOD = 1e9 + 7;

template<class T>
static void cmn(T &a, T b) { a = (a <=> b > 0) ? b : a; }
template<class T>
static void cmx(T &a, T b) { a = (a <=> b < 0) ? b : a; }

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(n);
    vector<int> ind(n), outd(n);
    vector<bool> inchat(n);
    bool f = true;
    if(m == 1)
        f = false;
    for(int i = 0; i < m; ++i)
    {
        int id, k;
        cin >> id >> k;
        id--;
        inchat[id] = true;
        if(!k)
        {
            cin >> id;
            continue;
        }
        for(int j = 0, x; j < k; ++j)
        {
            cin >> x;
            x--;
            edges[id].push_back(x);
        }
    }
    for(int i = 0; i < n; ++i)
    {
        for(int j: edges[i])
        {
            if(inchat[j])
            {
                ind[j]++;
                outd[i]++;
            }
        }
    }
    if(!f)
    {
        cout << "-1\n";
        return;
    }
    for(int i = 0; i < n; ++i)
    {
        if(inchat[i] && ind[i] == m - 1 && outd[i] == 0)
        {
            cout << i + 1 << '\n';
            return;
        }
    }
    cout << -1 << '\n';
}

int main()
{
    (cin.tie(0))->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve();
    return 0;
}