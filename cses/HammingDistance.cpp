#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        for(int j = 0; j < k; ++j)
            if(s[j] == '1')
                arr[i] |= (1 << j);
    }
    int ans = k;
    for(int i = 0; i < n; ++i)
        for(int j = i + 1; j < n; ++j)
            ans = min(ans, __builtin_popcount(arr[i] ^ arr[j]));
    cout << ans << '\n';
}