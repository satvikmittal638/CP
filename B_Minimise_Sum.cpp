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
       int a1,a2;
       for(int i=0;i<n;i++){
        int x;cin>>x;
        if(i==0) a1=x;
        if(i==1) a2=x;
       }
       cout<<a1+min(a1,a2)<<"\n";
    }
    return 0;
}