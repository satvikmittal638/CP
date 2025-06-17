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
       string s;cin>>s;
       vector<int> state(s.size()+2,-1); // 0 for unsorted, 1 for sorted,-1 for unknown(both possible)
       state[0]=state[1]=1;
       int sz=0;
       bool ok=1;
       for(auto c:s){
        if(c=='+') {
            sz++;
            if(sz>=2 && state[sz]==1) state[sz]=-1;
        }
        else if(c=='-') {
            sz--;
            if(sz>=2 && state[sz]==0) state[sz]=-1;
        }
        
        else if(c=='0'){
            if(state[sz]==1){
                ok=0;break;
            }
            else{
                state[sz]=0;
            }
        }
        else if(c=='1'){
            if(state[sz]==0){
                ok=0;break;
            }
            else{
                state[sz]=1;
            }
        }
       }
       cout<<(ok?"YES":"NO")<<"\n";
    }
    return 0;
}