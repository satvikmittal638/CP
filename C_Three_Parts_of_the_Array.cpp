#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;cin>>n;
    vector<long long> d(n+1),pref(n+1,0),suf(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>d[i];
        pref[i]=pref[i-1]+d[i];
    }
    reverse(d.begin()+1,d.end());
    for(int i=1;i<=n;i++){
        suf[i]=suf[i-1]+d[i];
    }
    long long ans;
    for(int a=n;a>=0;a--){
        if(binary_search(suf.begin(),suf.begin()+(n-a+1),pref[a])){
            ans=pref[a];
            break;
        } 
    }
    
    cout<<ans;
    return 0;
}