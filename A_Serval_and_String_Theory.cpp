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
       string rev;cin>>rev;
       string s=rev;
       set<char> st;
       for(auto c:s){
        st.insert(c);
       }
       reverse(all(rev)); 
       if((s>=rev && k==0) || st.size()==1) cout<<"NO\n";
       else cout<<"YES\n";

    }
    return 0;
}