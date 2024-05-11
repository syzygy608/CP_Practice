    #include <bits/stdc++.h>

    #define IO (cin.tie(0))->sync_with_stdio(0);
    #define F first
    #define S second
    #define sz(x) ((int)(x).size())
    #define all(x) (x).begin(), (x).end()
    #define rall(x) (x).rbegin(), (x).rend()
    #define _ << ' ' <<

    using namespace std;
    using ll = long long;

    const int maxn = 1e5 + 5;

    void sol()
    {
        int n;
        cin >> n;
        set<int> s;
        while(n != 1)
        {
            s.insert(n);
            int tmp = n, sum = 0;
            while(tmp)
            {
                sum += (tmp % 10) * (tmp % 10);
                tmp /= 10;
            }
            n = sum;
            if(s.count(n))
            {
                cout << "UNHAPPY\n";
                return;
            }
        }
        cout << "HAPPY\n";
    }

    int main()
    {
        IO
        int t = 1;
        // cin >> t;
        while(t--)
            sol();
        return 0;
    }
