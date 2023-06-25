#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
using ll = long long;

int main()
{
    int n, m;
    cin >> n >> m;
    multiset<int> ticket;
    for(int i = 0, num; i < n; ++i)
    {
        cin >> num;
        ticket.insert(num);
    }
    for(int i = 0, num; i < m; ++i)
    {
        cin >> num;
        auto it = ticket.lower_bound(num);
        if(*it == num)
        {
            cout << *it << '\n';
            ticket.erase(it);
        }
        else
        {
            if(it != ticket.begin())
            {
                --it;
                cout << *it << '\n';
                ticket.erase(it);
            }
            else
                cout << "-1\n";
        }
    }
    
    return 0;
}