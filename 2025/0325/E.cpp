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

constexpr int MAX_PR = 10'000'005;
bitset<MAX_PR> isprime;
vector<int> pr;
i64 pref[MAX_PR];

void eratosthenesSieve(int lim)
{
    isprime.set(); isprime[0] = isprime[1] = 0;
    for(i64 i = 4; i < lim; i += 2)
        isprime[i] = 0;
    for(i64 i = 3; i * 1ll * i < lim; i += 2)
        if(isprime[i])
            for(i64 j = i * 1ll * i; j < lim; j += i * 2)
                isprime[j] = 0;
    for(int i = 2; i <= lim; ++i)
        if(isprime[i])
            pr.push_back(i);
    for(int i: pr)
    {
        pref[i]++;
        for(int j: pr)
        {
            if(i * 1ll * j > lim)
                break;
            pref[i * j]++;
        }
    }
    for(int i = 1; i <= lim; ++i)
        pref[i] += pref[i - 1];
}

void solve()
{
    int n;
    cin >> n;
    
    cout << pref[n] << '\n';
}

int main()
{
    (cin.tie(0))->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    eratosthenesSieve(MAX_PR - 1);
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}