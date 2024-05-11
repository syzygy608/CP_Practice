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
    vector<int> v(n);
    for(int &i: v)
        cin >> i;
    vector<ll> pre(n + 1);
    for(int i = 0; i < n; i++)
        pre[i + 1] = pre[i] + v[i];
    int q;
    cin >> q;
    while(q--)
    {
        int l, u;
        cin >> l >> u;
        ll L = -4e18, R = 4e18, idx = -1;
        while(L <= R)
        {
            ll mid = L + (R - L) / 2;
            function<pair<bool, int>(ll)> test = [&](ll x)
            {
                int LL = 0, RR = n - l, idx = 1e9; // l is 1-indexed
                bool ok = 0;
                while(LL <= RR)
                {
                    int mid = (LL + RR) / 2;
                    ll temp = pre[l + mid] - pre[l - 1]; // [l, l + mid]
                    ll sub = temp * (temp - 1) / 2;
                    temp = temp * u - sub;
                    if(temp >= x)
                    {
                        ok = 1;
                        idx = min(idx, mid + l);
                        RR = mid - 1;
                    }
                    else
                        LL = mid + 1;
                }
                return make_pair(ok, idx);
            };
            pair<bool, int> check = test(mid);
            if(check.first)
            {
                idx = max(idx, (ll)check.second);
                L = mid + 1;
            }
            else
                R = mid - 1;
        }
        cout << idx << " \n"[q == 0];
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
