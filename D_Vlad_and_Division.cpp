#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    
    int k=0;
    for(int i=0;i<=30;i++){
        k+=(1<<i);
    }
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
       int ans=0;
       multiset<int> st;
       for(int i=0;i<n;i++){
        int a;cin>>a;
        auto it=st.find(k^a);
        // if u find a match, pair them up and remove them from any further look-ups
        if(it!=st.end()){
            st.erase(it);
            ans++;
        }
        else{
            st.insert(a);
        }
       }
       ans+=st.size(); // individual elts
       cout<<ans<<"\n";
    }
    return 0;
}