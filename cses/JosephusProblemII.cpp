#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> RBT;
const int maxn = 2e5 + 5;

int main()
{
    int n, k;
    cin >> n >> k;
    RBT t;
    int p = k % n;
    for(int i = 1; i <= n; ++i)
        t.insert(i);
    while(t.size())
    {
        int i = *t.find_by_order(p);
        cout << i << ' ';
        t.erase(i);
        if(t.size())
            p = (p + k) % t.size();
    }
}