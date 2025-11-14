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
       vector<int> a(n);for(auto &i:a) cin>>i;
       /*
       Only 3 ans are possible 0,1,2
       fix L(0) or R(1) for the i=1 and check if valid sequence can be built
       */
      int ans=0;
      // input the configuration of a[0]
      auto build=[&](int st){
          string seq;
          seq+='0'+st;
          for(int i=1;i<n;i++){
            if(a[i]!=a[i-1]) seq.push_back(seq.back());// keep same
            else seq.push_back(!(seq.back()-'0')+'0');// alternate
          }
          return seq;
      };
      // checks if a seqn is valid based on a 
      auto check=[&](string s){
        int tot_r=count(all(s),'1');
        int cur_l=0,cur_r=0;
        for(int i=0;i<n;i++){
            int cur=cur_l+(tot_r-(s[i]=='1')-cur_r)+1;
            if(cur!=a[i]) return 0;
            cur_l+=s[i]=='0';
            cur_r+=s[i]=='1';
        }
        return 1;
      };

    //   cout<<build(0)<<"  "<<check(build(0))<<'\n';
    //   cout<<build(1)<<"  "<<check(build(1))<<"\n\n";
      cout<<(check(build(0))+check(build(1)))<<'\n';

    }
    return 0;
}