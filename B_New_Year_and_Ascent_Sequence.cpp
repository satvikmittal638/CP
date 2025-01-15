#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
// TODO:implement
int main()
{
fastio;
    int n;cin>>n;
    int cnt_Desc=0;
    vector<pair<int,int>> nonDescSeq;
    int tmpn=n;
    while(tmpn--){
        int l;cin>>l;
        int minm=INT_MAX,maxm=INT_MIN,prevS=INT_MAX;
        bool isDesc=1;
        if(l==1) isDesc=0;
        while(l--){
            int s;cin>>s;
            minm=min(minm,s);
            maxm=max(maxm,s);
            isDesc&=(s<=prevS);
            prevS=s;
        }
        if(isDesc){
            cnt_Desc++;
        }else{
            nonDescSeq.push_back(make_pair(minm,maxm));
        }
    }
    ll ans=0ll;
    ans+=cnt_Desc*n*1ll;

    return 0;
}