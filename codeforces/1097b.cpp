#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(int &i: v)
        cin >> i;
    for(int i = 0; i < (1 << n); ++i)
    {
        int sum = 0;
        for(int j = 0; j < n; ++j)
        {
            if(i & (1 << j))
                sum += v[j];
            else
                sum -= v[j];
        }
        if(sum % 360 == 0)
        {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
}