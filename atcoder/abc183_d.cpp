#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main()
{
    int n, w;
    cin >> n >> w;
    vector<ll> diff(200005, 0);
    for(int i = 0, s, t, p; i < n; ++i)
    {
        cin >> s >> t >> p;
        diff[s] += p;
        diff[t] -= p;
    }
    ll sum = 0;
    for(int i = 0; i <= 200004; ++i)
    {
        sum += diff[i];
        //cerr << sum << '\n';
        if(sum > w)
        {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
    return 0;
}