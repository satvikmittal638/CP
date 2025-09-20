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
       string r,b;
      cin>>r>>b;
       int cntR=0,cntB=0;
       for(int i=0;i<n;i++){
        if(r[i]>b[i]) cntR++;
        else if(r[i]<b[i]) cntB++;
       }
       if(cntR>cntB){
        cout<<"RED";
       }
       else if(cntR<cntB){
        cout<<"BLUE";
       }
       else{
        cout<<"EQUAL";
       }
       cout<<"\n";
    }
    return 0;
}