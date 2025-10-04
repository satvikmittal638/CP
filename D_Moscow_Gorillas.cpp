#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    ll n;cin>>n;
    vector<ll> p(n),q(n),inv_p(n+1,-1),inv_q(n+1,-1);
    for(ll i=0;i<n;i++) {
        cin>>p[i];
        inv_p[p[i]]=i;
    }
    for(ll i=0;i<n;i++) {
        cin>>q[i];
        inv_q[q[i]]=i;
    }    
    ll ans=0ll;
    
    ll lp,rp,lq,rq;
    lp=rp=inv_p[1];lq=rq=inv_q[1];
    ll mnPos=min(lp,lq),mxPos=max(lp,lq);
    // edge case:m=1
    ans+=mnPos*(mnPos+1)/2;//prefix
    ans+=(mxPos-mnPos-1)*(mxPos-mnPos)/2;//middle
    ans+=(n-mxPos-1)*(n-mxPos)/2;//suffix
    // cout<<ans<<' ';
    
    // iterate over the mexs
    for(ll m=2;m<=n;m++){
        // unite the llervals
        ll l=min(lp,lq),r=max(rp,rq);
        // [l,r] is smallest stretch where all elts 1..m-1 lie
        // check if m is present in p[l,r] or q[l,r]
        // if yes, then u can't choose any subarray
        if(l<=inv_p[m] && inv_p[m]<=r || l<=inv_q[m] && inv_q[m]<=r) {
            lp=min(lp,inv_p[m]);rp=max(rp,inv_p[m]);
            lq=min(lq,inv_q[m]);rq=max(rq,inv_q[m]);
            continue;
        }
        mnPos=min(inv_p[m],inv_q[m]),mxPos=max(inv_p[m],inv_q[m]);
        
        ll cntL,cntR;
        // [l,r] lies in a prefix
        if(r<mnPos){
            cntL=l+1; // 0..l
            cntR=mnPos-r; // r..mnPos-1
        }
        // [l,r] lies in a suffix
        else if(l>mxPos){
            cntL=l-mxPos;// mxPos+1...l
            cntR=n-r; // r..n-1
        }
        // [l,r] lies in the middle
        else{
            cntL= l-mnPos;//mnPos+1..l
            cntR= mxPos-r;// r..mxPos-1 
        }
        ans+=cntL*cntR;
        // cout<<m<<"-> "<<cntL<<" "<<cntR<<" "<<cntL*cntR<<"\n";
        // update the span for next value of m
        lp=min(lp,inv_p[m]);rp=max(rp,inv_p[m]);
        lq=min(lq,inv_q[m]);rq=max(rq,inv_q[m]);
    }
    ans++;// mex=n+1
    cout<<ans;
    return 0;
}