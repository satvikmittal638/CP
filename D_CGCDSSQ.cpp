#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
// for debugging
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << '\n';
	err(++it, args...);
}


const int K=20;
const int MAXN=1e5+1;
int log2_floor(unsigned long i) {
    return bit_width(i) - 1;
}
int st[K][MAXN]; // faster access
int main()
{
fastio;
    int n;cin>>n;
    vector<int> a(n);for(auto &i:a) cin>>i;
    copy(all(a),st[0]);
    for(int i=1;i<K;i++){
        for(int j=0;j+(1<<i)<=n;j++){
            st[i][j]=gcd(st[i-1][j],st[i-1][j+(1<<(i-1))]);
        }
    }
    // 0-indexed
    auto hcf=[&](int l,int r){
        int i=log2_floor(r-l+1);
        return gcd(st[i][l],st[i][r-(1<<i)+1]);
    };
    map<int,ll> mp;// gcd->no. of intervals
    int l=0;
    // O(nlognlog^2A)
    for(int l=0;l<n;l++){
        int curr=l;
        // O(log^2Alogn)
        while(curr<n){
            // BS smallest r>=l where the gcd drops
            // i.e. hcf(l,r)>hcf(l,r+1)
            int val=hcf(l,curr);
            int lo=curr,hi=n-1,bestr=curr;
            // O(logn)
            while(lo<hi){
                int mid=lo+(hi-lo)/2;
                if(hcf(l,mid)==val){
                    bestr = mid;
                    lo=mid+1;
                }
                else{
                    hi=mid-1;
                }
            }
            error(curr,bestr)
            // all subarrays starting at l and ending in [curr, bestr] 
            // have the same gcd equal to 'val'
            mp[val]+=bestr-curr+1;
            curr=bestr+1;// l=r+1 after the increment
        }
    }

    int q;cin>>q;
    while(q--){
        int x;cin>>x;
        if(mp.count(x)) cout<<mp[x]<<'\n';
        else cout<<"0\n";
    }
    return 0;
}