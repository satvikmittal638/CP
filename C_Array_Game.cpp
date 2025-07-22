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
       ll n,k;cin>>n>>k;
       vector<ll> a(n);for(auto &i:a) cin>>i;
       if(k>=3){
        cout<<"0\n";
        continue;
       }
       sort(all(a));
       ll mn=LLONG_MAX;
       for(int i=0;i<n-1;i++){
        mn=min(mn,a[i+1]-a[i]);
       }
       if(k==1){
        cout<<mn<<"\n";
        continue;
       }
       //brute 1st opn
       for(int i=0;i<n;i++) for(int j=0;j<i;j++)
       {
            int v=a[i]-a[j];
            int p=lower_bound(all(a),v)-a.begin();
            if(p<n) mn=min(mn,a[p]-v);
            if(p>0) mn=min(mn,v-a[p-1]);
        }
       
       cout<<mn<<"\n";
    }
    return 0;
}