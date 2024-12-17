#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;cin>>n>>k;
    vector<long long> pref(n+1,0);
    for(int i=1;i<=n;i++){
        int a;cin>>a;
        pref[i]=pref[i-1]+a;
    }
    long long sum=0ll;
    for(int i=k;i<=n;i++){
        sum+=pref[i]-pref[i-k];
    }
    double ans=(double)sum/(double)(n-k+1);
    cout<<fixed<<setprecision(6)<<ans;
    return 0;
}