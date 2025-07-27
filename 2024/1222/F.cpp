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
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> v(q);
    cin >> v;
    int L = m, R = m;
    /*
    1 2 3 4 5 6
    1 2 3 4 5 6
    2 3 4 5 6 1
    */
    for(int i = 0; i < q; ++i)
    {
        if(v[i] < L)
            L = max(1, L - 1);
        else if(v[i] > R)
            R = min(n, R + 1);
        else if(v[i] >= L && v[i] <= R)
        {
            L = max(1, L - 1);
            R = min(n, R + 1);
        }
        cout << R - L + 1 << " \n"[i == q - 1];
    }
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