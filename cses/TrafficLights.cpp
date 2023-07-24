#include <iostream>
#include <set>

using namespace std;

int main()
{
    (cin.tie(0))->sync_with_stdio(0);
    int x, n;
    cin >> x >> n;
    set<int> pt;
    multiset<int> len;
    pt.insert(0);
    pt.insert(x);
    len.insert(x);
    for(int i = 0, p; i < n; ++i)
    {
        cin >> p;
        auto r = pt.upper_bound(p);
        auto l = r;
        l--;
        auto it = len.find(*r - *l); 
        if(it != len.end())
            len.erase(it);
        len.insert(*r - p);
        len.insert(p - *l);
        pt.insert(p);
        cout << *len.rbegin() << '\n';
    }
}