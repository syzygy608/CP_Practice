#include <bits/stdc++.h>

using namespace std;

const double pi = acos(-1);
double h, r, da, dw;
double ha, hw;

double cal(double hw)
{
    double ha = h - hw;
    
    double cw = hw / 2.0; // 水的質心
    double ca = h - ha / 2.0; // 空氣的質心

    return (cw * dw * hw + ca * da * ha) / (dw * hw + da * ha);
}

int main()
{
    cin >> h >> r >> da >> dw;
    double L = 0, R = h;
    int times = 100000;
    while(times--)
    {
        double a = (2.0 * L + R) / 3.0;
        double b = (L + 2.0 * R) / 3.0;
        if(cal(a) < cal(b))
            R = b;
        else
            L = a;
    }
    cout << fixed << setprecision(10) << L << '\n';
}   