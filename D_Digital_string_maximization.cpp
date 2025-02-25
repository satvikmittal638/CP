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
       string s;cin>>s;
       int n=s.length();
       set<pair<int,int>> st;//(d+p,p)
       for(int i=n-1;i>=0;i--){
        st.insert({(s[i]-'0')+i,i});
       }
       string ans;
       bool found=0;
       do{
        auto it=st.lower_bound({INT_MIN,})
       }while(found);


    }
    return 0;
}