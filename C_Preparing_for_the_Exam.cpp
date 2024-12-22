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
       int n,m,k;cin>>n>>m>>k;
       vector<int> a(m),q(k);
       vector<bool> canAns(n+1,0);
       for(auto &i:a) cin>>i;
       for(auto &i:q) {
        cin>>i;
        canAns[i]=1;
       }
       string ans;
       int answersIknow=count(canAns.begin()+1,canAns.end(),1);
       if(answersIknow<n-1) ans=string(m,'0');
       else if(answersIknow==n) ans=string(m,'1');
       else{
        for(int i=0;i<m;i++){
            if(canAns[a[i]]){
                ans+='0';
            }else{
                ans+='1';
            }
        }
       }
       cout<<ans<<"\n";

    }
    return 0;
}