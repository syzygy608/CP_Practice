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

int fpow(int a, int b)
{
    int ans = 1;
    while(b)
    {
        if(b & 1)
            ans = (1LL * ans * a);
        a = (1LL * a * a);
        b >>= 1;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        string a, b;
        cin >> a >> b;
        int numa = 0, numb = 0;
        if(a.find('.') != string::npos)
        {
            string tmp = a.substr(a.find('.') + 1);
            numa = stoi(a.substr(0, a.find('.'))) * fpow(10, (int)tmp.size());
            numa += stoi(tmp);
        }
        else
            numa = stoi(a);
        if(b.find('.') != string::npos)
        {
            string tmp = b.substr(b.find('.') + 1);
            numb = stoi(b.substr(0, b.find('.'))) * fpow(10, (int)tmp.size());
            numb += stoi(tmp);
        }
        else
            numb = stoi(b);
        int gcd_ab = __gcd(numa, numb);
        numa /= gcd_ab;
        numb /= gcd_ab;
        //cerr << numa _ numb << '\n';
        if(numa == numb)
            cout << "2 2\n";
        else
        {
            bool flag[2] = {0, 0};
            for(int i = 2; i * i <= numa; ++i)
            {
                if(numa % i == 0)
                {
                    flag[0] = 1;
                    break;
                }
            }
            for(int i = 2; i * i <= numb; ++i)
            {
                if(numb % i == 0)
                {
                    flag[1] = 1;
                    break;
                }
            }
            if(numa == 1 || numb == 1)
                cout << "impossible\n";
            else if(flag[0] || flag[1])
                cout << "impossible\n";
            else 
                cout << numa _ numb << '\n';
        }
    }
    return 0;
}