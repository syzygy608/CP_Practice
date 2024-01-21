#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define AnNinMiRu (*cin.tie(0)).sync_with_stdio(0);
#define eb emplace_back
#define X first
#define Y second
#define _ << ' ' <<
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(x) ((int)(x).size())

const int maxn = 2e5 + 5;

void sol()
{
    int n;
    cin >> n;
    vector<string> a(n);
    vector<int> v(n), people(n, 0);
    for(int i = 0; i < n; ++i)
    {
        cin >> a[i];
        v[i] = i;
    }
    int m;
    cin >> m;
    for(int i = 0, l, r; i < m; ++i)
    {
        cin >> l >> r;
        --l, --r;
        people[l] = people[r] + 1;
        v[l] = v[r];
    }
    while(people[0]--)
        cout << "I_love_";
    cout << a[v[0]] << '\n';
}

signed main()
{
    AnNinMiRu
    int t = 1;
    // cin >> t;
    while(t--)
        sol();
    return 0;
}