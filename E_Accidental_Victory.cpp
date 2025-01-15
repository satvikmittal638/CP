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
       vector<pair<int,int>> inp(n);// a[i]->i
       for(int i=0;i<n;i++){
        cin>>inp[i].first;
        inp[i].second=i;
       }
        sort(all(inp));
        vector<int> a(n),idx(n);
        for(int i=0;i<n;i++){
            a[i]=inp[i].first;
            idx[i]=inp[i].second;
        }
        auto canWin=[&](int i){
            ll cur=a[i]*1ll;
            for(int j=0;j<n;j++){
                if(i==j) continue;
                if(a[j]<=cur){
                    cur+=a[j];
                }
                else return 0;
            }
            return 1;
        };
        // if player i can win, player i+1 can also win(in a sorted array a)
        int lo=-1,hi=n-1; 
        while(hi-lo>1){
            int mid=(lo+hi)/2;
            if(canWin(mid)){
                hi=mid;
            }
            else{
                lo=mid;
            }
        }
        cout<<n-hi<<"\n";
        vector<int> ans;
        for(int i=hi;i<n;i++){
            ans.push_back(idx[i]+1);
        }
        sort(all(ans));
        for(auto e: ans) cout<<e<<" ";
        cout<<"\n";
    }
    return 0;
}