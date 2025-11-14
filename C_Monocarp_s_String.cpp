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
       vector<int> a(n+1,0);
       for(int i=1;i<=n;i++){
        char c;cin>>c;
        a[i]=(c=='a')-(c=='b');
       }
       int s=accumulate(all(a),0);
       vector<int> sumToInd(2*n+1,-1);// sum=i is stored as n+i
       sumToInd[n]=0; // empty subarray sums to 0
       int ans=INT_MAX,cur=0;
       if(s==0) ans=0;
       for(int i=1;i<=n;i++){
        cur+=a[i];
        int l=sumToInd[n+(cur-s)];
        // valid l<r exists
        if(l!=-1){
            ans=min(ans,i-l);
        }
        sumToInd[n+cur]=i;
       }
    //    for(int i=1;i<=2*n;i++) cout<<sumToInd[i]<<' ';
       if(ans>=n) ans=-1;
       cout<<ans<<'\n';
    }
    return 0;
}