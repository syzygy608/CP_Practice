#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll square(double r){
    ll count = 0;
    for(int i = 1; i <= r; ++i)
        count += 4ll * (int)sqrt(r * r - i * i);

    return count;
}

int main(){
    int s;
    cin >> s;
    double L = 0.0, R = 30000;
    double ans = R;
    int times = 200;
    while(times--){
        double mid = (L + R) / 2.0;
        if(square(mid) > s){
            ans = mid;
            R = mid;
        }
        else
            L = mid;
    }
    cout << fixed << setprecision(10) << ans << '\n';
}