#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long tt;cin>>tt;
    while(tt--){
       long long n;cin>>n;
       vector<long long> a(n+1),pref(n+1,0);
       for(long long i=1;i<=n;i++){
        cin>>a[i];
        pref[i]=pref[i-1]+a[i];
       }
       string s;cin>>s;
       s=' '+s;
       stack<pair<long long,long long>> st;
       long long i=1,j=n;
       while(i<j){
        if(s[i]=='L' && s[j]=='R'){
            st.push({i,j});
            i++;j--;
        }
        else{
            if(s[i]=='R') i++;
            if(s[j]=='L') j--;
        }
       }
       long long ans=0;
       while(st.size()){
        pair<long long,long long> top=st.top();
        long long l=top.first,r=top.second;
        st.pop();
        ans+=pref[r]-pref[l-1];
       }  
       cout<<ans<<"\n";  
    }
    return 0;
}