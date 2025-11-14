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
       int n,k;cin>>n>>k;
       vector<bool> used(n+1,0);
       vector<int> a(n);for(auto &i:a) {cin>>i;used[i]=1;}
       // a permutation
       int x,y,z;
       if(accumulate(all(used),0)==n){
        x=a[0];y=a[1];z=a[2];
       }
       else{
        // find unused elt and use as x
        for(int i=1;i<=n;i++){
            if(!used[i]){
                x=i;
                break;
            }
        }
        z=a[n-1];
        // set y different from x and z
        if(x!=1 && z!=1) y=1;
        else if(x!=2 && z!=2) y=2;
        else if(x!=3 && z!=3) y=3;
       }
       // now rpt x,y,z,x,y,z...
       for(int i=1;i<=k-(k%3);i+=3){
        cout<<x<<' '<<y<<' '<<z<<' ';
       }
       if(k%3==1){
        cout<<x;
       }
       else if(k%3==2){
        cout<<x<<' '<<y;
       }
       cout<<'\n';

       
    }
    return 0;
}