#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt;cin>>tt;
    while(tt--){
       int n,m;cin>>n>>m;
       vector<int> cnt(m,0);
       while(n--){
        int a;cin>>a;
        cnt[a%m]++;
       }
       int ans=cnt[0]>0;
       if(m%2==0) ans+=cnt[m/2]>0;
       for(int i=1;2*i<m;i++){
        ans+=1+max(0,abs(cnt[i]-cnt[m-i])-1);
       }
       cout<<ans<<"\n";
    }
    return 0;
}