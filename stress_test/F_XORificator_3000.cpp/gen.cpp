#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()

// 1. Setup the Random Number Generator
// random_device provides a non-deterministic seed (hardware based)
// mt19937 is a high-quality RNG
mt19937 rng(random_device{}());

// 2. Helper function: Random integer in range [min, max] inclusive
ll get_rand(ll min, ll max) {
    uniform_int_distribution<ll> dist(min, max);
    return dist(rng);
}



int main()
{
fastio;
    int t=1;
    cout<<t<<endl;
    while(t--){
        ll l=get_rand(1,20),r=get_rand(20,30),i=get_rand(0,5),k=get_rand(0,(1<<i)-1);
        cout<<l<<' '<<r<<' '<<i<<' '<<k<<endl;
    }
    return 0;
}