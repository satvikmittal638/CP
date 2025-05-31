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
       vector<int> c(10);for(auto &i:c) cin>>i;
       int mnDig=10,mnC=INT_MAX;
       // exclude 0 and compute the ans
       for(int i=1;i<10;i++){
        // count is given 1st pref
        if(c[i]<mnC){
            mnC=c[i];
            mnDig=i;
        }
        // digit value is given 2nd preference
        else if(c[i]==mnC && i<mnDig){
            mnDig=i;
        }
       }
       string ans1(mnC+1,'0'+mnDig);
       string ans2(c[0]+1,'0');ans2='1'+ans2;
    //    cout<<ans1<<" "<<ans2<<"\n";
       string ans;
       if(ans1.length()>ans2.length()){
        ans=ans2;
       }
       else if(ans1.length()<ans2.length()){
        ans=ans1;
       }
       else{
        // lexicographical comparison if same length
        ans=min(ans1,ans2);
       }
       cout<<ans<<"\n";
    }
    return 0;
}