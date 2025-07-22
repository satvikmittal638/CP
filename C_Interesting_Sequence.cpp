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
       ll n,m=0ll,x;cin>>n>>x;
       ll pos=61;
       // find position of first set bit in x
       for(ll i=0;i<62;i++){
        ll mask=(1ll<<i);
        if(mask&x){
            pos=i;
            break;
        }
       }
       // m is same from MSB to pos-1
       for(ll i=pos-1;i<62;i++){
        ll mask=(1ll<<i);
        if(x&mask) m|=mask;
       }
       
       ll maxPosToSet=-1;
       for(ll i=pos-2;i>=0;i--){
        ll mask=(1ll<<i);
        // if a bit is set in n but not in x, then a more significant bit must be set in m
        // this allows the bit at that position to become 0 in atleast one of the numbers in the range [n,m]
        if((mask&x)==0 && (mask&n)!=0){
            maxPosToSet=i+1ll;
            break;
        }
       }
    //    cout<<maxPosToSet<<" "<<m<<" ";
       if(maxPosToSet!=-1) m|=(1ll<<maxPosToSet);
       // all positions from pos till MSB must be same in both n,n+1...m and x  
       bool ok=1;
       for(ll i=max(pos-1,0ll);i<62;i++){
        ll mask=(1ll<<i);
        // differing bits
        if(((mask&x)==0 && (mask&n)!=0) || ((mask&n)==0 && (mask&x)!=0)){
            ok=0;
            break;
        }
       }
       cout<<(ok?m:-1)<<"\n";

    }
    return 0;
}