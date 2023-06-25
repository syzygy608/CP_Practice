#include <iostream>
#include <vector>
#include <utility>

using namespace std;
using ll = long long;

int main()
{
    ll n;
    cin >> n;
    ll temp = (1 + n) * n / 2;
    if(temp % 2 != 0)
        cout << "NO\n";
    else
    {
        cout << "YES\n";
        ll sum = 0;
        vector<int> a, b;
        for(int i = n; i >= 1; --i)
        {
            if(sum + i <= temp / 2)
            {
                a.push_back(i);
                sum += i;
            }
            else
                b.push_back(i);
        }
        cout << a.size() << '\n';
        for(int &el: a)
            cout << el << ' ';
        cout << '\n';
        cout << b.size() << '\n';
        for(int el: b)
            cout << el << ' ';
    }
    return 0;
}
