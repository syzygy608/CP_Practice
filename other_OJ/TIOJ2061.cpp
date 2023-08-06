#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    string a;
    cin >> a;
    string b = a;
    reverse(b.begin(), b.end());
    vector<int> dp1(a.size() + 1, 0), dp2(a.size() + 1, 0);
    for(int i = 1; i <= a.size(); i++)
    {
        for(int j = 1; j <= a.size(); j++)
        {
            if(a[i - 1] == b[j - 1])
                dp2[j] = dp1[j - 1] + 1;
            else
                dp2[j] = max(dp1[j], dp2[j - 1]);
        }
        swap(dp1, dp2);
    }
    cout << dp1[a.size()] << '\n';
}