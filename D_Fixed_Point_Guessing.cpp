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
       int n;cin>>n;
       int lo=1,hi=n;
       while(lo<hi){
        int mid=(lo+hi)/2;
        cout<<"? "<<lo<<" "<<mid<<endl;
        int cnt=0;
        for(int i=lo;i<=mid;i++){
            int x;cin>>x;
            cnt+=(lo<=x && x<=mid);
        }
        if(cnt%2!=0){
            hi=mid;
        }
        else{
            lo=mid+1;
        }
       }
       cout<<"! "<<lo<<endl;
    }
    return 0;
}