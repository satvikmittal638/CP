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
       vector<vector<int>> a(n);
       vector<map<int,int>> cnt(n);
       vector<int> mex(n,0),mex2(n,0);
       for(int i=0;i<n;i++){
         int l;cin>>l;
         a[i].assign(l,0);
         for(auto &j:a[i]) {
            cin>>j;
            cnt[i][j]++;
         }
         sort(all(a[i]));
         // compute mex
         for(int j=0;j<l;j++){
            if(a[i][j]==mex[i]) mex[i]++;
         }
         // compute the mex if we added an elt=mex to the array
         // assume we inserted mex
        mex2[i]=mex[i]+1;
        for(auto x:a[i]) {
            if(x==mex2[i]) mex2[i]++;
        }
       }
       map<int,int> gain; // gain[m] is gain for all arrays if mex[i] is inserted into any of them
       for(int i=0;i<n;i++){
           gain[mex[i]]+=mex2[i]-mex[i];
        }
        ll init=accumulate(all(mex),0ll),ans=0ll; // base ans
       // traverse all a[i][j] and get effects on all a[k]
       for(int i=0;i<n;i++){
        for(int j=0;j<a[i].size();j++){
            // assume that this elts movement has no effect
            // so there will be k=n-1 such arrays(exclude self)
            ll cur=init*(n-1);
            if(a[i][j]<mex[i] && cnt[i][a[i][j]]==1){
                // mex drops from mex[i] to a[i][j]
                cur-=(mex[i]-a[i][j])*(n-1);
            }
            cur+=gain[a[i][j]]; // add this elt to any array(including self, adding to self has no effect)
            ans+=cur;
        }
       }
       cout<<ans<<'\n';

    }
    return 0;
}