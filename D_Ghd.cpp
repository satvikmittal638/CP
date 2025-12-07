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
    vector<ll> a(n);for(auto &i:a) cin>>i;
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> dist(0,n-1);
    // check if x is divisor of >=N/2 numbers
    auto check=[&](ll x){
        int cnt=0;
        for(auto e:a) cnt+=e%x==0;
        return cnt>=(n+1)/2;
    };
    ll ans=1ll;
    //O(nrootA)~O(1e12)
    // P(fail)=(0.5)^30
    for(int _=1;_<=20;_++){
        int idx=dist(rng);// pick a random elt
        vector<ll> divs;
        for(ll j=1;j*j<=a[idx];j++){
            if(a[idx]%j==0){
                divs.emplace_back(j);
                if(a[idx]!=j*j) divs.emplace_back(a[idx]/j);
            }
        }
        sort(all(divs));
        // by performing the transformation a[i]->gcd(a[i],a[idx]), we have atmost d(a[idx]) distinct values in the transformed array(d(N)<=6720 for N<=1e12) 
        // hence we can compress the array and then brute force count the no. of no's divisible by a divisor of a[idx]
        // using map for compression gives TLE
        vector<ll> cnt(divs.size(),0ll);
        for(auto e:a){
            ll g=gcd(e,a[idx]);
            int id=lower_bound(all(divs),g)-divs.begin();
            cnt[id]++;
        }
        for(int i=divs.size()-1;i>=0;i--){
            if(divs[i]<=ans) break;// better ans found already
            ll total=0ll;
            for(int j=i;j<divs.size();j++){
                if(divs[j]%divs[i]==0){
                    total+=cnt[j];
                }
            }
            if(2*total>=n) ans=max(ans,divs[i]);
        }

    }
    cout<<ans;

    return 0;
}