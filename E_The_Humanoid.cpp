#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()

int solve(vector<int>& a,int i, ll h,int blue,int green){
    if(i==a.size()) return 0;
    if(a[i]<h){
        return solve(a,i+1,h+a[i]/2,blue,green)+1; // a[i] astronaut killed
    }
    int ans1=(blue>0?solve(a,i,3*h,blue-1,green):0);
    int ans2=(green>0?solve(a,i,2*h,blue,green-1):0);
    return max(ans1,ans2);
}

int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       ll n,h;cin>>n>>h;
       vector<int> a(n);for(auto &i:a) cin>>i;
       sort(all(a));
       cout<<solve(a,0,h,1,2)<<"\n";
    }
    return 0;
}