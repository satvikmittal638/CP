#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
       map<int,int> f;
       for(int i=0;i<n;i++) {
        int a;
        cin>>a;
        f[a]++;
       }
       int cnt=0;
       pair<int,int> last={0,0};
       for(auto p:f){
        // just the beginning
        if(last.first==0){
            cnt+=p.second;
        }else{
            // if current doll is consecutive with prvs doll
            if(p.first-last.first==1){
                 // merge as much as possible
                cnt+=max(p.second-last.second,0);
            }else{
                cnt+=p.second; // make another grp since its not mergeable
            }
        }
        last=p;
       }
       cout<<cnt<<"\n";
       
    }
    return 0;
}