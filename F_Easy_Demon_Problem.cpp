#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,m,q,suma=0ll,sumb=0ll;cin>>n>>m>>q;
    // set<ll> a,b;
    vector<bool> has_a(2*n+1,0),has_b(2*m+1,0); // 2*m+1 to adjust for -ve numbers, i.e. -n is stored as 0 index
    for(int i=0;i<n;i++){
        int ai;cin>>ai;
        has_a[ai+n]=1;
        suma+=ai;
    }
    for(int i=0;i<m;i++){
        int bi;cin>>bi;
        has_b[bi+m]=1;
        sumb+=bi;
    }
    while(q--){
        bool found=0;
        auto check=[&](ll d1,ll d2){
            ll need_a=suma-d1+n;
            ll need_b=sumb-d2+m;
            if((0<=need_a && need_a<=2*n && has_a[need_a]) &&
                (0<=need_b && need_b<=2*m && has_b[need_b]))
                found=1;
        };
        ll x;cin>>x;
        // check all divisors of x(+ve -ve both)
        for(int d=1;d*d<=abs(x);d++){
            if(x%d==0){
                check(d,x/d);
                check(x/d,d);
                check(-d,-x/d);
                check(-x/d,-d);
            }
        }
        if(found) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}