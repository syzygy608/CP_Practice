#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

struct Matrix
{
    int n;
    vector<vector<ll>> mat;
    Matrix(int n) : n(n), mat(n, vector<ll>(n)) {}
    Matrix operator*(const Matrix& other)
    {
        Matrix product(n);
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                ll sum = 0;
                for(int k = 0; k < n; ++k)
                {
                    sum += mat[i][k] * other.mat[k][j];
                    sum %= mod;
                }
                sum %= mod;
                product.mat[i][j] = sum;
            }
        }
        return product;
    }    
};

Matrix power(Matrix mat, ll p)
{
    Matrix product(mat.n);
    for(int i = 0; i < mat.n; ++i)
        product.mat[i][i] = 1;
    while(p)
    {
        if(p & 1)
            product = product * mat;
        mat = mat * mat;
        p >>= 1;
    }
    return product;
}

int main()
{
    ll n;
    cin >> n;
    Matrix base(6), a(6);
    // dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3] + dp[i - 4] + dp[i - 5] + dp[i - 6]
    for(int i = 0; i < 5; ++i)
        base.mat[i][i + 1] = 1;
    base.mat[5][0] = base.mat[5][1] = base.mat[5][2] = base.mat[5][3] = base.mat[5][4] = base.mat[5][5] = 1;
    a.mat[0][0] = a.mat[0][1] = a.mat[0][2] = a.mat[0][3] = a.mat[0][4] = a.mat[0][5] = 1;
    a = a * power(base, n - 1);
    cout << a.mat[0][5] << '\n';
}