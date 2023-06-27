#include <iostream>
#include <vector>

using namespace std;
const int maxn = 1e5 + 5;
int n, m;
vector<int> p;

int search(int x)
{
    return (p[x] < 0) ? x : p[x] = search(p[x]);
}

bool unite(int x, int y)
{
    int px = search(x), py = search(y);
    if(px == py)
        return false;
    p[px] += p[py];
    p[py] = px;
    return true;
}

int main()
{
    cin >> n >> m;
    p.assign(n + 1, -1);
    int sz = 1, c = n;
    for(int i = 0, u, v; i < m; ++i)
    {
        cin >> u >> v;
        if(unite(u, v))
            c--;
        sz = max(sz, -p[search(u)]);
        cout << c << ' ' << sz << '\n';
    }
}