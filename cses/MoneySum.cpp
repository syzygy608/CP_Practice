#include <iostream>
#include <bitset>
#include <vector>

using namespace std;
const int maxn = 1e5 + 5;
bitset<maxn> sub;

int main()
{
    int n;
    cin >> n;
    sub[0] = 1;
    for(int i = 0, num; i < n; ++i)
    {
        cin >> num;
        sub |= sub << num;
    }
    vector<int> ans;
    for(int i = 1; i <= 100000; ++i)
        if(sub[i])
            ans.push_back(i);
    cout << ans.size() << '\n';
    for(int el: ans)
        cout << el << ' ';
}