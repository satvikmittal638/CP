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
       int n,m;cin>>n>>m;
       string s;cin>>s;
       vector<int> lf(n,-1),rf(n,-1);
       for(int i=n-1;i>=0;i--){
        if(s[i]=='1'){
            lf[i]=i;
        }
        else if(i<n-1){
            lf[i]=lf[i+1];
        }
       }
       for(int i=0;i<n;i++){
        if(s[i]=='0'){
            rf[i]=i;
        }
        else if(i>0){
            rf[i]=rf[i-1];
        }
       }
       set<pair<int,int>> st;
       while(m--){
        int l,r;cin>>l>>r;l--;r--;
        int lb=lf[l], rb=rf[r];
        if(lb==-1 || rb==-1 || lb>=rb){
            st.insert({-1,-1});// for original string
        }
        else{
            st.insert({lb,rb});
        }
       }
       cout<<st.size()<<"\n";
    }
    return 0;
}