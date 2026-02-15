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
       ll n,k;cin>>n>>k;
       vector<ll> stalls;
       bool ok=1;
       while(k>0){
        ll lo=1,hi=n,p=-1;
        while(lo<=hi){
            ll mid=(lo+hi)/2;
            // try to decrease p to buy more goods at once
            if((n/mid)<=k){
                p=mid;
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        if(p==-1){
            ok=0;
            break;
        }
        stalls.push_back(p);
        k-=n/p;
        n-=(n/p)*p;
       }
       if(ok){
        cout<<"YES\n";
        cout<<stalls.size()<<'\n';
        for(auto s:stalls) cout<<s<<' ';
       }
       else{
        cout<<"NO";
       }
       cout<<'\n';
    }
    return 0;
}