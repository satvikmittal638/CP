#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()

ll gcd(ll a, ll b) {
    while (b) {
        ll t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main()
{
fastio;
    ll n,k;cin>>n>>k;
    vector<ll> nums(k);for(auto &i:nums) cin>>i;
    // count the no. of numbers which are cancelled
    // brute all subsets of nums
    ll cntBad=0ll;
    // ! Don't include empty set
    for(ll st=1;st<(1<<k);st++){
        ll bits=0,l=1ll;
        // find the intersection of all the elts in the set
        for(int i=0;i<k;i++){
            if(st&(1<<i)){
                l = l / gcd(l, nums[i]) * nums[i];
                bits++;
            }
        }
        if(bits%2==1) cntBad+=n/l;
        else cntBad-=n/l;
    }
    n-=cntBad;
    cout<<n;
    return 0;
}