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
       string s;cin>>s;
       vector<vector<int>> cnt;
       for(int i=0,j=k-1;i<=j;i++,j--){
        cnt.emplace_back(vector<int>(26,0));
        for(int pd=0;pd+k-1<n;pd+=k){
            cnt.back()[s[i+pd]-'a']++;
            if(i<j) cnt.back()[s[j+pd]-'a']++;
        }
       }
       int ans=0;
       for(auto chain:cnt){
        ans+=accumulate(all(chain),0)-*max_element(all(chain));
       }
       cout<<ans<<"\n";

    }
    return 0;
}