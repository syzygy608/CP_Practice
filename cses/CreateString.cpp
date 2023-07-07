#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<string> ans;
    string str;
    cin >> str;
    sort(str.begin(), str.end());
    do
    {
        ans.push_back(str);
    }while(next_permutation(str.begin(), str.end()));
    cout << ans.size() << '\n';
    for(string el: ans)
        cout << el << '\n';
}