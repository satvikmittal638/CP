#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()

int main()
{
fastio;
    int n;cin>>n;
    vector<int> a(n);for(auto &i:a) cin>>i;
    auto lis=[](vector<int> ar){
        vector<int> lisEndingAt(ar.size()),bestEnd;
        for(int i=0;i<ar.size();i++){
            if(bestEnd.empty() || ar[i]>bestEnd.back()){
                bestEnd.push_back(ar[i]);
                lisEndingAt[i]=bestEnd.size();
            }
            else{
                auto it=upper_bound(all(bestEnd),ar[i]);// first elt strictly > ar[i]
                *it=ar[i]; // smaller ending for same length
                lisEndingAt[i]=it-bestEnd.begin()+1;
            }
        }
        return lisEndingAt;
    };
    auto lisEndingAt=lis(a);
    reverse(all(a));
    auto ldsStartingAt=lis(a);reverse(all(ldsStartingAt));
    int ans=0;
    // bitonic mustn't be lds or lis
    for(int i=0;i<n;i++){
        if(lisEndingAt[i]>1 && ldsStartingAt[i]>1)
        ans=max(lisEndingAt[i]+ldsStartingAt[i]-1,ans);
    }
    cout<<ans;
    return 0;
}