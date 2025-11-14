#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
       map<ll,ll> cnt;
       vector<ll> a(n);for(auto &i:a) {cin>>i;cnt[i]++;}
       vector<ll> ans(3,0ll),odds;
       int sides=0;
       // case 1: take all pairs only
       for(auto &[k,v]:cnt){
        ans[0]+=(v-(v&1))*k;
        sides+=v-(v&1);
        if(v&1) odds.push_back(k);
       }
       ans[1]=ans[2]=ans[0];
       if(sides<3) ans[0]=0;
    //    cout<<ans[1]<<' ';
       // case 2: take all pairs and one more side(out of leftover)
       bool found=0;
       for(int i=odds.size()-1;i>=0;i--){
        if(odds[i]<ans[1]){
            ans[1]+=odds[i];
            sides++;
            found=1;
            break;
        }
       }
    //    cout<<ans[1]<<". ";
       if(sides<3) ans[1]=0;
       sides-=found;
       // case 3: take all pairs, and 2 more sides(out of leftover)
       for(int i=odds.size()-1;i>=1;i--){
        if(odds[i]<ans[2]+odds[i-1]) {
            ans[2]+=odds[i]+odds[i-1];
            sides+=2;
            break;
        }
       }
       if(sides<3) ans[2]=0;
       cout<<*max_element(all(ans))<<'\n';
    // cout<<ans[0]<<' '<<ans[1]<<' '<<ans[2]<<'\n';
    }
    return 0;
}