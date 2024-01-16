#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

void sol()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int cur = 0;
    for(int i = 1; i <= n && cur < n; i += 2)
        for(int j = 0; i * (1 << j) <= n && cur < n; ++j)
            a[cur++] = i * (1 << j);
    for(int i = 0; i < n; ++i)
        cout << a[i] << " \n"[i == n - 1];
}

int main()
{
    int t;
    cin >> t;
    while(t--)
        sol();
}