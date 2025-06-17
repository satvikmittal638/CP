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
       vector<int> ans(n);
       int i=0,j=n-1,num=1;
       while(i<=j){
        ans[i]=num;
        if(i!=j)ans[j]=num+1;
        num+=2;
        i++;j--;
       }
       for(auto e:ans) cout<<e<<" ";
       cout<<"\n";
    }
    return 0;
}