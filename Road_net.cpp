#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
       vector<vector<int>> adj(n+1,vector<int>(n+1));
       for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cin>>adj[i][j];
            }
       }
       for(int i=1;i<=n;i++){
//i!=j also i>j and i<j are symmetric cases
            for(int j=i+1;j<=n;j++){
                bool isAdj=1;
                // check if 2 cities are adjacent
                for(int k=1;k<=n;k++){
                    if(i!=k && k!=j && (adj[i][k]+adj[k][j]==adj[i][j])){
                        isAdj=0;break;
                    }
                }
                if(isAdj) cout<<i<<" "<<j<<"\n";
            }
       }
    }
    return 0;
}