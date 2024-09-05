#include <bits/stdc++.h>

using namespace std;

mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

int main()
{
    int t = 10;
    cout << t << '\n';
    for(int i = 0; i < t; ++i)
    {
        int x = rng() % (int)(1e9 + 1);
        int y = rng() % (int)(1e9 + 1);
        int k = rng() % (int)(1e9) + 1;
        cout << x << ' ' << y << ' ' << k << '\n';
    }
}