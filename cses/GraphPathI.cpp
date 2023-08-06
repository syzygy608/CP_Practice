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
    int n, m, k;
    cin >> n >> m >> k;
    Matrix base(n);
    for(int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;
        base.mat[u][v]++;
    }
    base = power(base, k);
    cout << base.mat[0][n - 1] << '\n';
}