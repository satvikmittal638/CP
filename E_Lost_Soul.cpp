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
       vector<int> posa_rightmost(n+1,-1),posa_2ndrightmost(n+1,-1);
       vector<int> posb_rightmost(n+1,-1),posb_2ndrightmost(n+1,-1);
       vector<bool> ina(n+1,0),inb(n+1,0);
       for(int i=0;i<n;i++){
        int a;cin>>a;
        ina[a]=1;
        if(posa_rightmost[a]!=-1){
            posa_2ndrightmost[a]=posa_rightmost[a];
        }
        posa_rightmost[a]=i+1;// 1 indexed
       }
       for(int i=0;i<n;i++){
        int b;cin>>b;
        inb[b]=1;
        if(posb_rightmost[b]!=-1){
            posb_2ndrightmost[b]=posb_rightmost[b];
        }
        posb_rightmost[b]=i+1;// 1 indexed
       }
       int ans=0;
       for(int i=1;i<=n;i++){
        if(ina[i] && inb[i]){
            if(abs(posa_rightmost[i]-posb_rightmost[i])!=1){
                ans=max(ans,min(posa_rightmost[i],posb_rightmost[i]));
            }
        }
        if(posa_2ndrightmost[i]!=-1){
            ans=max(ans,posa_2ndrightmost[i]);
        }
        if(posb_2ndrightmost[i]!=-1){
            ans=max(ans,posb_2ndrightmost[i]);
        }
       }
       cout<<ans<<"\n";



    }
    return 0;
}