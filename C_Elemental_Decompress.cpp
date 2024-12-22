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
       vector<int> a(n),ctr(n+1,0);
       for(auto &i:a) {
        cin>>i;
        ctr[i]++;
       }
       vector<int> p(n,-1),q(n,-1);
       set<int> seenp,seenq;
       bool ok=1;
       for(int i=0;i<n;i++){
        if(ctr[a[i]]==1) {
            p[i]=q[i]=a[i];
            seenp.insert(a[i]);
            seenq.insert(a[i]);
        }
        else if(ctr[a[i]]==2){
            if(seenp.count(a[i])==0) {
                p[i]=a[i];
                seenp.insert(a[i]);
            }
            else if(seenq.count(a[i])==0) {
                q[i]=a[i];
                seenq.insert(a[i]);
            }
        }
        else{
            ok=0;break;
        }
       }
       // get all possible candidates which can be filled
       set<int> canFillP,canFillQ;
       for(int i=1;i<=n;i++){
        if(seenp.count(i)==0) canFillP.insert(i);
        if(seenq.count(i)==0) canFillQ.insert(i);
       }  
       // fill remaining places
       for(int i=0;i<n;i++){
        if(p[i]==-1){
            auto it=canFillP.lower_bound(a[i]);
            it--;
            p[i]=*it;
            canFillP.erase(p[i]);
        }
       }
       for(int i=0;i<n;i++){
        if(q[i]==-1){
            auto it=canFillQ.lower_bound(a[i]);
            it--;
            q[i]=*it;
            canFillQ.erase(q[i]);
        }
       }
       // if there an elt a[i]<i(1-indexed) no solution possible
        sort(a.begin(),a.end());
        for(int i=0;i<n;i++){
            if(a[i]<i+1){
                ok=0;break;
            }
        }

       if(ok){
        cout<<"YES\n";
        for(auto e:p) cout<<e<<" ";
        cout<<"\n";
        for(auto e:q) cout<<e<<" ";
        cout<<"\n";
       }else{
        cout<<"NO\n";
       }

    }
    return 0;
}