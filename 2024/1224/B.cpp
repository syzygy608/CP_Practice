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
    int n, d;
    cin >> n >> d;
    vector<int> ans;
    ans.eb(1);
    if(n >= 3 || (d == 3 || d == 6 || d == 9))
        ans.eb(3); // good
    if(d == 5)
        ans.eb(5); // good
    if((n <= 2 && d == 7) || n > 2)
        ans.eb(7); // good
    if(n >= 6 || (d == 3 && n >= 3) || (d == 6 && n >= 3) || d == 9)
        ans.eb(9); // good
    cout << ans << '\n';
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