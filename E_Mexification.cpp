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
       vector<int> a(n),cnt(n+1,0);
       for(auto &i:a) {
        cin>>i;
       }
       // emulates the process and makes inplace changes to a
       auto emulate=[&](){
        cnt.assign(n+1,0);
        for(auto e:a) cnt[e]++;
           int m1=0;
           for(int i=0;i<=n;i++){
            if(cnt[i]==0){
                m1=i;
                break;
            }
           }
           for(int i=0;i<n;i++){
            if(a[i]>m1 || cnt[a[i]]>1) a[i]=m1;
           }
       };
       emulate();
       k--;
       if(k%2!=0) {
        emulate();k--;
       }
       // spam some more operations 
        if(k>0) {emulate();k--;}
        if(k>0) {emulate();k--;}
        if(k>0) {emulate();k--;}
        if(k>0) {emulate();k--;}
        cout<<accumulate(all(a),0ll)<<'\n';
        
    }
    return 0;
}