#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    // Precompute gcd of all pairs (x,y) for x,y<=5000
    int MAX=5001;
    vector<vector<int>> h(MAX,vector<int>(MAX,-1));
    // base case
    for(int i=0;i<MAX;i++){
        h[i][0]=h[0][i]=i;
    }
    for(int i=1;i<MAX;i++){
        // i>=j now
        for(int j=1;j<=i;j++){
            h[i][j]=h[j][i%j];
            h[j][i]=h[i][j]; // symmetry
        }
    }

    int tt;cin>>tt;
    while(tt--){
       int n,g=0;cin>>n;
       vector<int> a(n);for(auto &i:a) {
        cin>>i;
        g=h[i][g];
       }
       int cntg=count(all(a),g);
       if(cntg>0){
        cout<<n-cntg<<"\n";
        continue;
       }
       vector<int> f(MAX,MAX);
       // base case reqd
       for(int i=0;i<n;i++){
        f[a[i]]=0;
       }
       for(int x=MAX-1;x>=0;x--){
        for(int i=0;i<n;i++){
            f[h[x][a[i]]]=min(f[h[x][a[i]]],f[x]+1);
        }
       }
       int ans=f[g]+n-1;// 1 elt is now made into g using minm no. of opn
       cout<<ans<<"\n";
    // for(int i=1;i<=30;i++){
    //     cout<<f[i]<<" ";
    // }
    }
    return 0;
}