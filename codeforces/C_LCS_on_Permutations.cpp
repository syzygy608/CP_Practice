#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
const int maxn = 2e5 + 5;

void sol()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1, num; i <= n; i++)
    {
        cin >> num;
        a[num] = i;
    }
    vector<int> b(n + 1);
    for(int i = 1, num; i <= n; i++)
    {
        cin >> num;
        b[i] = a[num];
    }
    vector<int> v;
    for(int i = 1; i <= n; i++)
    {
        if(v.empty() || v.back() < b[i])
            v.push_back(b[i]);
        else
        {
            auto it = lower_bound(v.begin(), v.end(), b[i]);
            *it = b[i];
        }
    }
    cout << v.size() << '\n';
}

int main()
{
    int t = 1;
    // cin >> t;
    while(t--)
        sol();
    return 0;
}