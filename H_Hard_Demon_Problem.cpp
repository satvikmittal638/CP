#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
  cin.tie(nullptr);
    int tt;cin>>tt;
    while(tt--){
        int n,q;cin>>n>>q;
        vector<vector<long long>>
                                p_iMij(n+1,vector<long long>(n+1,0ll)),
                                p_jMij(n+1,vector<long long>(n+1,0ll)),
                                p_Mij(n+1,vector<long long>(n+1,0ll));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                long long Mij;
                cin>>Mij;
                p_Mij[i][j]=p_Mij[i-1][j]+p_Mij[i][j-1]-p_Mij[i-1][j-1]+Mij;
                p_iMij[i][j]=p_iMij[i-1][j]+p_iMij[i][j-1]-p_iMij[i-1][j-1] + i*Mij;
                p_jMij[i][j]=p_jMij[i-1][j]+p_jMij[i][j-1]-p_jMij[i-1][j-1] + j*Mij;
            }
        }
        while(q--){
            int x1,x2,y1,y2;cin>>x1>>y1>>x2>>y2;
            long long sumiMij=p_iMij[x2][y2]-p_iMij[x1-1][y2]-p_iMij[x2][y1-1]+p_iMij[x1-1][y1-1],
                    sumjMij=p_jMij[x2][y2]-p_jMij[x1-1][y2]-p_jMij[x2][y1-1]+p_jMij[x1-1][y1-1],
                    sumMij=p_Mij[x2][y2]-p_Mij[x1-1][y2]-p_Mij[x2][y1-1]+p_Mij[x1-1][y1-1];
            long long w=y2-y1+1;
            long long ans=w*sumiMij-(x1*w+(y1-1))*sumMij + sumjMij;
            cout<<ans<<" ";
        }
        cout<<"\n";

    }
    return 0;
}