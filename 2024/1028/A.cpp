#include <bits/stdc++.h>

#define sz(a) ((int)(a).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define IO (*cin.tie(0)).sync_with_stdio(0);
using namespace std;
using ll = long long;
const double EPS = 1e-9;

ll ceilDiv(ll n, ll m)
{
    return ((n >= 0) ? (n + m - 1) / m : n / m);
}

ll floorDiv(ll n, ll m)
{
    return ((n >= 0) ? n / m : (n - m + 1) / m);
}

void solve()
{
    int x, y, k;
    cin >> x >> y >> k;
    for(int i = 0; i <= x; ++i)
    {
    	for(int j = 0; j <= y; ++j)
    	{
    		if(i * i + j * j < k * k)
    			continue;
    		int dx = i, dy = j;
    		for(int l = 0; l <= k; ++l)
    		{
    			int nx = x - dy * l;
    			int ny = dx * l;
    			if(nx < 0 || ny > y)
    				break;
    			if((nx - x) * (nx - x) + ny * ny >= k * k)
    			{
    				cout << "0 0 " << i << ' ' << j << '\n';
    				cout << x << " 0 " << nx << ' ' << ny << '\n';
    				return;
    			}
    		}
    		for(int l = 0; l <= k; ++l)
    		{
    			int nx = dy * l;
    			int ny = y - dx * l;
    			if(ny < 0 || nx > x)
    				break;
    			if(nx * nx + (ny - y) * (ny - y) >= k * k)
    			{
    				cout << "0 0 " << i << ' ' << j << '\n';
    				cout << "0 " << y << ' ' << nx << ' ' << ny << '\n';
    				return;
    			}
    		}
    	}
    }
}

int main()
{
    IO
    cin.exceptions(cin.failbit);
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}