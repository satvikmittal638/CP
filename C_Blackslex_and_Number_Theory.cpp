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
       vector<int> a(n);for(auto &i:a) cin>>i;
       auto isPos=[](int k,vector<int> a){
        // all elts <k must be equal to the final value=remainder
        int r=-1;
        for(int i=0;i<a.size();i++){
            if(a[i]<k) {
                if(r==-1) r=a[i];
                else if(a[i]!=r){
                    return 0;
                }
            }
        }
        // now all a[i]-r must be >=k
        for(int i=0;i<a.size();i++){
            if(a[i]>r && a[i]-r<k){
                return 0;
            }
        }
        return 1;
       };
       int lo=*min_element(all(a)),hi=*max_element(all(a)),ans=-1;
       while(lo<=hi){
        int mid=(lo+hi)/2;
        if(isPos(mid,a)){
            ans=mid;
            lo=mid+1;
        }
        else{
            hi=mid-1;
        }
       }
    //    cout<<isPos(6,a);
       cout<<ans<<'\n';
    }
    return 0;
}