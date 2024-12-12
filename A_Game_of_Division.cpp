#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt;cin>>tt;
    while(tt--){
       int n,k;cin>>n>>k;
       vector<int> a(n);for(auto &i:a) cin>>i;
       bool meWin;
       int i;
       for(i=0;i<n;i++){
        meWin=1;
        for(int j=0;j<n;j++){
            if(i!=j && abs(a[i]-a[j])%k==0){
                meWin=0;
            }
        }
        if(meWin) break;
       }
       if(meWin){
        cout<<"YES\n"<<i+1<<"\n";
       }else{
        cout<<"NO\n";
       }
    }
    return 0;
}