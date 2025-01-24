#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    int n,m,d;cin>>n>>m>>d;
    vector<vector<int>> c(n,vector<int>(m));
    int curMod=-1,mn=INT_MAX;
    bool ok=1;
    ll avg=0ll;
    for(int i=0;i<n && ok;i++){
        for(int j=0;j<m && ok;j++){
            cin>>c[i][j];
            if(i!=0 && j!=0){
                curMod=c[i][j]%d;
                c[i][j]/=d;
            }else{
                if(c[i][j]%d!=curMod){
                    ok=0;
                }
                else{
                    c[i][j]/=d;
                }
            }
            avg+=c[i][j];            
        }
    }
    avg/=n*m;
    ll ans=0ll;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ans+=c[i][j]-mn;
        }
    }
    if(!ok) ans=-1;
    cout<<ans;
    return 0;
}