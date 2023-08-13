#include <iostream>
#include <vector>
#include <bitset>

using namespace std;
const int maxn = 1e6 + 5;
bitset<maxn> state;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(k);
    for(int &e: v)
        cin >> e;

    for(int i = 1; i <= n; ++i)
    {
        for(int j = 0; j < k; ++j)
        {
            if(i >= v[j] && !state[i - v[j]])
                state[i] = true;
        }
    }
    for(int i = 1; i <= n; ++i)
        cout << (state[i] ? "W" : "L");
    cout << '\n';

}