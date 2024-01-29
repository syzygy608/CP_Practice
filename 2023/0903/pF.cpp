#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define _ << ' ' << 
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define IO (*cin.tie(0)).sync_with_stdio(0);

using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;

int main()
{
    int n;
    cin >> n;
    vector<int> one;
    unordered_map<int, int> s;
    for(int i = 1, num; i <= n; ++i)
    {
        cin >> num;
        if(num == 1)
            one.pb(i);
        s[num] = i;
    }
    if(one.size() >= 2)
    {
        cout << one[0] _ one[1] << '\n';
        return 0;
    }
    int fib1 = 1, fib2 = 2;
    while(fib2 <= 1000000)
    {
        if(s.count(fib2) && s.count(fib1))
        {
            cout << s[fib1] _ s[fib2] << '\n';
            return 0;
        }
        int tmp = fib2;
        fib2 += fib1;
        fib1 = tmp;
    }
    cout << "impossible\n";
    return 0;
}