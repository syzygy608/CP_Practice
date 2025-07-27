#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    while(n--){
        int p[9] = {0}, s[9] = {0}, m[9] = {0}, z[7] = {0};
        string str;
        cin >> str;
        for(int i = 0; i < str.size(); i+=2){
            if(str[i+1] == 'p'){
                p[str[i]-'1']++;
            }
            if(str[i+1] == 's'){
                s[str[i]-'1']++;
            }
            if(str[i+1] == 'm'){
                m[str[i]-'1']++;
            }
            if(str[i+1] == 'z'){
                z[str[i]-'1']++;
            }
        }
        if(p[0] > 0 && p[8] > 0 && s[0] > 0 && s[8] > 0 && m[0] > 0 && m[8] > 0 &&
            z[0] > 0 && z[1] > 0 && z[2] > 0 && z[3] > 0 && z[4] > 0 && z[5] > 0 && z[6] > 0){
            cout << "Thirteen Orphans\n";
            continue;
        }

        int cnt = 0;
        for(int i = 0; i < 9; i++){
            if(p[i] == 2) cnt++;
            if(s[i] == 2) cnt++;
            if(m[i] == 2) cnt++;
        }
        for(int i = 0; i < 7; i++){
            if(z[i] == 2) cnt++;
        }
        if(cnt == 7){
            cout << "7 Pairs\n";
            continue;
        }

        cout << "Otherwise\n";
    }
    return 0;
}