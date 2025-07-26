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
       int n,m,k;cin>>n>>m>>k;
       int lo=1,hi=m,ans=m;
       while(lo<=hi){
            int mid=(lo+hi)/2;
            int max_case1 = (m + 1)/ 2;
            int num = mid * (m + 1);
            int den = mid + 1;
            int max_case2 = num/den;
            max_case2 = min(m, max_case2);
            int max_s_row = max(max_case1, max_case2);
            int total = max_s_row * n;
            if (total >= k){
                ans = mid;
                hi = mid - 1;
            }
            else
                lo = mid + 1;

       }
       cout<<ans<<"\n";
    }
    return 0;
}