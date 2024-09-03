#include <bits/stdc++.h>

#define X first
#define Y second
#define all(x) (x).begin(), (x).end()
using namespace std;

using ll = long long;

void count_sort(vector<int> &pos, vector<int> &rank)
{
    int n = pos.size();
    vector<vector<int>> cnt(n);
    for(int i: pos)
        cnt[rank[i]].push_back(i);
    for(int i = 0, idx = 0; i < n; ++i)
        for(auto x: cnt[i])
            pos[idx++] = x;
}

void get_suffix(string &s, vector<int> &sa)
{
    s += '$';
    int n = s.size();
    vector<int> rank(n);
    iota(all(sa), 0);
    sort(all(sa), [&](int a, int b)
    {
        return s[a] < s[b];
    });
    for(int i = 0; i < n; ++i)
    {
        if(i == 0)
            rank[sa[i]] = 0;
        else
            rank[sa[i]] = rank[sa[i - 1]] + (s[sa[i]] != s[sa[i - 1]]);
    }
    vector<int> new_rank(n);
    for(int k = 0; (1 << k) <= n; ++k)
    {
        for(int i = 0; i < n; ++i)
            sa[i] = (sa[i] - (1 << k) % n + n) % n;
        count_sort(sa, rank);
        new_rank[sa[0]] = 0;
        for(int i = 1;i < n;i++)
        {
            pair<int,int> prev = {rank[sa[i - 1]], rank[(sa[i - 1] + (1 << k)) % n]};
            pair<int,int> now = {rank[sa[i]], rank[(sa[i] + (1 << k)) % n]};
            new_rank[sa[i]] = new_rank[sa[i - 1]] + (prev != now);
        }
        rank = new_rank;
    }
}

void sol()
{
    string a, b;
    cin >> a >> b;
    int n = a.size(), m = b.size();
    vector<int> sa1(n + 1), sa2(m + 1);
    get_suffix(a, sa1);
    get_suffix(b, sa2);
    string ans1 = a.substr(sa1[n]);
    string ans2 = b.substr(sa2[m]);
    int len = 0;
    for(int i = 0; i < (int)ans1.size(); ++i)
    {
        if(ans1[i] < ans2[0] && i)
            break;
        len = i;
    }
    cout << ans1.substr(0, len + 1) << ans2.substr(ans2) << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)
        sol();
}

