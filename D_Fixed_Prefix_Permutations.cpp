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
       vector<vector<int>> a(n,vector<int>(m)),inv_a(n,vector<int>(m));
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) {
            cin>>a[i][j];a[i][j]--;
            inv_a[i][a[i][j]]=j;
        }
       }
       // M-2: fast lookup via set
       set<vector<int>> st;
       for(int i=0;i<n;i++){
        vector<int> pref;
        for(int j=0;j<m;j++){
            pref.push_back(inv_a[i][j]);
            st.insert(pref);
        }
       }
       for(int i=0;i<n;i++){
        vector<int> pref;
        int ans=0;
        for(int j=0;j<m;j++){
            pref.push_back(a[i][j]);
            if(st.count(pref)) ans=pref.size();
            else break;
        }
        cout<<ans<<" ";
       }
       cout<<"\n";
    }
    return 0;
}