#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, d;
    cin >> n >> d;
    vector<string> arr(n);
    for(int i = 0; i < n; ++i)
        cin >> arr[i];
    vector<int> a;
    bool last = false;
    for(int i = 0; i < d; ++i)
    {
        bool check = true;
        for(int j = 0; j < n; ++j)
            check &= (arr[j][i] == 'o');
        if(check)
            a.push_back(i);
    }
    if(a.empty())
    {
        cout << "0\n";
        return 0;
    }
    int ans = 0, tmp = 1;
    // 0 0 1 1 0 1 0 1 1 1 0 
    for(int i = 0; i < a.size() - 1; ++i)
    {
        if(a[i] == a[i + 1] - 1)
            tmp++;
        else
        {
            ans = max(tmp, ans);
            tmp = 1;
        }
    }
    ans = max(tmp, ans);
    cout << ans << '\n';
    return 0;
}