#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
const int K=25;
const int MAXN=1e5+1;

// pre C++20
int log2_floor(unsigned long long i) {
    return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}
int main()
{
fastio;
    int n;cin>>n;
    vector<int> a(n);for(auto &i:a) cin>>i;
    // sparse table
    vector<vector<int>> st(K,vector<int>(MAXN,0));
    copy(all(a),st[0].begin());

    for(int i=1;i<K;i++){
        for(int j=0;j+(1<<i)<=n;j++){
            st[i][j]=min(st[i-1][j],st[i-1][j+(1<<(i-1))]);
        }
    }
    int q;cin>>q;
    while(q--){
        int i,j;cin>>i>>j;
        int z=log2_floor(j-i+1);
        cout<<min(st[z][i],st[z][j-(1<<z)+1])<<'\n';
    }
    return 0;
}