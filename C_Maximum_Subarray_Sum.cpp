#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()

ll kadane(const vector<ll>& arr) {
    ll maxSoFar = arr[0];
    ll maxEndingHere = arr[0];

    for (size_t i = 1; i < arr.size(); ++i) {
        maxEndingHere = max(arr[i], maxEndingHere + arr[i]);
        maxSoFar = max(maxSoFar, maxEndingHere);
    }

    return maxSoFar;
}

int main()
{
fastio;
    const ll INF=1e13;
    ll tt;cin>>tt;
    while(tt--){
       ll n,k;cin>>n>>k;
       string s;cin>>s;
       vector<ll> a(n);for(auto &i:a) cin>>i;
       ll pos=0;
       // find location of 1st 0
       while(pos<n && s[pos]=='1') {
           pos++;
        }
        ll s1=0ll,s2=0ll,mxS1=0,mxS2=0;
        // get maxm suffix sum for 0,..,pos-1
       for(int i=pos-1;i>=0;i--){
        s1+=a[i];
        mxS1=max(mxS1,s1);
       }
       for(int i=0;i<n;i++){
        if(s[i]=='0') a[i]=-INF;
       }
       // get maxm prefix sum for pos+1,..,n-1
       for(int i=pos+1;i<n;i++){
        s2+=a[i];
        mxS2=max(mxS2,s2);
       }
       if(pos<n) a[pos]=k-mxS1-mxS2;
       ll mxSum=kadane(a);
       if(mxSum==k){
        cout<<"Yes\n";
        for(auto e:a)cout<<e<<" ";
        cout<<"\n";
        }
        else{
            cout<<"No\n";
        }
    // cout<<mxSum<<"  ";

    }
    return 0;
}