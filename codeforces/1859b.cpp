#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

void sol()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    int mn = 1e9 + 1;
    for(int i = 0; i < n; ++i)
    {
        int k;
        cin >> k;
        int t1 = 1e9 + 1, t2 = 1e9 + 1;
        for(int j = 0; j < k; ++j)
        {
            int x;
            cin >> x;
            if(x < t1)
            {
                t2 = t1;
                t1 = x;
            }
            else if(x < t2)
                t2 = x;
        }
        a[i] = t1;
        b[i] = t2;
        mn = min(mn, t1);
    }
    cout << mn + accumulate(b.begin(), b.end(), 0ll) - *min_element(b.begin(), b.end()) << '\n';
}

int main()
{
    int t;
    cin >> t;
    while(t--)
        sol();
}