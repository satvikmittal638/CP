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
       vector<int> a(n),cnt(101,0);for(auto &i:a) {cin>>i;cnt[i]++;}
       int mex=0;
       // find mex of original array
       for(int i=0;i<=100;i++){
        if(cnt[i]==0){
            mex=i;
            break;
        }
       }
       cout<<mex<<'\n';


    }
    return 0;
}