#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    int n;cin>>n;
    vector<double> a(n);
    vector<int> ans(n);
    ll sum=0ll;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=floor(a[i]);
    }
    // cout<<sum<<"\n\n";
    for(int i=0;i<n;i++){
        // no. is not integral, so round it up to make the sum=0
        if(floor(a[i])!=a[i] && sum!=0){
            sum++;
            ans[i]=ceil(a[i]);
        }
        else{
            ans[i]=floor(a[i]);
        }
    }
    for(auto e:ans)cout<<e<<"\n";
   
    return 0;
}