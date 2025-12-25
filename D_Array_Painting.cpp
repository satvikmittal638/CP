#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()

struct block{
    int st,en,cnt2;
};

int main()
{
fastio;
    int n;cin>>n;
    vector<int> a(n);for(auto &i:a) cin>>i;
    // edge case: all 0s
    if(count(all(a),0)==n){
        cout<<n;
        return 0;
    }
    // compute blocks of non-0s
    vector<block> blocks;
    vector<bool> colored(n,0);
    for(int i=0;i<n;i++){
        if(a[i]==0) continue;
        // found 1st non-0, start building the block
        int st=i,en=i,cnt2=0;
        while(en<n && a[en]>0) {
            colored[en]=1;
            if(a[en]==2) cnt2++;
            en++;
        }
        i=en;// i points to a 0 elt
        en--;// points to last non-0 elt of the block
        blocks.emplace_back(st,en,cnt2);
    }
    int ans=blocks.size();// 1 coin is needed for each block
    for(const auto &b:blocks){
        // extend both sides
        if(b.cnt2>0){
            if(b.st>0)colored[b.st-1]=1;
            if(b.en<n-1)colored[b.en+1]=1;
        }
    }
     for(const auto &b:blocks){
        // all 1s, can extend in 1 dirn only
        if (b.cnt2 == 0) {
        // try to color a neighbor that is not yet colored
        // first try the 0 prvs to this block since the next block can't touch it
        if (b.st > 0 && !colored[b.st - 1]) {
            colored[b.st - 1] = 1;
        } else if (b.en < n - 1 && !colored[b.en + 1]) {
            colored[b.en + 1] = 1;
        }
    }
    }
    // now color remaining 0s on a paid basis
    ans+=count(all(colored),0);
    cout<<ans;
    return 0;
}