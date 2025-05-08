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
       string s,subset;cin>>s;
       vector<int> subs;
       // find the lexicographically largest subset of s
       vector<char> s_mx(n,0);
       s_mx[n-1]=s[n-1];
       for(int i=n-2;i>=0;i--){
        s_mx[i]=max(s[i],s_mx[i+1]);
       }
       for(int i=0;i<n;i++){
        if(s[i]==s_mx[i]) {
            subset.push_back(s[i]);
            subs.push_back(i);
        }
       }
       int l=0,r=subs.size()-1;
       while(l<r){
        swap(s[subs[l]],s[subs[r]]);
        l++;
        r--;
       }
       
       int i=0;
       while(i<subset.size()-1 && subset[i]==subset[i+1])i++;
       int ans=subset.size()-(i+1);
       if(!is_sorted(all(s))) ans=-1;
       cout<<ans<<"\n";
    }
    return 0;
}