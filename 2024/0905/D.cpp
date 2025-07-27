#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define MOD 998244353;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> vec(n);
        for(int i = 0; i < n; i++) cin >> vec[i];

        int l = 0, r = vec.size();
        while(l < r){
            for(int i = l; i < r - 1; i++){
                // if(vec[i+1] % vec[i] == 0)
                ll ta = __gcd(vec[i], vec[i+1]);
                ll tb = vec[i] * vec[i+1] / ta;
                vec[i] = ta;
                vec[i+1] = tb;
            }
            // if(vec[i+1] % vec[i] == 0){
                
            // }
            r--;
            
        }

        ll ans = 0;
        for(int i = 0; i < n; i++){
            ans += vec[i] % MOD;
        }
        cout << ans % MOD;
    }

    return 0;
}