#include <iostream>
#include <vector>
#include <array>
#include <cmath>
#include <algorithm>

using namespace std;
const int maxn = 2e5 + 5;
int n, q, block_size;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    block_size = max(1, (int)sqrt(n));
    vector<int> v(n), disc(n);
    for(int i = 0; i < n; ++i)
    {
        cin >> v[i];
        disc[i] = v[i];
    }
    sort(disc.begin(), disc.end());
    disc.erase(unique(disc.begin(), disc.end()), disc.end());
    for(int i = 0; i < n; ++i)
        v[i] = lower_bound(disc.begin(), disc.end(), v[i]) - disc.begin();
    vector<array<int, 3>> queries(q);
    for(int i = 0; i < q; ++i)
    {
        cin >> queries[i][0] >> queries[i][1];
        --queries[i][0], --queries[i][1];
        queries[i][2] = i;
    }
    sort(queries.begin(), queries.end(), [](const array<int, 3> &a, const array<int, 3> &b)
    {
        // sort with odd even optimization
        if(a[0] / block_size != b[0] / block_size)
            return a[0] < b[0];
        return (a[0] / block_size & 1) ? a[1] > b[1] : a[1] < b[1];
    });
    int l = 0, r = -1, distinct = 0;
    vector<int> ans(q);
    vector<int> freq(n);
    for(array<int, 3> el: queries)
    {
        while(r < el[1])
        {
            ++r;
            if(freq[v[r]] == 0)
                ++distinct;
            ++freq[v[r]];
        }
        while(r > el[1])
        {
            --freq[v[r]];
            if(freq[v[r]] == 0)
                --distinct;
            --r;
        }
        while(l < el[0])
        {
            --freq[v[l]];
            if(freq[v[l]] == 0)
                --distinct;
            ++l;
        }
        while(l > el[0])
        {
            --l;
            if(freq[v[l]] == 0)
                ++distinct;
            ++freq[v[l]];
        }
        ans[el[2]] = distinct;
    }
    for(int el: ans)
        cout << el << '\n';
}