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
       ll n,x;cin>>n>>x;
       ll base=0,maxw=0;
       for(int i=0;i<n;i++){
        ll a,b,c;cin>>a>>b>>c;
        base+=a*(b-1);
        maxw=max(maxw,a*b-c);// gives 1 roll back but adds max distance
       }
       if(base>=x){
        cout<<"0\n";
        continue;
       }
       if(maxw<=0){
        cout<<"-1\n";
        continue;
       }
       ll rem=x-base;
       ll ans=(rem+maxw-1)/maxw; // how many cycles of this best w are done
       cout<<ans<<'\n';

    }
    return 0;
}