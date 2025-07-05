#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    int n,m;cin>>n>>m;
    string s;cin>>s;
    string mask="abc";
    vector<vector<int>> prefs(6,vector<int>(n,0));
    int i=0;
    do{
        // create a string to compare against with
        string t;
        for(int i=0;i<n/3;i++){
            t+=mask;
        }
        // append remaining characters(if any)
        if(n%3==1){
            t+=mask[0];
        }
        else if(n%3==2){
            t+=mask[0];
            t+=mask[1];
        }
        // make prefix sum for the given permutation
        for(int j=0;j<n;j++){
            prefs[i][j]=(s[j]!=t[j]);
            if(j>0) prefs[i][j]+=prefs[i][j-1];
        }
        i++;
    }while(next_permutation(all(mask)));
    
    while(m--){
        int l,r;cin>>l>>r;l--;r--;
        int ans=INT_MAX;
        for(int i=0;i<6;i++){
            ans=min(ans,prefs[i][r]-(l>0?prefs[i][l-1]:0));
        }
        cout<<ans<<"\n";
    }
    return 0;
}