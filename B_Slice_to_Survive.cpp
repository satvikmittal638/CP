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
       ll n,m,a,b;cin>>n>>m>>a>>b;
       int turns=0;
       while(n>1 && m>1){
        vector<vector<ll>> c={{a-1,m},{n-a,m},{n,m-b},{n,b}};
        // pick the best choice
        ll bestC,mxArea=LLONG_MIN;
        for(int i=0;i<4;i++){
            if(c[i][0]*c[i][1]>mxArea){
                mxArea=c[i][0]*c[i][1];
                bestC=i;
            }
        }
        // slice off and discard
        n-=c[bestC][0];
        m-=c[bestC][1];
        //move F to central position
        a=n/2;
        b=m/2;
        turns++;
       }
       cout<<turns<<"\n";
    }
    return 0;
}