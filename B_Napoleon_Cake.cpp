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
       vector<int> wetted(n+2,0);
       for(int i=1;i<=n;i++){
        int x;cin>>x;
        x=min(i,x);
        wetted[i-x+1]++;
        wetted[i+1]--;
       }
       partial_sum(all(wetted),wetted.begin());
       for(int i=1;i<=n;i++){
        cout<<(wetted[i]>0)<<" ";
       }
       cout<<"\n";
    }
    return 0;
}