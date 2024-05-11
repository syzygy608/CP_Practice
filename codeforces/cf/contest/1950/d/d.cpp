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

vector<int> binary;

void build()
{
    bitset<10> b;
    for(int i = 2; i <= 63; ++i)
    {
        b.reset();
        for(int j = 0; j < 10; ++j)
            b[j] = (i & (1 << j));
        if(stoll(b.to_string()) > 100000)
            break;
        binary.pb(stoi(b.to_string()));
    }
}
void solve()
{
    int n;
    cin >> n;
    while(true)
    {
        bool div = false;
        for(int i = sz(binary) - 1; i >= 0; --i)
        {
            if(n % binary[i] == 0)
            {
                n /= binary[i];
                div = true;
                break;
            }
        }
        if(!div || n == 1)
            break;
    }
    if(n == 1)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main()
{
    IO;
    build();
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
