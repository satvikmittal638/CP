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
       ll n,k;cin>>n>>k;
       string a,b;cin>>a>>b;
       // count no. of unique chars in a that should be modified
       vector<int> cnt(26,0);
       for(int i=0;i<n;i++){
        cnt[a[i]-'a']+=cnt[a[i]-'a']==0 && a[i]!=b[i];
       }
       ll u=accumulate(all(cnt),0ll);
       // a=b can be done
       if(k>=u){
        cout<<n*(n+1)/2<<"\n";
        continue;
       }
       vector<char> uniqChars;
       for(int i=0;i<26;i++){
        if(cnt[i]>0) uniqChars.push_back('a'+i);
       }
       // OW choose a k element subset out of u chars.Brute all subsets
       // Use bitmask to select a subset of 'uniqChars'
       ll ans=0ll;
       for(int st=0;st<(1<<u);st++){
        if(__builtin_popcount(st)==k){
            // process a subset and modify string a
            string tmpa=a;
            for(int i=0;i<u;i++){
                if(st&(1<<i)){
                    char c=uniqChars[i];
                    // cout<<c;
                    for(int i=0;i<n;i++){  
                        if(a[i]==c) tmpa[i]=b[i];
                    }
                }
            }
            // compute the ans now
            ll cur=0ll,sz=0ll;
            for(int i=0;i<n;i++){
                if(tmpa[i]==b[i]){
                    sz++;
                }
                else{
                    cur+=sz*(sz+1)/2;
                    sz=0ll; // reset for nxt segment
                }
            }
            cur+=sz*(sz+1)/2; // handle last segment
            // update the ans
            ans=max(ans,cur);
        }
       }

       cout<<ans<<"\n";
    }
    return 0;
}