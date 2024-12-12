#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
       vector<int> b(n+1);
       b[0]=1;
       for(int i=1;i<=n;i++) cin>>b[i];
       vector<int> a;
       a.emplace_back(b[1]);
       for(int i=1;i<n;i++){
        if(b[i]%b[i+1]==0){
            a.emplace_back(b[i+1]);
        }
       }
       if(a.size()==n){
        for(auto e:a) cout<<e<<" ";
       }else{
        cout<<-1;
       }
       cout<<"\n";
    }
    return 0;
}