#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
const int MOD = 998244353;

i64 fpow(i64 a, i64 b)
{
    i64 res = 1;
    while(b)
    {
        if(b & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

void sol()
{
    int k;
    string s;
    cin >> k >> s;
    int question = count(s.begin(), s.end(), '?');
    int q;
    cin >> q;
    while(q--)
    {
        int p;
        char c;
        cin >> p >> c;
        p--;
        if(s[p] == '?' && c != '?')
            question--;
        else if(s[p] != '?' && c == '?')
            question++;
        cout << fpow(2, question) << '\n';
        s[p] = c;
    }

}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)
        sol();
    return 0;
}
