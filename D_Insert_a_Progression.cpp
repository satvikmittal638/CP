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
       int n,x;cin>>n>>x;
       vector<int> a(n);for(auto &i:a) cin>>i;
       int mn=*min_element(all(a)),mx=*max_element(all(a));
       ll ans=0ll;
       for(int i=0;i<n-1;i++) ans+=abs(a[i]-a[i+1]);
       // elts<mn and/or >mx are left to be adjusted
       if(1<mn){
        // if(a[0]!=mn && a[n-1]!=mn) ans+=2*(mn-1);
        // else ans+=mn-1;
        ans+=min({2*(mn-1),a[0]-1, a[n-1]-1});
       }
       if(x>mx) {
        // if(a[0]!=mx && a[n-1]!=mx) ans+=2*(x-mx);
        // else ans+=x-mx;
        ans+=min({2*(x-mx),x-a[0],x-a[n-1]});
       }
       cout<<ans<<'\n';
    }
    return 0;
}