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
       ll n,k;cin>>n>>k;
       vector<int> p(n+1);
       // start with an identity permutation
       iota(p.begin(), p.end(), 0);
       int i=1,j=n;
       while(i<j && (k-2*(j-i))>=0){
        swap(p[i],p[j]);
        k-=2*(j-i);
        i++;j--;
       }
       // apply 2-cycle on consecutive elements
       for(int z=i;k>=2 && z<j;z++){
        swap(p[z],p[z+1]);
        k-=2;
       }
       if(k>0){
        cout<<"No\n";
        continue;
       }
       cout<<"Yes\n";
       for(int i=1;i<=n;i++) cout<<p[i]<<" ";
       cout<<"\n";

    }
    return 0;
}