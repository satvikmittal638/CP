#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt;cin>>tt;
    while(tt--){
       int n,q;cin>>n>>q;
       vector<long long> p_sum(n),p_max(n);
       for(int i=0;i<n;i++){
        long long a;
        cin>>a;
        p_sum[i]=a+(i>0?p_sum[i-1]:0);
        p_max[i]=max(a,(i>0?p_max[i-1]:a));
       }
       while(q--){
        long long k;cin>>k;
        int i=upper_bound(p_max.begin(),p_max.end(),k)-1-p_max.begin();
        cout<<(i==-1?0:p_sum[i])<<" ";
       }
       cout<<"\n";
    }
    return 0;
}