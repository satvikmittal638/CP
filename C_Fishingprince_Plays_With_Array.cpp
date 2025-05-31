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
       ll n,m;cin>>n>>m;
       vector<ll> a(n);for(auto &i:a) cin>>i;
       ll k;cin>>k;
       vector<ll> b(k);for(auto &i:b) cin>>i;
       
       // returns highest power of m in x
       // also reduces x to leftovers directly in the memory
       auto highPow=[&](ll &x){
        ll pow=0ll;
        while(x%m==0){
            pow++;
            x/=m;
        }
        return pow;
       };

       auto process=[&](vector<ll>& a){
        int sz=a.size();
        vector<ll> powe(sz);
        for(int i=0;i<sz;i++){
            powe[i]=highPow(a[i]);
            // cout<<powe[i]<<" ";
        }
        a.push_back(*a.rbegin());
        vector<pair<ll,ll>> cnt;
        for(int i=0;i<sz;i++){
            ll cur_cnt=0ll;
            while (i + 1 < sz && a[i] == a[i + 1]) {
                cur_cnt += pow(m,powe[i]);
                i++;
            }
            cur_cnt += pow(m,powe[i]); // Add the last one in the group
            cnt.push_back({a[i], cur_cnt});
        }
        return cnt;
       };
       
       auto pa=process(a),pb=process(b);
    //    for(auto e:a) cout<<e<<" ";
       cout<<(pa==pb?"Yes":"No")<<"\n";
    //    for(auto &[x,y]:pa) cout<<x<<" "<<y<<"  ";
    //    cout<<"\n";
    //    for(auto &[x,y]:pb) cout<<x<<" "<<y<<" ";

    }
    return 0;
}