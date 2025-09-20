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
       vector<int> a(n),b(n);
       for(int i=0;i<n;i++) cin>>a[i]>>b[i];
       vector<bool> selected(n,1); // initially select all

       // g(S')=0
       // brute check all pairs of intervals
       for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j) continue;
            // check if ith pair is contained inside j-th pair(the reverse is also checked since we loop j from 0 to n)
            // remove i-th pair then
            if(a[j]<=a[i] && b[i]<=b[j]){
                selected[i]=0;
            }
        }
       }
       int k=accumulate(all(selected),0);
       cout<<k<<"\n";
       for(int i=0;i<n;i++){
        if(selected[i]) cout<<i+1<<" ";
       }
       cout<<"\n";

    }
    return 0;
}