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
       if(is_sorted(all(a))){
        cout<<"NO\n";
        continue;
       }
       cout<<"YES\n2\n";
       for(int i=0;i<n-1;i++){
        if(a[i]>a[i+1]){
            cout<<a[i]<<" "<<a[i+1]<<"\n";
            break;
        }
       }
    }
    return 0;
}