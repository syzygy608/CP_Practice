#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

typedef unsigned long long ull;
typedef pair<ull, ull> pll;

const int N = 60, M = 998244353;
const ull mask = std::chrono::steady_clock::now().time_since_epoch().count();

ull shift(ull x)
{
    x ^= mask;
    x ^= x << 13;
    x ^= x >> 7;
    x ^= x << 17;
    x ^= mask;
    return x;
}

ull getHash(int x, int fa, vector<vector<int>> &edge)
{
    ull hash = 1;
    for(int i: edge[x])
    {
        if(i == fa)
            continue;
        hash += shift(getHash(i, x, edge));
    }
    return hash;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> edges1, edges2;
        edges1.resize(n + 1);
        edges2.resize(n + 1);
        for(int i = 0, u, v; i < n - 1; ++i)
        {
            cin >> u >> v;
            edges1[u].push_back(v);
            edges1[v].push_back(u);
        }
        for(int i = 0, u, v; i < n - 1; ++i)
        {
            cin >> u >> v;
            edges2[u].push_back(v);
            edges2[v].push_back(u);
        }
        ull hash1 = getHash(1, 0, edges1);
        ull hash2 = getHash(1, 0, edges2);
        if(hash1 == hash2)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}