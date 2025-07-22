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
    vector<tuple<int,int,int>> itvls;
    for(int i=0;i<n;i++){
        int l,r;cin>>l>>r;
        itvls.emplace_back(l,r,i);
    }
    sort(all(itvls), [](auto &a, auto &b) {
        if (get<0>(a) != get<0>(b)) return get<0>(a) < get<0>(b);
        return get<1>(a) > get<1>(b);
    });
    vector<pair<int,int>> suf_min(n);// suf_min[i] gets interval idx with minm r value in range [i+1,n]
    suf_min[n-1]={INT_MAX,-1};
    for(int i=n-2;i>=0;i--){
        int r=get<1>(itvls[i+1]),ind=get<2>(itvls[i+1]);
        suf_min[i]=suf_min[i+1];
        if(r<suf_min[i].first){
            suf_min[i]={r,ind};
        }
    }
    int ians=-2,jans=-2;
    for(int i=0;i<n-1;i++){
        int r = get<1>(itvls[i]);
        int idx_j = get<2>(itvls[i]);
        int min_r = suf_min[i].first;
        int idx_i = suf_min[i].second;

        if(min_r <= r){
            ians = idx_i; // this is smaller interval
            jans = idx_j; // this is larger interval
            break;
        }
    }
    cout<<ians+1<<" "<<jans+1;
    return 0;
}