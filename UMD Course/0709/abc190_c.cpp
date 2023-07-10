#include <iostream>
#include <vector>
#include <array>
#include <utility>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<array<int, 2>> condition(m);
    for(auto &el: condition)
        cin >> el[0] >> el[1];
    int k;
    cin >> k;
    vector<array<int, 2>> people(k);
    for(auto &el: people)
        cin >> el[0] >> el[1];
    int ans = 0;
    for(int i = 0; i < (1 << k); ++i)
    {
        vector<int> dish(n + 1, 0);
        for(int j = 0; j < k; ++j)
        {
            if(i & (1 << j))
                dish[people[j][0]]++;
            else
                dish[people[j][1]]++;
        }
        int cnt = 0;
        for(auto el: condition)
            if(dish[el[0]] && dish[el[1]])
                cnt++;
        ans = max(ans, cnt);
    }
    cout << ans << '\n';
    return 0;
}