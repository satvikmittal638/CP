#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    int c;cin>>c;
    vector<int> v(c);for(auto &i:v) cin>>i;
    int cur=0,mxPref=0;
    for(int i=0;i<c;i++){
        cur+=v[i];
        mxPref=max(mxPref,cur);
    }
    cout<<(100+mxPref);
    return 0;
}