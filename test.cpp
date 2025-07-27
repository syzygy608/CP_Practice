#include<bits/stdc++.h>
using namespace std;
#define int long long 
string str;
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>str;
    string mnc="$";
    for(auto i:str)
    {
        mnc.push_back('#');
        mnc.push_back(i);
    }
    mnc+="#&";
    //cout<<mnc<<'\n';
    int len=mnc.length();
    vector<int> p(len,0);
    int mid=0,right=0;
    for(int i=1;i<mnc.length()-1;i++){
        int another=2*mid-i;
        if(i<right){
            p[i]=min(p[another],right-i);
        }
        while(mnc[i+1+p[i]]==mnc[i-1-p[i]])
            p[i]++;
        if(i+p[i]>right){
            mid=i;
            right=i+p[i];
        }
    }
    int ansl=0,ansp=0;
    for(int i=0;i<p.size();i++){
        if(p[i]>ansl){
            ansl=p[i];
            ansp=i;
        }
    }
    cout<<str.substr((ansp-ansl)/2,ansl)<<'\n';
}