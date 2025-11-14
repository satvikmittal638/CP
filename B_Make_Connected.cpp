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
       vector<string> grid(n);for(auto &i:grid) cin>>i;
        // count total blacks
       int cntB=0;
       for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cntB+=grid[i][j]=='#';
        }
       }
       // check that only a single 2x2 square can be formed
       bool ok=0;
       if(n<=2) ok=1;
       for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1;j++){
            int curCntB=(grid[i][j]=='#')+(grid[i+1][j]=='#')+(grid[i][j+1]=='#')+(grid[i+1][j+1]=='#');
            // all blacks are confined in a 2X2 square
            if(curCntB==cntB) ok=1;
        }
       }
      
       // all blacks must lie on the zig-zag paths
       auto check=[&](){
           if(cntB == 0){ ok = 1; return; }  // no black cells

           int ti=-1,tj=-1,bi=-1,bj=-1;
           for(int i=0;i<n;i++){
               for(int j=0;j<n;j++){
                   if(grid[i][j]=='#'){
                       if(ti==-1){ ti=i; tj=j; }
                       bi=i; bj=j;
                   }
               }
           }

           // path-1
           int i=ti,j=tj,curCntB=0;
           bool flag=1;
           while(i<n && j<n && i<=bi && j<=bj){
               curCntB+=grid[i][j]=='#';
               if(flag) j++; else i++;
               flag=!flag;
           }
           if(curCntB==cntB){ ok=1; return; }

           // path-2
           i=ti,j=tj,curCntB=0;
           flag=0;
           while(i<n && j<n && i<=bi && j<=bj){
               curCntB+=grid[i][j]=='#';
               if(flag) j++; else i++;
               flag=!flag;
           }
           if(curCntB==cntB) ok=1;
       };
        check();
        // flip the grid R<->L(mirror it)
        for(int i=0;i<n;i++){
            int l=0,r=n-1;
            while(l<=r){
                swap(grid[i][l],grid[i][r]);
                l++;r--;
            }
        }
        check(); // check again

        cout<<(ok?"YES":"NO")<<'\n';
    }
    return 0;
}