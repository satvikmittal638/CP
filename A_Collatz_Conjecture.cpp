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
       ll k,x;cin>>k>>x;
       for(int i=0;i<k;i++){
        if(x%2!=0){
            x*=2;
        }
        else{
            if((x-1)%3==0){
                x=(x-1)/3;
            }
            else{
                x*=2;
            }
        }
       }
       cout<<x<<'\n';
    }
    return 0;
}