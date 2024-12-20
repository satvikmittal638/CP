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
    vector<int> a(n);for(auto &i:a) cin>>i;
    sort(all(a));
    ll sum=0ll;
    int cnt=0;
    for(int i=0;i<n;i++){
        // person will be happy so serve him
        if(sum<=a[i]){
            cnt++;
            sum+=a[i];
        }
    }
    cout<<cnt;
    return 0;
}