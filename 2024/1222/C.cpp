#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define eb emplace_back
using namespace std;
using ll = long long;
const int INF = numeric_limits<int>::max() / 2;
const ll LINF = numeric_limits<ll>::max() / 2;

template<typename T>
istream& operator>>(istream& in, vector<T> &arr)
{
    for(auto &x: arr)
        in >> x;
    return in;
}
 
template<typename T>
ostream& operator<<(ostream& out, vector<T> &arr)
{
    ll n = arr.size();
    if(n != 0)
        cout << arr[0];
    for (int i = 1; i < n; i++)
        out << " " << arr[i];
    return out;
}

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(m), q(k);
    vector<int> prefix(n + 1, 0);
    for(int i = 0; i < m; ++i)
        cin >> a[i];
    for(int i = 0; i < k; ++i)
    {
        cin >> q[i];
        prefix[q[i]] = 1;
    }
    for(int i = 1; i <= n; ++i)
        prefix[i] += prefix[i - 1];
    for(int i = 0; i < m; ++i)
    {
        bool f = true;
        if(prefix[n] == n - 1 && prefix[a[i]] - prefix[a[i] - 1] != 0)
            f = false;
        else if(prefix[n] < n - 1)
            f = false;
        cout << f;
    }
    cout << '\n';
}

int main()
{
    (*cin.tie(0)).sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}