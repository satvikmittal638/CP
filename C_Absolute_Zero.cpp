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
       vector<int> a(n);
       for(auto &i:a) cin>>i;
       int foundE=0,foundO=0;
       for(auto e:a){
        foundE|=(e%2==0);
        foundO|=(e%2!=0);
       }
       if(foundO && foundE){
        cout<<"-1\n";
        continue;
       }
       vector<int> x;
       for(int i=29;i>=0;i--){
        x.push_back(1<<i);
        for(auto &e:a){
            e=abs(e-(1<<i));
        }
       }
       if(a[0]==1){
        x.push_back(1);
       }
       cout<<x.size()<<"\n";
       for(auto e:x) cout<<e<<" ";
       cout<<"\n";

       
    }
    return 0;
}