#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()

#ifndef ONLINE_JUDGE
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << endl;
    err(++it, args...);
}
#else
#define error(args...)
#endif

int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
       vector<int> a(n);for(auto &i:a) cin>>i;
       ll sum=0ll,ans=INT_MAX;
       for(int i=0;i<n-1;i++){
        sum+=abs(a[i+1]-a[i]);
       }
       for(int k=0;k<n;k++){
        ll cur=sum;
        if(k>0)cur-=abs(a[k]-a[k-1]);
        if(k<n-1)cur-=abs(a[k+1]-a[k]);
        if(0<k && k<n-1)cur+=abs(a[k+1]-a[k-1]);
        ans=min(ans,cur);
       }
       cout<<ans<<'\n';
    }
    return 0;
}