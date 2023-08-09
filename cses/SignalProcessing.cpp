#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <complex>

using namespace std;

typedef double ld;
typedef complex<ld> cd;
const int SIZE = 1<<19;
const ld PI = acos(-1);

int N, M, K;
vector<cd> A(SIZE), B(SIZE);

void fft(vector<cd> &a, bool inv){
    int N = (int) a.size();

    for(int i = 1, j = 0; i < N; i++){
        int bit = N>>1;
        for(; j&bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if(i < j)
            swap(a[i], a[j]);
    }

    for(int len = 2; len <= N; len <<= 1){
        ld theta = 2*PI / len * (inv ? -1 : 1);
        cd wlen(cos(theta), sin(theta));
        for(int i = 0; i < N; i += len){
            cd w(1);
            for(int j = 0; j < len / 2; j++){
                cd u = a[i+j], v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }

    if(inv)
        for(cd &z : a)
            z /= N;
}

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        A[i] = x;
    }
    for(int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        B[m - i - 1] = x;
    }
    fft(A, false);
    fft(B, false);
    for(int i = 0; i < SIZE; i++)
        A[i] *= B[i];
    fft(A, true);
    for(int i = 0; i < (n + m - 1); i++)
        cout << llround(A[i].real()) << " \n"[i == (n + m - 1)];
    return 0;
}