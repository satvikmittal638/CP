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
       int n,m,k;cin>>n>>m>>k;
       if(abs(n-m)>k || k>max(n,m)){
           cout<<"-1\n";
           continue;
       } 
       string ans;
       char mx_c='1',mn_c='0';
       if(n>=m) swap(mx_c,mn_c);
       if(n<m) swap(n,m);
       // now n>=m
        ans.append(k,mx_c);
        n-=k;
        int z=min(n,m);
        for(int i=1;i<=z;i++){
            ans+=mn_c;
            ans+=mx_c;
        }
        n-=z;
        m-=z;
        ans.append(n,mx_c);
        ans.append(m,mn_c);
        cout<<ans<<"\n";
    }
    return 0;
}