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
    vector<pair<int,int>> a(n);
    for(auto &i:a) cin>>i.first>>i.second;
    sort(all(a));
    int cur=min(a[0].first,a[0].second);
    for(int i=1;i<n;i++){
        int mn=min(a[i].first,a[i].second);
        int mx=max(a[i].first,a[i].second);
        if(cur<=mn){
            cur=mn;
        }else{
            cur=mx;
        }
    }
    cout<<cur;
    return 0;
}