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
       int a,b,k;cin>>a>>b>>k;
       vector<int> boy(k),girl(k);
       map<int,int> startWithB, endWithG;
       map<pair<int,int>,int> BG;
       for(auto &i:boy) {
        cin>>i;
        startWithB[i]++;
       }
       for(auto &i:girl) {
        cin>>i;
        endWithG[i]++;
       }
       for(int i=0;i<k;i++){
        BG[{boy[i],girl[i]}]++;
       }
       ll ans=0ll;
       for(int i=0;i<k;i++){
        ans+=k-(startWithB[boy[i]])-(endWithG[girl[i]])+(BG[{boy[i],girl[i]}]);
       }
       cout<<ans/2<<"\n";

    }
    return 0;
}