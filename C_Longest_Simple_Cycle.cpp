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
       vector<ll> c(n),a(n),b(n),len(n);for(auto &i:c) cin>>i;
       for(auto &i:a) cin>>i;for(auto &i:b) cin>>i;
       // len[i] is length of longest cycle ending at the i-th chain(whole i-th chain is part of the cycle at its right)
       len[0]=0; // single chain-> no cycle
       for(int i=1;i<n;i++){
        // either end the cycle at (i-1)-th or extend it further
        // to extend it further, remove the segment [a[i],b[i]] from the longest cycle ending at (i-1) and then add its length
        // c[i]-1 is length of i-th chain, and we add +2 for edges--> total c[i]+1 from i-th chain
        
        // also if a[i]=b[i], then we can't extend the chain backwards 
        len[i]=c[i]+1+(a[i]!=b[i])*max(abs(a[i]-b[i]),len[i-1]-abs(a[i]-b[i])); 
       }
       cout<<*max_element(all(len))<<"\n";

    }
    return 0;
}