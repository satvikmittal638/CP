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
       vector<vector<bool>> r(2,vector<bool>(n+2,0));
       for(int j=0;j<2;j++){
           for(int i=1;i<=n;i++){
            char x;cin>>x;
            int dig=x-'0';
            if(dig==1 || dig==2) r[j][i]=0;
            else r[j][i]=1;
           }
       }
       bool ok=1,j=0;
       for(int i=1;i<n+1;i++){
        if((r[0][i]+ r[1][i])==2) j=!j; // change the row
        else if((r[0][i]+r[1][i])==1 && r[j][i]==1){
            ok=0;
            break;
        }
        // else keep the row same(do nothing)
       }
       ok&=(j==1);
       cout<<(ok?"YES":"NO")<<"\n";
       
    }
    return 0;
}