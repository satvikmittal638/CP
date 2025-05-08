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
       int n,x;cin>>n>>x;
       vector<int> a(n);for(auto &i:a) cin>>i;
       sort(rall(a));
       int cnt=0;
       for(int i=0;i<n;i++){
        // form the smallest team size now
        int st=i;
        while(i<n && a[i]*(i-st+1)<x){
            i++;
        }
        if(i<n) cnt++;
       }
       cout<<cnt<<"\n";
    }
    return 0;
}