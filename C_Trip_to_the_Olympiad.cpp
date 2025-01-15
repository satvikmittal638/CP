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
       int l,r;cin>>l>>r;
       int a=l,b=r,c=0;
       for(int i=0;i<log2(r);i++){
        if((a&(1<<i))==0 && (b&(1<<i))==0){
            c|=(1<<i);
        }
       }  
       if(c==l) c++;
       if(c==r) c--;     
       cout<<a<<" "<<b<<" "<<c<<"\n";
    }
    return 0;
}