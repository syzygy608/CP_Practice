#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    if(n == 1)
    {
        cout << 1 << '\n';
        return 0;
    }
    if(n < 4)
    {
        cout << "NO SOLUTION\n";
        return 0;
    }
    vector<int> v;
    for(int i = 1; i <= n; i++)
    {
        if(i % 2 == 0)
            v.push_back(i);
    }
    for(int i = 1; i <= n; i++)
    {
        if(i % 2 == 1)
            v.push_back(i);
    }
    for(int i : v)
        cout << i << ' ';
}