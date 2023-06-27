#include <iostream>
#include <map>

using namespace std;
const int maxn = 2e5 + 5;
int arr[maxn];

int main()
{
    int n;
    cin >> n;
    map<int, int> cnt;
    for(int i = 1; i <= n; ++i)
        cin >> arr[i];    
    int l = 1, r = 1, ans = 0, len = 0;
    while(r <= n)
    {
        if(cnt[arr[r]] == 0)
        {
            cnt[arr[r]]++;
            len++;
            ans = max(ans, len);
            r++;
        }
        else
        {
            len--;
            cnt[arr[l]]--;
            l++;
        }
    }
    cout << ans << '\n';
}
/*
8
1 2 1 3 2 7 4 2
*/