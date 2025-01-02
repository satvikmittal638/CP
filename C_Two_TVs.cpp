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
    vector<pair<int,int>> pts;
    for(int i=0;i<n;i++){
        int l,r;cin>>l>>r;
        r++;
        pts.emplace_back(l,1);
        pts.emplace_back(r,-1);
    }
    sort(all(pts));
    int maxTV=0,curTV=0;
    for(int i=0;i<2*n;i++){
        curTV+=pts[i].second;
        maxTV=max(maxTV,curTV);
    }
    cout<<(maxTV<=2?"YES":"NO");
    return 0;
}