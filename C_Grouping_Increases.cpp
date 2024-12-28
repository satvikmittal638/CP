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
       int x=INT_MAX,y=INT_MAX,ans=0;

       for(int i=0;i<n;i++){
        int a;cin>>a;
        if(x>y) swap(x,y); // to assume x<=y WLOG
        // insert at back of the array with smaller last elt
        // to increase range of values<last elt
        if(a<=x){
            x=a;
        }
        // insert at back of array with larger last element
        // to avoid incurring a penalty
        // min(x,y)<a && a<=max(x,y)
        else if(a<=y){
            y=a;
        }
        else{
            x=a;
            ans++;
        }
       }
       cout<<ans<<"\n";
    }
    return 0;
}