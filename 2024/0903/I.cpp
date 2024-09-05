#include <bits/stdc++.h>
using namespace std;

int main()
{
    int l, r;
    cin >> l >> r;
    vector<int> fz, bz;
    for(int i = l; i <= r; i++)
    {
        string tmp;
        cin >> tmp;
        if(tmp == "Fizz")
            fz.push_back(i);
        else if(tmp == "Buzz")
            bz.push_back(i);
        else if(tmp == "FizzBuzz")
        {
            fz.push_back(i);
            bz.push_back(i);
        }
    }
    if(fz.size() == 0)
        cout << "1000000 ";
    else if(fz.size() == 1)
        cout << fz[0] << ' ';
    else
        cout << fz[1] - fz[0] << ' ';
    if(bz.size() == 0)
        cout << "1000000 ";
    else if(bz.size() == 1)
        cout << bz[0] << ' ';
    else
        cout << bz[1] - bz[0] << ' ';
    return 0;
}