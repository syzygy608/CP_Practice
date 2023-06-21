#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <array>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int sum = 0;
    vector<int> a(n);
    for(int &i : a)
    {
        cin >> i;
        sum += i;
    }
    if(sum)
    {
        cout << "YES" << endl;
        cout << "1" << endl;
        cout << "1 " << n << endl;
        return 0;
    }
    sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum += a[i];
        if(sum)
        {
            cout << "YES" << endl;
            cout << "2" << endl;
            cout << 1 << " " << i + 1 << endl;
            cout << i + 2 << " " << n << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}