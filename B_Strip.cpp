#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
const int INF=1e9;
int main()
{
fastio;
    int n,dif,len;cin>>n>>dif>>len;
    vector<int> a(n+1),dp(n+1);
    for(int i=1;i<=n;i++)cin>>a[i];
    multiset<int> st_a,st_dp;
    int p1=1;
    // jmax=i-len+1 always
    // so (j-1)max=i-len
    for(int i=1;i<=n;i++){
        st_a.insert(a[i]);
        while(st_a.size() && *st_a.rbegin()-*st_a.begin()>dif){
            st_a.erase(st_a.find(a[p1]));
            // ! we remove dp[p1-1] rather than dp[p1] since we store all valid dps to which we can add 1 to get dp[i]
            // hence p1 is no longer a valid j and hence we can't use dp[p1-1]
            if(p1<=i-len)st_dp.erase(st_dp.find(dp[p1-1]));
            p1++;
        }
        if(p1<=i-len+1) st_dp.insert(dp[i-len]);
        if(st_dp.size()){
            dp[i]=*st_dp.begin()+1;
        }
        else{
            dp[i]=INF;
        }

    }
    cout<<(dp[n]>=INF?-1:dp[n]);
    return 0;
}