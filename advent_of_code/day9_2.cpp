#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    ll a, b;
    char c; // to read comma
    vector<pair<ll,ll>> crds;
    while (cin >> a >> c >> b) {
        crds.emplace_back(a,b);
    }
    sort(all(crds));// first sort by rows,then by cols
    int n=crds.size();
    vector<ll> is,js;
    for(auto &[i,j]:crds){
        is.push_back(i);
        js.push_back(j);
    }
    // build pmax,smax,pmin,smin for js
    vector<ll> pmax(n),pmin(n),smax(n),smin(n);
    pmin[0]=pmax[0]=js[0];
    for(int i=1;i<n;i++){
        pmax[i]=max(pmax[i-1],js[i]);
        pmin[i]=min(pmin[i-1],js[i]);
    }
    smin[n-1]=smax[n-1]=js[n-1];
    for(int i=n-2;i>=0;i--){
        smax[i]=max(js[i],smax[i+1]);
        smin[i]=min(js[i],smin[i+1]);
    }

    for(int i=0;i<n;i++) cout<<is[i]<<','<<js[i]<<'\n';
    ll ans=0ll;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            auto &[i1,j1]=crds[i];
            auto &[i2,j2]=crds[j];
            //i1<=i2 is guaranteed by sorting

            if(j2>=j1){
                // check if there exists (i,j) s.t. i>=i2 && j<=j1(bottom left)
                // check if there exists (i,j) s.t. i<=i1 && j>=j2(top right)
                if(smin[j]<=j1 && pmax[i]>=j2) ans=max(ans,(i2-i1+1)*(j2-j1+1));
            }
            else{
                 // check if there exists (i,j) s.t. i>=i2 && j>=j1(bottom right)
                 // check if there exists (i,j) s.t. i<=i1 && j<=j2(top left)
                 if(smax[j]>=j1 && pmin[i]<=j2) ans=max(ans,(i2-i1+1)*(j1-j2+1));
            }
            cout<<ans<<' ';
        }
    }
    cout<<ans;
    return 0;
}