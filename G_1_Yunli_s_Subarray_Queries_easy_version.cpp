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
       int n,k,q;cin>>n>>k>>q;
       vector<int> a(n);
       for(int i=0;i<n;i++){
        cin>>a[i];
        a[i]-=i;
       }
       vector<int> ans,cnt(2*n+1,0);
       multiset<int> ms;
       // initialize multiset with all zero frequencies
       for(int i=0;i<=2*n;i++){
           ms.insert(0);
       }
       for(int r=0;r<n;r++){
        if(r>=k){
            // remove a[r-k] from window
            ms.erase(ms.find(cnt[a[r-k]+n]));
            cnt[a[r-k]+n]--;
            ms.insert(cnt[a[r-k]+n]);
        }
        // add to current window
        ms.erase(ms.find(cnt[n+a[r]]));
        cnt[n+a[r]]++; // a[r] stored as n+a[r]
        ms.insert(cnt[n+a[r]]);

        if(r>=k-1) ans.emplace_back(k-*ms.rbegin());
       }
       while(q--){
        int l,r;cin>>l>>r;l--;r--;
        cout<<ans[l]<<'\n';
       }
    }
    return 0;
}