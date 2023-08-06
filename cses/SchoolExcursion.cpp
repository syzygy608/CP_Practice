#include <iostream>
#include <vector>
#include <bitset>

using namespace std;
const int N = 1e5 + 5;

struct DSU
{
    int n;
    vector<int> par_sz;
    DSU(int _n)
    {
        n = _n;
        par_sz.resize(n);
        for(int i = 0; i < n; ++i)
            par_sz[i] = -1;
    }
    int find(int x)
    {
        return (par_sz[x] < 0 ? x : par_sz[x] = find(par_sz[x]));
    }
    void unite(int x, int y)
    {
        int px = find(x);
        int py = find(y);
        if(px == py)
            return;
        if(par_sz[px] > par_sz[py])
            swap(px, py);
        par_sz[px] += par_sz[py];
        par_sz[py] = px;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    DSU dsu(n);
    for(int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        dsu.unite(a - 1, b - 1);
    }
    vector<int> comp;
    for(int i = 0; i < n; ++i)
        if(dsu.find(i) == i)
            comp.push_back(-dsu.par_sz[i]);
    bitset<N> bs;
    bs[0] = 1;
    for(int t: comp)
        bs |= (bs << t);
    for(int i = 1; i <= n; ++i)
        cout << bs[i];
    cout << '\n';
    return 0;
}