#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    deque<ll> dq;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    vector<ll> ans = a;
    for(int i = 0; i < n; i++)
    {
        while(!dq.empty() && a[dq.back()] >= a[i])
            dq.pop_back();
        ans[i] += (dq.empty()) ? i * a[i] : (i - dq.back() - 1) * a[i];
        dq.push_back(i);
    }
    dq.clear();
    for(int i = n - 1; i >= 0; i--)
    {
        while(!dq.empty() && a[dq.back()] >= a[i])
            dq.pop_back();
        ans[i] += (dq.empty()) ? (n - i - 1) * a[i] : (dq.back() - i - 1) * a[i];
        dq.push_back(i);
    }
    cout << *max_element(ans.begin(), ans.end()) << '\n';
}