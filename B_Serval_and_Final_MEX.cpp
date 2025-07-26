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
       vector<int> a(n);for(auto &i:a) cin>>i;
       int st=-1,end=-1;
       for(int i=0;i<n;i++){
        if(a[i]==0 && st==-1) st=i+1;
        if(a[i]==0) end=i+1;
       }
       vector<int> l,r;
       // single 0
       if(st!=-1 && end!=-1){
           if(st==end){
            if(st==1){
                l.push_back(st);r.push_back(st+1);
    
            }else{
                l.push_back(st-1);r.push_back(st);
            }
            n--;
           }
           // 0s at bdries
           else if(st==1 && end==n){
            l.push_back(st);r.push_back(end-2);
            l.push_back(2);r.push_back(3);
            n=2;
           }
           else if(st>0 && end>0){
            l.push_back(st);r.push_back(end);
            n-=end-st;
           }
       }
       l.push_back(1);r.push_back(n);

       cout<<l.size()<<"\n";
       for(int i=0;i<l.size();i++){
        cout<<l[i]<<" "<<r[i]<<"\n";
       }
    }
    return 0;
}