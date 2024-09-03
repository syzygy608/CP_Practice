#include <bits/stdc++.h>

#define X first
#define Y second
#define all(x) ((x).begin(), (x).end())
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;

ll fpow(ll a, ll b)
{
    ll res = 1;
    while(b)
    {
        if(b & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

struct Matrix
{
    int n, m;
    vector<vector<ll>> a;
    Matrix(int _n, int _m) : n(_n), m(_m), a(_n, vector<ll>(_m)) {}
    Matrix operator*(const Matrix &b) const
    {
        Matrix res(n, b.m);
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < b.m; ++j)
                for(int k = 0; k < m; ++k)
                    res.a[i][j] = (res.a[i][j] + a[i][k] * b.a[k][j]) % MOD;
        return res;
    }
};

Matrix fpow(Matrix a, int b)
{
    Matrix res(a.n, a.m);
    for(int i = 0; i < a.n; ++i)
        res.a[i][i] = 1;
    while(b)
    {
        if(b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}


void sol()
{
    int n, k, m;
    cin >> n >> k >> m;
    int left = k - k / m; // 剩下的可能
    vector<ll> pb(m);
    vector<int> cnt(m);
    for(int i = 1; i <= k; ++i)
    {
        if(i % m == 0)
            continue;
        cnt[i % m]++;
    }
    for(int i = 0; i < m; ++i)
        pb[i] = (cnt[i] * fpow(left, MOD - 2)) % MOD;
    Matrix a(m, m);
    for(int i = 0; i < m; ++i)
        for(int j = 0; j < m; ++j)
            a.a[i][j] = pb[(j - i + m) % m];
    a = fpow(a, n);
    cout << a.a[0][0] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)
        sol();
}

