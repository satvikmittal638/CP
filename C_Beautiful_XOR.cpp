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
       int a,b,c;cin>>a>>b;
       c=a^b;
       vector<int> ans;
       bool ok=1;
       for(int i=0;i<31;i++){
        int mask=(1<<i);
        
        if(c&mask) {
            ans.push_back(mask);
            if(mask>a){
                ok=0;
                break;
            } 
        }
       }
       if(ok){
        cout<<ans.size()<<'\n';
        for(auto e:ans) cout<<e<<' ';
       }
       else{
        cout<<-1;
       }
       cout<<'\n';
    }
    return 0;
}