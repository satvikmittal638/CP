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
       vector<int> cnt(n+1,0);
       for(int i=0;i<n;i++){
        int a;cin>>a;
        cnt[a]++;
       }
       // any subset of size k-1 of the original array can be chosen
       // find mex of original array, then bound it by k-1(we can remove elts from back and mex drops to k-1 if mex of original array>k-1)
       int mex=0;
       while(cnt[mex]>0) mex++;
       cout<<min(mex,k-1)<<'\n';
    }
    return 0;
}