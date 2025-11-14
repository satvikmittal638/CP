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
       int n;cin>>n;
       vector<int> askFrom;
       for(int i=1;i<n;i++) askFrom.push_back(i);
       int pn=0,msb_pos=31-__builtin_clz(n);;
       // determine bit at position k
       for(int k=0;k<=msb_pos;k++){
        int b;
        int mask=(1<<k);
        vector<vector<int>> g(2,vector<int>());
        // partition the previous set of indices into 2 grps
        //g[0] has indices of elts having bit=0 at k given the previous constraints
        //g[1] has indices of elts having bit=1 at k given the previous constraints
        for(auto ind:askFrom){
            cout<<"? "<<ind<<" "<<mask<<endl;cin>>b;
            g[b].push_back(ind);
        }
        // cnt0 is no. of no.s from 1 to n which have same bit configuration at lowest k bits(0..k-1) as pn(which we have determined from previous iterations) but additionally have bit=0 at position k
        // same for cnt1

        ll M = 1LL << (k + 1); 
        // v0 is the value we're looking for (matches pn, 0 at bit k)
        ll v0 = pn; 
        // v1 is the other value (matches pn, 1 at bit k)
        ll v1 = pn | mask; 

        int cnt0, cnt1;

        // count numbers x in [1, n] such that x % M == v0
        if (v0 == 0) {
            // edge case:  M, 2M, 3M, ...
            cnt0 = n / M;
        } else {
            //  v0, v0 + M, v0 + 2M, ...
            // Only count if v0 is a valid number in the range
            cnt0 = (v0 <= n) ? ((n - v0) / M + 1) : 0;
        }

        // count numbers x in [1, n] such that x % M == v1
        // v1 is always >= 1 (since mask >= 1)
        cnt1 = (v1 <= n) ? ((n - v1) / M + 1) : 0;
        
       // k-th bit is 0
        if(g[0].size()<cnt0){
            askFrom=g[0];
        }
        // k-th bit is 1, set it in pn
        else{
            askFrom=g[1];
            pn|=mask;
        }
       }
       cout<<"! "<<pn<<endl;
    }
    return 0;
}