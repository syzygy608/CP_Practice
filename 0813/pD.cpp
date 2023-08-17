#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define _ << ' ' <<
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define IO (*cin.tie(0)).sync_with_stdio(0);

using namespace std;
using ll = long long;
const int maxn = 1e5 + 5;

int main()
{
    IO
    string s[3];
    cin >> s[0] >> s[1] >> s[2];
    bool flag[3] = {1, 1, 1};
    if(s[0]== "tapioka" || s[0]== "bubble")
        flag[0] = false;
    if(s[1]== "tapioka" || s[1]== "bubble")
        flag[1] = false;
    if(s[2]== "tapioka" || s[2]== "bubble")
        flag[2] = false;
    if(flag[0] == flag[1] && flag[1] == flag[2] && flag[1] == false)
        puts("nothing");
    else
        for(int i = 0; i < 3; ++i)
            if(flag[i])
                cout << s[i] << ' ';
    return 0;
}
