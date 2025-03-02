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
       int n,k;cin>>n>>k;
       string s;cin>>s;
       vector<int> a(n);for(auto &i:a) cin>>i;
       auto isSafe=[&](int x){
        string newS;
        for(int i=0;i<n;i++){
            if(a[i]>x) newS.push_back(s[i]);
        }
        int cnt=(newS[0]=='B');
        for(int i=1;i<newS.size();i++){
           if(newS[i]=='B' && (newS[i-1]!='B')){
            cnt++;
           } 
        }
        return cnt<=k;
       };
       int lo=0,hi=*max_element(all(a)),ans;
       while(lo<=hi){
        int mid=(lo+hi)/2;
        // cout<<mid<<" ";
        if(isSafe(mid)){
            ans=mid;
            hi=mid-1;
        }
        else{
            lo=mid+1;
        }
       }
    //    cout<<"\n";
    //    cout<<isSafe(0);
       cout<<ans<<"\n";
    }
    return 0;
}