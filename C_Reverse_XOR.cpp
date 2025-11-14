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
       int st=-1,end=-1;
       for(int i=0;i<31;i++){
        int mask=(1<<i);
        // set bit found
        if(n&mask){
            if(st==-1) st=i;
            end=i;
        }
       }
       bool isPalin=1;
       int i=st,j=end;
       while(i<=j){
        int biti=(n&(1<<i))!=0,bitj=(n&(1<<j))!=0;
        if(biti!=bitj){
            isPalin=0;
            break;
        }
        i++;j--;
       }
       bool ok=1;
       if(!isPalin){
        ok=0;
       }
       else{
        if((end-st+1)%2!=0 && (n&(1<<((end+st)/2)))!=0){
            ok=0;
        }
       }
       cout<<(ok?"YES":"NO")<<'\n';
    }
    return 0;
}