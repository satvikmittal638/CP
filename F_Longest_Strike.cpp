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
       int n,k;cin>>n>>k;
       map<int,int> mp;
       for(int i=0;i<n;i++){
        int a;cin>>a;
        mp[a]++;
       }
       vector<int> a; // store all good elements
       for(auto p:mp){
        if(p.second>=k) a.emplace_back(p.first);
       }

        if(a.size()==0){
            cout<<"-1\n";
            continue;
        }

       int lans=a[0],rans=a[0],mxWin=0,l=a[0];
       for(int i=1;i<a.size();i++){
        if(a[i]-a[i-1]==1){
            if(a[i]-l>mxWin){
                lans=l;
                rans=a[i];
                mxWin=rans-lans;
            }
        }
        // break the array if non-consecutive elements found
        else{
            l=a[i];
        }
       }
       cout<<lans<<" "<<rans<<"\n";
    }
    return 0;
}