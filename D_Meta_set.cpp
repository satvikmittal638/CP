#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    int n,k;cin>>n>>k;
    vector<vector<int>> c(n,vector<int>(k));
    map<vector<int>,ll> cnt;
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            cin>>c[i][j];
        }
        cnt[c[i]]=0;
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            // calculate the unique card
            vector<int> calc(k);
            for(int z=0;z<k;z++){
                if(c[i][z]==c[j][z]) calc[z]=c[i][z];
                else calc[z]=c[i][z]^c[j][z]^1^2; // now the value at that feature is pairwise distinct
            }
            // if the calculated card exists in the deck
            if(cnt.count(calc)) cnt[calc]++;
        }
    }
    ll ans=0ll;
    for(auto &[card,f]:cnt){
        ans+=f*(f-1)/2;
    }
    cout<<ans;
    return 0;
}