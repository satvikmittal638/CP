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
       int n;cin>>n;
       vector<int> ans(n);
       set<pair<int,int>> st;
       st.insert({-n,0});
       int op=1;
       while(st.size()){
        auto [sz,l]=*st.begin();
        st.erase(st.begin());
        sz*=-1;
        int r=l+sz-1,mid,len;
        if(sz%2!=0){
            mid=(l+r)/2;
            len=sz/2;
            if(len>0){
                st.insert({-len,l});
                st.insert({-len,mid+1});
            }
        }
        else{
            mid=(l+r-1)/2;
            len=sz/2;
            if(len>1)st.insert({-(len-1),l});
            if(len>0)st.insert({-(len),mid+1});
        }
        ans[mid]=op++;
       }
       for(auto e:ans) cout<<e<<" ";
       cout<<"\n";
    }
    return 0;
}