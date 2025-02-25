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
       int mn=*min_element(all(a));
       int i;
       for(i=0;i<n;i++){
        if(a[i]==mn) break;
       }
       if(is_sorted(a.begin()+i,a.end())){
        cout<<i<<"\n";
       }
       else{
        cout<<"-1\n";
       }
    }
    return 0;
}