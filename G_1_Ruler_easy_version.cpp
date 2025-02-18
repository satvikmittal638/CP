#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       int lo=2,hi=999,ans=0;
       while(lo<=hi){
        int mid=(lo+hi)/2;
        cout<<"? "<<mid<<" "<<mid<<endl;
        int res;cin>>res;
        if(sqrt(res)==mid){
            lo=mid+1;
        }
        else{
            ans=mid;
            hi=mid-1;
        }
       }
       cout<<"! "<<ans<<endl;
    }
    return 0;
}