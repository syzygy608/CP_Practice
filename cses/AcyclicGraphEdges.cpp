#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> v(m);
    for(auto &el: v)
        cin >> el.first >> el.second;
    for(auto &el: v)
    {
        if(el.first > el.second)
            swap(el.first, el.second);
        cout << el.first << ' ' << el.second << '\n';
    }
}