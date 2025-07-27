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
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    for(int i = 0; i < n; ++i)
    {
        cin >> b[i];
        a[i] *= b[i];
    }
    vector<int> pref1(n + 1, 0), pref2(n + 1, 0);
    for(int i = 0; i < n; ++i)
    {
        pref1[i + 1] = pref1[i] + a[i];
        pref2[i + 1] = pref2[i] + b[i];
    }
    int k;
    cin >> k;
    vector<vector<double>> memo(n, vector<double>(k, -1));
    auto gpa = [&](int s) -> double
    {
        if(s < 60)
            return 0.0;
        if(s < 63)
            return 1.7;
        if(s < 67)
            return 2.0;
        if(s < 70)
            return 2.3;
        if(s < 73)
            return 2.7;
        if(s < 77)
            return 3.0;
        if(s < 80)
            return 3.3;
        if(s < 85)
            return 3.7;
        if(s < 90)
            return 4.0;
        return 4.3;
    };
    auto dfs = [&](this auto &&self, int i, int j) -> double
    {
        if(i == 0)
            return (j == 0) ? gpa(round(a[i] / b[i])) : -1e9;
        if(j == 0)
            return  gpa(round(1.0 * (pref1[i + 1]) / pref2[i + 1]));
        if(memo[i][j] != -1)
            return memo[i][j];
        double res = -1e9;
        for(int l = i; l >= 1; --l)
        {
            double tmp = gpa(round(1.0 * (pref1[i + 1] - pref1[l]) / (pref2[i + 1] - pref2[l])));
            cmx(res, self(l - 1, j - 1) + tmp);
        }
        return memo[i][j] = res;
    };
    cout << fixed << setprecision(7) << dfs(n - 1, k - 1) / k << '\n';
}

int main()
{
    (cin.tie(0))->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}