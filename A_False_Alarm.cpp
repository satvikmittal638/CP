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
       int n,x;cin>>n>>x;
       vector<bool> a(n);
       for(int i=0;i<n;i++) {
        int y;cin>>y;
        a[i]=y;
       }
      
       bool canPass=1,active=0;
       int flipAt=-1;
       for(int i=0;i<n && canPass;i++){
        if(a[i]==1 && flipAt==-1){
            flipAt=i;
            active=1;
        }
        if(i-flipAt==x && flipAt!=-1) active=0;
        if(!active) canPass&=!a[i];
        // if(!canPass) break;
       }
       cout<<(canPass?"YES":"NO")<<"\n";

        

    }
    return 0;
}