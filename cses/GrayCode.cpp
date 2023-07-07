#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<int> b(n, 0);
    for(int i = 1; i <= (1 << n); ++i)
    {
        for(int el: b)
            cout << el;
        cout << '\n';
        if(i & 1)
            *b.rbegin() = !*b.rbegin();
        else
        {
            for(int j = n - 1; j >= 1; j--)
            {
                if(b[j] == 1)
                {
                    b[j - 1] = !b[j - 1];
                    break;
                }
            }
        }
    }
    return 0;
}
