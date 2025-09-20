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
       int n,s;cin>>n>>s;
       vector<int> a(n);for(auto &i:a) cin>>i;
       int tot=accumulate(all(a),0);
       int exc=s-tot;
       if(exc==0 || exc>1){
        cout<<"-1\n";
        continue;
       }
       else if(exc<0){
        for(auto e:a) cout<<e<<" ";
        cout<<"\n";
        }
        else{
        vector<int> cnt(3,0);
        for(auto e:a) cnt[e]++;
        for(int i=0;i<cnt[0];i++){
            cout<<0<<" ";
        }
        for(int i=0;i<cnt[2];i++){
            cout<<2<<" ";
        }
        for(int i=0;i<cnt[1];i++){
            cout<<1<<" ";
        }
        cout<<"\n";
        }
    }
    return 0;
}