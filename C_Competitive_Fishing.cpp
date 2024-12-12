#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt;cin>>tt;
    while(tt--){
       int n,k;cin>>n>>k;
       string s;cin>>s;
       // double counting converts into a prefix/suffix problem
       reverse(s.begin(),s.end());
       vector<int> suf(n+1,0); // #1-#0 for each suffix
       for(int i=0;i<n;i++){
        suf[i+1]=suf[i]+(s[i]=='1')-(s[i]=='0');
       }
       /*
       overlapping region of any pair of suffix refers to the multiplication factor
       greedily pick the highest scored suffix until a score of atleast k is reached
       */
       sort(suf.rbegin()+1,suf.rend()-1); // (for rbegin+1)skip taking the whole array as 1 group(since it gives a score diff=0)
        int i=1;
        long long sum=0;
        while(i<=n && sum<k){
            sum+=suf[i++];
        }
        if(i<=n) cout<<i<<"\n";
        else cout<<"-1\n";
    }
    return 0;
}