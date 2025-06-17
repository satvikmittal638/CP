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
       vector<int> a(n),cnt(n+1,0);
       set<int> uniq;
       for(int i=0;i<n;i++){
        cin>>a[i];
        uniq.insert(a[i]);
        cnt[a[i]]++;
       }
       int r=n-1,ans=0;
       while(r>=0){
        ans++;// start a segment
        // keep going to left until no. of distinct elts in [1,r] = [l,r]
        int cnt_dist=uniq.size();
        int l=r;
        set<int> cnt_cur;
        while(l>=0 && cnt_cur.size()<cnt_dist){
            cnt[a[l]]--;
            cnt_cur.insert(a[l]);
            if(cnt[a[l]]==0) uniq.erase(a[l]);
            if(cnt_cur.size()<cnt_dist) l--;
        }
        // cout<<l<<" "<<r<<"  ";
        r=l-1;
       }
       cout<<ans<<"\n";
    }
    return 0;
}