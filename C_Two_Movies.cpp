#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
       vector<int> a(n),b(n);
       for(auto &i:a) cin>>i;
       for(auto &i:b) cin>>i;

       int rate1=0,rate2=0,cnt_11=0,cnt_neg11=0;
       for(int i=0;i<n;i++){
        if(a[i]>b[i]){
            rate1+=a[i];
        }
        else if(a[i]<b[i]){
            rate2+=b[i];
        }else{
            cnt_11+=a[i]>0;
            cnt_neg11+=a[i]<0;
        }
       }
       int ans=INT_MIN;
       for(int i=-cnt_neg11;i<=cnt_11;i++){
        ans=max(ans,min(rate1+i,rate2+(cnt_11-cnt_neg11-i)));
       }
       cout<<ans<<"\n";
     


       
    }
    return 0;
}