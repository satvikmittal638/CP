#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()

int main()
{
fastio;
    vector<ll> pw(50,1);
    for(int i=1;i<50;i++){
        pw[i] = pw[i-1]*3;
    }
    int tt;cin>>tt;
    while(tt--){
        ll n,k;cin>>n>>k;
        vector<ll> num(50);
        ll p=0;
        // express in ternary
       while(n){
        int d=n%3;
        num[p]=d;
        p++;
        n/=3;
       }
       k-=accumulate(all(num),0LL); // now excess operations remain
       if(k<0){
           cout << -1 << "\n";
           continue;
       }

       for(int i=49;i>=1;i--){
           if (k < 2) break;
           
           // find how many times we can transform in one step
           ll cnt_transforms = min(num[i], k / 2);

           if (cnt_transforms > 0) {
               // apply the transformations all at once
               num[i] -= cnt_transforms;
               num[i-1] += 3 * cnt_transforms;
               k -= 2 * cnt_transforms;
           }
       }

       ll res=0;
       for(int i=0;i<49;i++){
           if(num[i]>0){
               // cost(x) = 3^(i+1) + i*3^(i-1)
               ll cost = pw[i+1] + (i>0 ? (ll)i*pw[i-1] : 0);
               res += num[i]*cost;
           }
       }
       cout << res << "\n";
    }
    return 0;
}