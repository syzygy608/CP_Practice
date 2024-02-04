#include <bits/stdc++.h>

#define IO (cin.tie(0))->sync_with_stdio(0);
#define F first
#define S second
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define _ << ' ' <<

using namespace std;
using ll = long long;

const int maxn = 1e6 + 5;

vector<int> prime;
bitset<maxn> vis;

void Eratothenes()
{
    vis.set();
    vis[0] = vis[1] = 0;
    for(int i = 2; i * i < maxn; ++i)
    {
        if(vis[i])
        {
            prime.push_back(i);
            for(int j = (i << 1); j < maxn; j += i)
                vis[j] = 0;
        }
    }
}

int step = 0;

void solve(int x)
{
    while(x >= 4)
    {
        step++;
        for(int i: prime)
        {
            if(vis[x - i])
            {
                //  cerr << i _ x - i << '\n';
                x -= 2 * i;
                break;
            }
        }
    }
    cout << step << '\n';
}

void sol()
{
    int x;
    Eratothenes();
    cin >> x;
    solve(x);
}

int main()
{
    IO
    int t = 1;
    // cin >> t;
    while(t--)
        sol();
    return 0;
}
