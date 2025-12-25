#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
const int K=25;
const int MAXN=5*1e4+1;

// pre C++20
int log2_floor(unsigned long long i) {
    return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}
int main()
{
fastio;
    int n,m;cin>>n>>m;
    vector<int> h(n);for(auto &i:h) cin>>i;
    vector<vector<int>> st(K,vector<int>(MAXN,0));
    copy(all(h),st[0].begin());// base case
    for(int i=1;i<K;i++){
        for(int j=0;j+(1<<i)<=n;j++){
            st[i][j]=max(st[i-1][j],st[i-1][j+(1<<(i-1))]);
        }
    }

    int ans=0;
    while(m--){
        int l,r;cin>>l>>r;
        if(l>r) swap(l,r);
        l--;r-=2; // exclude hill b
        int i=log2_floor(r-l+1);
        ans+=max(st[i][l],st[i][r-(1<<i)+1])<=h[l];
    }
    cout<<ans;
    return 0;
}