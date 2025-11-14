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
       set<int> S;// S is set of indices s.t. their MAD is 0
       S.insert(1);
       
       vector<int> ans(2*n+1,0);
       auto routine=[&](set<int>& S, int i){
        cout<<"? "<<S.size()+1<<" ";
        for(auto e:S){
            cout<<e<<" ";
        }
        cout<<i<<endl;
        int x;cin>>x;
        if(x==0) S.insert(i);
        else ans[i]=x;
       };
       for(int i=2;i<=2*n;i++){
        routine(S,i);
       }
       // Now S has n indices containing positions of all elts {1,..,n} 
       // find S complement
       set<int> Scomp;
       for(int i=1;i<=2*n;i++){
        if(S.count(i)==0) Scomp.insert(i);
       }
       for(int i=1;i<=2*n;i++){
        if(ans[i]==0){
            routine(Scomp,i);
        }
       }
       cout<<"! ";
       for(int i=1;i<=2*n;i++) cout<<ans[i]<<' ';
       cout<<endl;
    }
    return 0;
}