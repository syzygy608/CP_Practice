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
const int maxn = 2e2;
int record[maxn][maxn], dx[] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[] = {-1, 0, 1, -1, 1, -1, 0, 1}, ans[maxn][maxn], tmp[maxn][maxn];

int main()
{
    int h, w;
    cin >> h >> w;
    h += 2;
    w += 2;
    for(int i = 1; i <= h; ++i)
    {
        for(int j = 1; j <= w; ++j)
        {
            cin >> record[i][j];
            tmp[i][j] = record[i][j];
        }
    }
    for(int i = 2; i <= h - 1; ++i)
    {
        for(int j = 2; j <= w - 1; ++j)
        {
            if(tmp[i - 1][j - 1] == 1)
            {
                // 放放看
                ans[i][j] = 1;
                tmp[i][j]--;
                // 更新對周圍的影響
                for(int k = 0; k < 8; ++k)
                    tmp[i + dx[k]][j + dy[k]]--;
            }
            else if(tmp[i - 1][j - 1] != 0)
            {
                // 只能是 0 or 1
                cout << "impossible\n";
                return 0;
            }
        }
    }
    for(int i = 1; i <= h; ++i)
    {
        for(int j = 1; j <= w; ++j)
        {
            // 還原看看
            int sum = ans[i][j];
            for(int k = 0; k < 8; ++k)
                sum += ans[i + dx[k]][j + dy[k]];
            if(sum != record[i][j])
            {
                cout << "impossible\n";
                return 0;
            }
        }
    }
    for(int i = 2; i <= h - 1; ++i)
    {
        for(int j = 2; j <= w - 1; ++j)
            cout << ((ans[i][j]) ? 'X' : '.');
        cout << '\n';
    }
    return 0;
}