#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
       vector<int> a(n+1);
       for(int i=1;i<=n;i++) cin>>a[i];
       long long sum_e=0ll,sum_o=0ll;
       vector<long long> diff(n+1,0ll);
       map<long long,int> mp_diff; // for fast searching on difference array
       mp_diff[0]=0;
       for(int i=1;i<=n;i++){
        if(i%2==0) sum_e+=a[i];
        else sum_o+=a[i];
        long long x=sum_e-sum_o;
        diff[i]=x;
        mp_diff[x]=i; // to store largest index r s.t. the diff is x
       }
       bool found=0;
       for(int l=0;l<=n;l++){
        if(l<mp_diff[diff[l]]){
            found=1;break;
        }
       }
       cout<<(found?"YES":"NO")<<"\n";
    }
    return 0;
}