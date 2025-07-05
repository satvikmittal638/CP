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
       for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
       }
       auto isSafe = [&](int x) {
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] >= x - cnt - 1 && b[i] >= cnt) {
                cnt++;
            }
            if (cnt == x) break;
        }
            return cnt >= x;
        };
       // BS on x
       int lo=0,hi=n,ans=0;
       while(lo<=hi){
        int mid=(lo+hi)/2;
        if(isSafe(mid)){
            ans=mid;
            lo=mid+1;
        }
        else{
            hi=mid-1;
        }
       }
       cout<<ans<<"\n";
    // cout<<isSafe(2);
    }
    return 0;
}