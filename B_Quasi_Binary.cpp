#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    int n;cin>>n;
    int mxDig=0;
    int tmp=n;
    while(tmp){
        mxDig=max(mxDig,tmp%10);
        tmp/=10;
    }
    vector<vector<bool>> ans(mxDig,vector<bool>(8,0));
    int pos=0;
    tmp=n;
    while(tmp){
        int dig=tmp%10;
        for(int i=0;i<dig;i++){
            ans[i][pos]=1;
        }
        tmp/=10;
        pos++;
    }
    cout<<ans.size()<<"\n";
    for(auto num:ans){
        int pos=0;
        reverse(all(num));
        while(num[pos]==0)pos++;// remove leading 0s
        for(;pos<8;pos++){
            cout<<num[pos];
        }
        cout<<" ";
    }
    return 0;
}