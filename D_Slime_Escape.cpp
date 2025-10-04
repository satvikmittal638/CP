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
       int n,k;cin>>n>>k;k--;
       vector<ll> a(n);for(auto &i:a) cin>>i;
       // edge case
       if(k==0 || k==n-1){
        cout<<"YES\n";
        continue;
       }
       int l=k-1,r=k+1;
       vector<pair<ll,ll>> g_l,g_r;//{sum,requirement}
       // sum is the net hp gain obtained by absorbing that grp
       // req is the minm possible hp(>=0) needed to absorb that grp
       // partition the left part into good grps(sum>=0)
       ll cur=0ll,req=0ll;
       while(l>=0){
        cur=0ll;req=0ll;//reset
        do{
            cur+=a[l];
            if(cur<0) req=max(req,abs(cur));
            l--;
        }while(l>=0 && cur<0);
        g_l.emplace_back(cur,req);
       }

        // partition the right part into good grps(sum>=0)
        while(r<n){
           cur=0ll,req=0ll;//reset
            do{
                cur+=a[r];
                if(cur<0) req=max(req,abs(cur));
                r++;
        }while(r<n && cur<0);
        g_r.emplace_back(cur,req);
       }

       // reverse g_l and g_r and use them as stacks 
       reverse(all(g_l));
       reverse(all(g_r));

       ll hp=a[k];
       while(hp>=0 && g_l.size() && g_r.size()){
        auto [gain_l,req_l]=g_l.back();
        auto [gain_r,req_r]=g_r.back();
        // can use only left grp
        if(hp>=req_l && hp<req_r){
            hp+=gain_l;
            g_l.pop_back();
        }
        // can use only right grp
        else if(hp>=req_r && hp<req_l){
            hp+=gain_r;
            g_r.pop_back();
        }
        // can use any grp, so use the one with maximum gain
        else if(hp>=max(req_l,req_r)){
            if(gain_l>=gain_r){
                hp+=gain_l;
                g_l.pop_back();
            }
            else{
                hp+=gain_r;
                g_r.pop_back();
            }
        }
        // no requirement is satisfied, so game ends
        else{
            break;
        }
       }
       // if any of g_l or g_r is empty, we can exit succesfully
       cout<<((g_l.empty() || g_r.empty())?"YES":"NO")<<'\n';


    }
    return 0;
}