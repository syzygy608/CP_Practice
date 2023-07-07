#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    int last = -1, cnt = 0;
    vector<int> arr(n);
    for(int &el: arr)
        cin >> el;
    sort(arr.begin(), arr.end());
    for(int &el: arr)
    {
        if(el != last)
            cnt++;
        last = el;
    }
    cout << cnt << '\n';
}