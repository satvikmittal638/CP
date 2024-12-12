#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt;cin>>tt;
    while(tt--){
       int n,m,k;cin>>n>>m>>k;
       string s;cin>>s;
       s="L"+s; // treat starting surface as a Log
       vector<int> nextNearestSurface(n+1);
       nextNearestSurface[n]=n+1;// n+1 is ending surface
       for(int i=n-1;i>=0;i--){
        nextNearestSurface[i]=(s[i+1]=='L'?i+1:nextNearestSurface[i+1]);
       }
       bool isSafe=1;
       for(int i=0;i<=n;){
        if(s[i]=='L'){
            // its always beneficial to jump over swimming
            if((nextNearestSurface[i]-i)<=m){
                i=nextNearestSurface[i];
            }else{
                i+=m;// we reach W or C
            }
        }
        if(s[i]=='W'){
            if(nextNearestSurface[i]-i<=k){
                int nxtLog=nextNearestSurface[i];
                // swim each part step by step to check for crocodiles
                while(i<nxtLog && s[i]!='C'){
                    i++;
                }
            }else{
                // u will either freeze off or bitten by crocodile
                isSafe=0;break; 
            }
        }
        if(s[i]=='C'){
            isSafe=0;break;
        }
       }
        cout<<(isSafe?"YES\n":"NO\n");
    }
    return 0;
}