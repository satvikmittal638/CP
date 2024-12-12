#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
       vector<vector<bool>> a(n,vector<bool>(n));
       for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            char c;cin>>c;
            a[i][j]=c-'0';
        }
       }
       int ans=0;
       for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int cnt0=0,cnt1=0;
            int nowi=i,nowj=j;
            cnt0+=a[nowi][nowj]==0;
            cnt1+=a[nowi][nowj]==1;
            //rotate 90 deg
            int oldi=nowi,oldj=nowj;
            nowi=oldj;
            nowj=n-1-oldi;
            cnt0+=a[nowi][nowj]==0;
            cnt1+=a[nowi][nowj]==1;
            // rotate 90 deg again
            oldi=nowi,oldj=nowj;
            nowi=oldj;
            nowj=n-1-oldi;
            cnt0+=a[nowi][nowj]==0;
            cnt1+=a[nowi][nowj]==1;
            // rotate 90 deg again
            oldi=nowi,oldj=nowj;
            nowi=oldj;
            nowj=n-1-oldi;
            cnt0+=a[nowi][nowj]==0;
            cnt1+=a[nowi][nowj]==1;
            ans+=min(cnt0,cnt1);
        }
       }
       cout<<ans/4<<"\n"; // each subgrid counted 4 times
      
    }
    return 0;
}