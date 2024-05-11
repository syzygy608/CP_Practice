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
    for(auto &i: v)
        cin >> i;
    int sum = 0;
    int cnt[3] = {0}, tt[3] = {0};
    for(int i = 0; i < n; ++i)
    {
        sum += v[i];
        cnt[v[i] % 3]++;
    }
    tt[0] = cnt[0];
    tt[1] = cnt[1];
    tt[2] = cnt[2];
    if(sum % 3 == 0)
        cout << "0\n";
    else
    {
        int ans = 1e9;
        int tmp = min(cnt[1], cnt[2]);
        cnt[1] -= tmp;
        cnt[2] -= tmp;
        cnt[1] %= 3;
        cnt[2] %= 3;
        if(cnt[2] > cnt[1])
            ans = min(ans, (cnt[2] - cnt[1]));
        else if(cnt[1] > cnt[2])
            ans = min(ans, ((cnt[1] - cnt[2] + 1) / 2));
        else
            ans = 0;
        tt[1] %= 3;
        tt[2] %= 3;
        if(tt[2] > tt[1])
            ans = min(ans, (tt[2] - tt[1]));
        else if(tt[1] > tt[2])
            ans = min(ans, ((tt[1] - tt[2] + 1) / 2));
        else
            ans = 0;
        cout << ans << '\n';
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
