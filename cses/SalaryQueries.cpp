#include <iostream>
#include <vector>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> RBT;
const int inf = 1 << 30;

int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> v(n + 1);
    RBT s;
    for(int i = 1; i <= n; ++i)
    {
        cin >> v[i];
        s.insert({v[i], i});
    }
    for(int i = 0; i < q; ++i)
    {
        char c;
        int a, b;
        cin >> c >> a >> b;
        if(c == '!')
        {
            s.erase({v[a], a});
            v[a] = b;
            s.insert({b, a});
        }
        else
            cout << s.order_of_key({b, inf}) - s.order_of_key({a - 1, inf}) << '\n';
    }
    return 0;
}