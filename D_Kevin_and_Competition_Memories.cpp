#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
constexpr int inf=1e9;

int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
        int n,m;cin>>n>>m;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
            a[i]=max(a[i],a[0]); // remove all players less rated than Kevin(a[0])
        }
        sort(all(a));
        vector<int> b(m);
        for(int i=0;i<m;i++){
            cin>>b[i];
            if(b[i]<=a[0]) b[i]=inf+1; // remove problems which can be solved by a[0] since they don't decide his rank
        }
        sort(rall(b));
        // update b[i] with number of players who could solve the ith problem
        for(int i=0;i<m;i++){
            b[i]=a.end()-lower_bound(all(a),b[i]);
        }
        for(int k=1;k<=m;k++){
            ll ans=0ll;
            for(int i=k-1;i<m;i+=k){
                ans+=b[i]+1; // rank(a[0])=(1+ the number of contestants who solve at least one problem in that competition )
            }
            cout<<ans<<" \n"[k==m]; // prints \n after the last iteration and a space otherwise
        }
    }
    return 0;
}