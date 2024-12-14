#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt;cin>>tt;
    while(tt--){
       int n;char c;string s;
       cin>>n>>c>>s;
       if(count(s.begin(),s.end(),c)==n){
        cout<<0;
       }else{
        vector<int> ans;
        bool ok;
        // Imp Observation: if for some x all its multiples in [1,n] are c, then that x can be chosen 
        // to change others to c
        // these nested loop run in O(nlogn)
        for(int x=1;x<=n;x++){
            ok=1;
            for(int j=x;j<=n;j+=x){
                ok&=s[j-1]==c;
            }
            if(ok){
                ans.push_back(x);
                break;
            }
        }
        if(!ok){
            ans.push_back(n-1);
            ans.push_back(n);
        }
        cout<<ans.size()<<"\n";
        for(auto e:ans) cout<<e<<" ";
       }
       cout<<"\n";
    }
    return 0;
}