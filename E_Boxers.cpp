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
    map<int,int> f;
    int mx=-1;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        mx=max(mx,x);
        f[x]++;
    }
    // check for each value on the number line, if it can be obtained
    int ans=0;
    for(int i=1;i<=12;i++){
        int oldans=ans;
        if(f[i]>0) ans++;
        else if(f[i-1]>1 || f[i+1]>1) ans++;
        if(ans>oldans) cout<<i<<"Y ";
        else cout<<i<<"N ";
    }
    // cout<<ans;

    return 0;
}