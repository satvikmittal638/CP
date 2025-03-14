#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()


vector<vector<int>> dp;
string s;
int n;
int calc(int l,int r){
    int &res=dp[l][r];
    if(res!=-1) return res; // key memoization step
    if(l>r) return 0;
    if(l==r) return 1;

    res=1+calc(l+1,r);
    for(int i=l+1;i<=r;i++){
        if(s[l]==s[i]){
            // ! 2nd term will be (i,r) instead of (i+1,r) since we are not adding 1 explicitly here(since that single operation may involve
            // deleting some other chars as well)
            res=min(res,calc(l+1,i-1)+calc(i,r));
        }
    }
    return res;

}


int main()
{
    fastio;
    cin>>n>>s;
   dp.assign(n,vector<int>(n,-1));
    cout<<calc(0,n-1);
    return 0;
}