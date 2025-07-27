#include<bits/stdc++.h>
using namespace std;

vector<int> dp[2];

int main()
{
    int n, s;
    cin >> n >> s;
    int arr[n];
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    if(sum == s)
        cout << n << '\n';
    else
        cout << n - 1 << '\n';
    return 0;
}