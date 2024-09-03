#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

i64 dfs(int i)
{
    if(i == 1 || i == 2)
        return i - 1;
    return (i - 1) * dfs(i - 1) + 1 + (i - 2) * (i - 2);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    cout << dfs(n) << '\n';
    return 0;
}