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
       string s;cin>>s;
       vector<vector<int>> pO(26,vector<int>(n,0)),pE(26,vector<int>(n,0));
       for(int i=0;i<n;i++){
        if(i%2==0) pE[s[i]-'a'][i]=1;
        else pO[s[i]-'a'][i]=1;
       }
       // make prefix sums
       for(int c=0;c<26;c++){
        for(int i=1;i<n;i++){
            pE[c][i]+=pE[c][i-1];
            pO[c][i]+=pO[c][i-1];
        }
       }

       if(n%2==0){
           int mxE=0,mxO=0;
            for(int c=0;c<26;c++){
                mxE=max(mxE,pE[c][n-1]);
                mxO=max(mxO,pO[c][n-1]);
            }
            // cout<<mxE<<" "<<mxO<<"\n";
            int ans=n-(mxE+mxO);
            cout<<ans<<"\n";
       }
       else{
        int ans=INT_MAX;
        // delete ith character
        for(int i=0;i<n;i++){
            int mxE=0,mxO=0;
            for(int c=0;c<26;c++){
                mxE=max(mxE,(i>0?(pE[c][i-1]):0)+(pO[c][n-1]-pO[c][i]));
                mxO=max(mxO,(i>0?(pO[c][i-1]):0)+(pE[c][n-1]-pE[c][i]));
            }
            ans=min(ans,(n-1)-mxE-mxO);
        }
        ans++; // 1 operation for deletion
        cout<<ans<<"\n";
       }
    }
    return 0;
}